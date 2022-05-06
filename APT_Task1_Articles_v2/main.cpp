#include "stdio.h"
#include "stdlib.h"

struct TitleNode
{
    int aTitleKey;
    int titlesCount;
    char aTitleString[201];
    TitleNode* next;
};

struct CommentsNode
{
    int aCommentKey;
    int commentsCount;
    char aCommentString[30];
    CommentsNode* next;
    CommentsNode* prev;
};

void remTitleNode(TitleNode*&node)
{
    while (node!=NULL)
    {
        TitleNode *p = node->next;
        delete node;
        node = p;
    }
}

void remCommentNode(CommentsNode*&node)
{
    while (node!=NULL)
    {
        CommentsNode *p = node->next;
        delete node;
        node = p;
    }
}


void printTitleList(TitleNode* node)
{
    while (node != NULL)
    {
        fprintf(stdout, "%d %s\n", node->aTitleKey, node->aTitleString);
        node = node->next;
    }
}

void printCommentList(CommentsNode* node)
{
    while (node != NULL)
    {
        fprintf(stdout, "%d %s\n", node->aCommentKey, node->aCommentString);
        node = node->next;
    }
}

TitleNode* SortedMerge(TitleNode* a, TitleNode* b);
void FrontBackSplit(TitleNode* source,
                    TitleNode** frontRef, TitleNode** backRef);

void MergeSort(TitleNode** headRef)
{
	TitleNode* head = *headRef;
	TitleNode* a;
	TitleNode* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}

TitleNode* SortedMerge(TitleNode* a, TitleNode* b)
{
	TitleNode* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->aTitleKey <= b->aTitleKey) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void FrontBackSplit(TitleNode* source,
					TitleNode** frontRef, TitleNode** backRef)
{
	TitleNode* fast;
	TitleNode* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

int main(void)
{
	FILE* inFile;
	FILE* outFile;

	int aKey;
	char aString[203];
	int titleCounter = 0;
	int commentCount = 0;

	TitleNode* title = new TitleNode();
	TitleNode* firstTitle = NULL;
	TitleNode* lastTitle = NULL;

	CommentsNode* comment = new CommentsNode();
	CommentsNode* firstComment = NULL;
	CommentsNode* lastComment = NULL;

    inFile = fopen("articles.in", "r");

    if (inFile == NULL){
        printf("Unable to open the file\n");
    } else {
        while(fscanf(inFile, "%[^\n]", aString) != EOF)
            {
            fscanf(inFile, "%d %[^\n]s", &aKey, aString);
            if (aString[0] == '\"')
            {
                if (title->aTitleKey == 0)
                {
                    title->aTitleKey = aKey;
                    title->titlesCount = ++titleCounter;
                    for (int i = 1; i < sizeof(aString); ++i)
                    {
                        if (aString[i] == '\"')
                            break;
                        title->aTitleString[i-1] = aString[i];
                    }
                    title->next = nullptr;
                    firstTitle = title;
                    lastTitle = title;
                }
                else
                {
                    title = new TitleNode();
                    title->titlesCount = ++titleCounter;
                    title->aTitleKey = aKey;

                    for (int i = 1; i < sizeof(aString); ++i)
                    {
                        if (aString[i] == '\"')
                            break;
                        title->aTitleString[i-1] = aString[i];
                    }
                    title->next = nullptr;
                    lastTitle->next = title;
                    lastTitle = title;
                }
            }
            else
            {
                if (aKey == 0) break;
                if (comment->aCommentKey == 0)
                {
                    comment->aCommentKey = aKey;
                    comment->commentsCount = ++commentCount;
                    for (int i = 0; i < sizeof(aString); ++i)
                    {
                        if (aString[i] == 0)
                            break;
                        else
                            comment->aCommentString[i] = aString[i];
                    }
                    comment->next = nullptr;
                    comment->prev = nullptr;
                    firstComment = comment;
                    lastComment = comment;
                }
                else
                {
                    comment = new CommentsNode();
                    comment->commentsCount = ++commentCount;
                    comment->aCommentKey = aKey;

                    for (int i = 0; i < sizeof(aString); ++i)
                    {
                        if (aString[i] == 0)
                            break;
                        else
                            comment->aCommentString[i] = aString[i];
                    }
                    comment->next = nullptr;
                    comment->prev = lastComment;
                    lastComment->next = comment;
                    lastComment = comment;
                }
                aKey = 0;
            }
        }
        fclose(inFile);

        outFile = fopen("articles.out", "w+");

        if (outFile == NULL)
        {
            printf("Unable to open the file\n");
        } else {
            MergeSort(&firstTitle);
            title = firstTitle;
            comment = lastComment;
            for (int i = 0; i < lastTitle->titlesCount; ++i)
            {
                int commentsWrittenToFile = 0;
                fprintf(stdout, "%s\n", title->aTitleString);
                fprintf(outFile, "%s\n", title->aTitleString);
                for (int j = lastComment->commentsCount; j > 0; --j)
                {
                    if (title->aTitleKey == comment->aCommentKey)
                    {
                        fprintf(stdout, "%s ", comment->aCommentString);
                        fprintf(outFile, "%s ", comment->aCommentString);
                        ++commentsWrittenToFile;
                    }
                    comment = comment->prev;
                }
                if (commentsWrittenToFile < 1)
                    fprintf(outFile, "-");
                fprintf(outFile, "\n");
                fprintf(stdout, "\n");
                title = title->next;
                comment = lastComment;
            }
            fclose(outFile);
        }
        printTitleList(firstTitle);
        printCommentList(firstComment);
        remTitleNode(firstTitle);
        remCommentNode(firstComment);
    }
	return 0;
}

