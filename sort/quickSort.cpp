#include<stdio.h>
int Partition(int A[],int low,int high){
    int pivot = A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot){
            --high;
        }
        A[low]=A[high];
        while(low<high && A[low]<=pivot){
            ++low;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int A[], int low, int high){
    if(low<high){
        int pivot = Partition(A,low,high);
        QuickSort(A,low,pivot-1);
        QuickSort(A,pivot+1,high);
    }
}
int main(){
    int a[]={1,2,6832,32812,894321,892,27,298};
    QuickSort(a,0,7);
    for(int i=0;i<8;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
