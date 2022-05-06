#include <iostream>

using namespace std;

struct elem {
    int num;
    elem *next;
};

int main()
{

    int nums[] = {1, 8, 4, 6, 5};
    elem *first = NULL;
    elem *last;
    for (int i = 0; i < 5; ++i)
    {
        elem *p = new elem;
        p->num = nums[i];
        p->next = NULL;
        if (first==NULL)
            first=last=p;
        else
        {
            last->next=p;
            last = p;
        }
    }

    // print
    elem *p = first;
    while (p!=NULL){
        cout << p->num<<" ";
        p = p->next;
    }
    cout << endl;

    // delete
    while(first){
        p = first->next;
        delete first;
        first = p;
    }

    return 0;
}
