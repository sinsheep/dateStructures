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
// void swap(int *a,int *b){ 
//     int tmp=*a;
//     *a=*b;
//     *b=*a;
// }
int Partition2(int A[],int p,int q){
    int i=p,j,x=A[p];
    for(j=p+1;j<q;j++){
        if(A[j]<x){
            i++;
            int tmp=A[j];
            A[j]=A[i];
            A[i]=tmp;
        }
    }
    int tmp=A[p];
    A[p]=A[i];
    A[i]=tmp;
    return i;
}
void QuickSort2(int A[],int p,int q){
    if(p<q){
        int pivot=Partition2(A,p,q);
        printf("pivot=%d\n",pivot);
        QuickSort2(A,p,pivot);
        QuickSort2(A,pivot+1,q);
    }
}
int main(){
    // printf("%d %d",a,b);
    int A[]={1,2,6832,32812,894321,892,27,298};// {6,10,13,5,8,3,2,1};
    QuickSort2(A,0,8);
    for(int i=0;i<8;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
