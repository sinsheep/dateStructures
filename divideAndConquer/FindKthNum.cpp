#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
int randomized_partition(int A[],int low,int high){
    int i=low-1;
    int j=rand()%(high-low+1)+low;
    swap(A[high],A[j]);
    for(j=low;j<high;++j){
        if(A[j]<=A[high]){
            swap(A[++i],A[j]);
        }
    }
    swap(A[high],A[++i]);
    return i;
}
int randomized_partition1(int A[],int low,int high){
    int i=low;
    int x=rand()%(high-low)+low;
    swap(A[low],A[x]);
    for(int j=low+1;j<high;j++){
        if(A[j]<=A[low]){
            swap(A[++i],A[j]);
        }
    }
    swap(A[low],A[i]);
    return i;
}
int randomized_select(int A[],int low,int high,int i){
    if(low==high)return A[low];
    int q=randomized_partition1(A,low,high);
    int k=q-low+1;
    if(k==i)return A[q];
    else if(i<k)
        return randomized_select(A,low,q,i);
    else
        return randomized_select(A, q+1, high, i-k);
}
int main(){
    srand(time(0));
    int a[10] = {3, 5, 7, 9, 8, 6, 1, 2, 4,10};
    printf("%d\n",randomized_select(a, 0, 9, 9));
    // printf("%d\n",randomized_select(a, 0, 9, 4));
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
    }
}
