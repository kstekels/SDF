#include<iostream>
using namespace std;

void print(int array[],int n) {
    for (int i=0;i<n;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void print_conf(int data[],int conf[],int n) {
    cout<<"[ ";
    for (int i=0;i<n;++i) {
        if (conf[i])
            cout<<data[i]<<" ";
    }
    cout<<"]"<<endl;
}

bool next_conf(int conf[],int n) {
    for (int pos=n-1;pos>=0;--pos) {
        if (conf[pos]==0) {
            conf[pos]++;
            for(int i=pos+1;i<n;++i) conf[i]=0;
            return true;
        }
    }
    return false;
}

int main()
{
    const unsigned n = 3;
    int data[n] = {0,1,2};
    int conf[n] = {0,0,0};
    print(data, n); // 0 1 2
    print_conf(data,conf,n); // [ ]

    int counter = 1;
    while (next_conf(conf, n))
    {
        print_conf(data, conf, n);
        ++counter;
    }
    cout << "n=" << n << endl;
    cout << counter << "=2^n" << endl;

    return 0;
}
