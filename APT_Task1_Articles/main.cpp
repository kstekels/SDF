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
};

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

int main(void)
{
	FILE* inFile;
	FILE* outFile;

	int aKey;
	char aString[203];
	int titleCounter = 0;
	int commentCount = 0;

    // Titles Linked List
	TitleNode* title = new TitleNode();
	TitleNode* firstTitle = NULL;
	TitleNode* lastTitle = NULL;

    // Comments Linked List
	CommentsNode* comment = new CommentsNode();
	CommentsNode* firstComment = NULL;
	CommentsNode* lastComment = NULL;

    inFile = fopen("articles.in", "r");

    if (inFile == NULL){
        printf("Unable to open the file\n");
    } else {
        while(fscanf(inFile, "%[^\n]", aString) != EOF){
            fscanf(inFile, "%d %[^\n]s", &aKey, aString);
            // If string starts with '\"', then it will save it to the title
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
            title = firstTitle;
            comment = firstComment;
            for (int i = 0; i < lastTitle->titlesCount; ++i)
            {
                int commentsWrittenToFile = 0;
                fprintf(stdout, "%s\n", title->aTitleString);
                fprintf(outFile, "%s\n", title->aTitleString);
                for (int j = 0; j < lastComment->commentsCount; ++j)
                {
                    if (title->aTitleKey == comment->aCommentKey)
                    {
                        fprintf(stdout, "%s ", comment->aCommentString);
                        fprintf(outFile, "%s ", comment->aCommentString);
                        ++commentsWrittenToFile;
                    }
                    comment = comment->next;
                }
                if (commentsWrittenToFile < 1)
                    fprintf(outFile, "-");
                fprintf(outFile, "\n");
                fprintf(stdout, "\n");
                title = title->next;
                comment = firstComment;
            }
            fclose(outFile);
        }
        printTitleList(firstTitle);
        printCommentList(firstComment);
    }


	return 0;
}

