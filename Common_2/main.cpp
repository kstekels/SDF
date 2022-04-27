#include<iostream>
using namespace std;

void print(int array[],int n) {
    for (int i=0;i<n;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int common2(int array_1[],int array_2[],int n) {
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (array_1[i]==array_2[j])
                return 1;
    return 0;
}

int main()
{
    int array_1[6]={1,4,5,6,7,8};
	int array_2[6]={11,44,55,66,77,8};
	print(array_1,6); // 1 4 5 6 7 8
	print(array_2,6); // 11 44 55 66 77 8
	cout<<common2(array_1,array_2,6)<<endl; // 1
    return 0;
}
