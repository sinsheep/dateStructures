#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
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
int Partition2(int A[],int p,int q){
    int i=p,j,x=A[p];
    for(j=p+1;j<q;j++){
        if(A[j]<x){
            i++;
            std::swap(A[j],A[i]);
        }
    }
    std::swap(A[p],A[i]);
    return i;
}
int PartitionRandomize(int A[],int p,int q){

    int r=rand()%(p-q)+p;
    std::swap(A[r],A[p]);
    int i=p,j,x=A[p];
    for(j=p+1;j<q;j++){
        if(A[j]<x){
            i++;
            std::swap(A[j],A[i]);
        }
    }
    std::swap(A[p],A[i]);
    return i;
}
void QuickSort2(int A[],int p,int q){
    if(p<q){
        // int pivot=PartitionRandomize(A,p,q);
        int pivot=Partition2(A,p,q);
        QuickSort2(A,p,pivot);
        QuickSort2(A,pivot+1,q);
    }
}
int main(){
    // printf("%d %d",a,b);
    srand(unsigned(time(NULL)));
    int A[]={1,2,6832,32812,894321,892,27,298};// {6,10,13,5,8,3,2,1};
    QuickSort2(A,0,8);
    for(int i=0;i<8;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
