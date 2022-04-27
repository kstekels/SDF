#include<iostream>
using namespace std;

void print(int array[],int n) {
    for (int i=0;i<n;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int common3(int array_1[],int array_2[],int array_3[],int n) {
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            for (int k=0;k<n;++k)
                if (array_1[i]==array_2[j] && array_2[j]==array_3[k])
                    return 1;
    return 0;
}

int main()
{
    int array_1[6]={1,4,5,6,7,8};
	int array_2[6]={11,44,55,66,77,88};
	int array_3[6]={111,444,555,666,777,8};
    print(array_1,6); // 1 4 5 6 7 8
	print(array_2,6); // 11 44 55 66 77 88
	print(array_3,6); // 111 444 555 666 777 8
    cout << common3(array_1, array_2, array_3, 6) << endl; // 0
    return 0;
}
