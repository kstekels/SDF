#include <iostream>
using namespace std;

void print(int array[],int n) {
    for (int i=0;i<n;++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void merge(int array[], int left, int mid, int right) {
    int i=left;
    int j=mid+1;
    int tmp[right-left+1];
    int k=0;
    while (i<=mid && j<=right) {
        if (array[i]<array[j]) {
            tmp[k] = array[i];
            ++i;
        }
        else {
            tmp[k] = array[j];
            ++j;
        }
        ++k;
    }
    while (i<=mid) {
        tmp[k] = array[i];
        ++i;
        ++k;
    }
    while (j<=right) {
        tmp[k] = array[j];
        ++j;
        ++k;
    }
    for (int i=left,k=0; i<=right; ++i,++k) {
        array[i] = tmp[k];
    }
}

void merge_sort(int array[], int left, int right) {
    if (left>=right) return;
    int mid = (left+right) / 2;
    merge_sort(array,left,mid);
    merge_sort(array,mid+1,right);
    merge(array,left,mid,right);
}

int main()
{
    int aa[6]={8,4,6,1,5,7};
	print(aa,6);
	merge_sort(aa,0,5);
	print(aa,6);
    return 0;
}
