/**********************************************************************************
  sorttask1 - program to test performance of sorting a sequence of objects
**********************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
int c1;
int cc;
int as;
int dd;
int ccx;
int asx;
struct sint
{
    int *data;
    sint() {
        data = new int;
        *data=rand();
        ++c1;
    }
    sint(const sint &s) {
        ++cc;
        data = new int;
        *data=*(s.data);
    }
    sint& operator=(const sint &s) {
        ++as;
        delete data;
        data = new int;
        *data=*(s.data);
        return *this;
    }
    ~sint() {
        ++dd;
        delete data;
    }
};
struct sintplus
{
    int *data;
    sintplus() {
        data = new int;
        *data=rand();
        ++c1;
    }
    sintplus(const sintplus &s) {
        ++cc;
        data = new int;
        *data=*(s.data);
    }
    sintplus(sintplus &&s) {
        ++ccx;
        data = s.data;
        s.data = nullptr;
    }
    sintplus& operator=(const sintplus &s) {
        ++as;
        delete data;
        data = new int;
        *data=*(s.data);
        return *this;
    }
    sintplus& operator=(sintplus &&s) {
        ++asx;
        if (this != &s)
        {
            delete data;
            data = s.data;
            s.data = nullptr;
        }
        return *this;
    }
    ~sintplus() {
        ++dd;
        delete data;
    }
};
bool less_sint(const sint &a, const sint &b) {
    return *(a.data) < *(b.data);
}
bool less_sintplus(const sintplus &a, const sintplus &b) {
    return *(a.data) < *(b.data);
}
bool less_sint_p(const sint *a, const sint *b) {
    return *(a->data) < *(b->data);
}
int main() {
    int N = 1000000;
    time_t timer1, timer2;
    cout<<"TASK1: SORTING VECTOR OF OBJECTS"<<endl<<endl;
    c1 = 0;
    cc = 0;
    as = 0;
    dd = 0;
    srand (time(NULL));
    vector<sint> datastruct(N);
    timer1 = time(NULL);
    sort(datastruct.begin(),datastruct.end(),less_sint);
    timer2 = time(NULL);
    cout<<"default constructor: "<<c1<<endl;
    cout<<"copy constructor: "<<cc<<endl;
    cout<<"assignment operator: "<<as<<endl;
    cout<<"destructor: "<<dd<<endl;
    cout<<"time: "<<timer2-timer1<<endl;

    cout<<endl<<"TASK2: SORTING VECTOR OF POINTERS TO OBJECTS"<<endl<<endl;
    c1 = 0;
    cc = 0;
    as = 0;
    dd = 0;
    srand (time(NULL));
    vector<sint*> datastructp(N);
    for (int i=0;i<datastructp.size();++i)
    {
        datastructp[i] = new sint();
    }
    timer1 = time(NULL);
    sort(datastructp.begin(),datastructp.end(),less_sint_p);
    timer2 = time(NULL);
    for (int i=0;i<datastructp.size();++i)
    {
        delete datastructp[i];
    }
    cout<<"default constructor: "<<c1<<endl;
    cout<<"copy constructor: "<<cc<<endl;
    cout<<"assignment operator: "<<as<<endl;
    cout<<"destructor: "<<dd<<endl;
    cout<<"time: "<<timer2-timer1<<endl;

    cout<<endl<<"TASK3: SORTING VECTOR OF OBJECTS USING MOVE FUNCTIONALITY"<<endl<<endl;
    c1 = 0;
    cc = 0;
    as = 0;
    ccx = 0;
    asx = 0;
    dd = 0;
    srand (time(NULL));
    vector<sintplus> datastructplus(N);
    timer1 = time(NULL);
    sort(datastructplus.begin(),datastructplus.end(),less_sintplus);
    timer2 = time(NULL);
    cout<<"default constructor: "<<c1<<endl;
    cout<<"copy constructor: "<<cc<<endl;
    cout<<"copy constructor move: "<<ccx<<endl;
    cout<<"assignment operator: "<<as<<endl;
    cout<<"assignment operator move: "<<asx<<endl;
    cout<<"destructor: "<<dd<<endl;
    cout<<"time: "<<timer2-timer1<<endl;
}
