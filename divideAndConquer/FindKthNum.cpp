#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
int randomized_partition(int A[],int low,int high){
    int i=low-1;
    int j=rand()%(high-low+1)+low;
    swap(A[high],A[j]);
    for(int j=low;j<high;++j){
        if(A[j]<=A[high]){
            swap(A[++i],A[j]);
        }
    }
    swap(A[high],A[++i]);
    return i;
}
int randomized_select(int A[],int low,int high,int i){
    if(low==high)return A[low];
    int q=randomized_partition(A,low,high);
    int k=q-low+1;
    if(k==i)return A[q];
    else if(i<k)
        return randomized_select(A,low,q-1,i);
    else
        return randomized_select(A, q+1, high, i-k);
}
int main(){
    srand(time(0));
    int a[9] = {3, 5, 7, 9, 8, 6, 1, 2, 4};
    printf("\n%d\n",randomized_select(a, 0, 9, 4));
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
    }
}
