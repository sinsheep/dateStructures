#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int L,int M,int R){
    int leftSize=M-L;
    int rightSize=R-M+1;
    int left[leftSize];
    int right[rightSize];
    for(int i=L;i<M;i++){
        left[i-L]=arr[i];
    }
    for(int i=M;i<=R;i++){
        right[i-M]=arr[i];
    }
    int i=0,j=0,k=L;
    while(i<leftSize&&j<rightSize){
        if(left[i]>right[j]){
            arr[k]=right[j];
            k++;
            j++;
        }else{
            arr[k]=left[i];
            k++;
            i++;
        }
    }
    while(i<leftSize){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<rightSize){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int L,int R){
    if(L==R){
        return ;
    }else{
        int M=(L+R)/2;
        mergeSort(arr,L,M);
        mergeSort(arr,M+1,R);
        merge(arr,L,M+1,R);
    }
}
int main(){

    int arr[]={8,2,5,3,6,1,7,4};
    int arr2[]={2,5,6,8,1,3,4,7};
    mergeSort(arr,0,7);
    // merge(arr2,0,4,7);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
