#include<stdio.h>
int binarySearch(int arr[],int v,int len){
    int begin=0,end=len-1;
    while(begin<end){
        int mid= ( begin+end )/2;
        if(arr[mid]<v){
            begin=mid+1;
        }else if(arr[mid]>v){
            end=mid-1;
        }else{
            return arr[mid];
        }
    }
    return arr[begin];
}
int main(){
    int arr[]={1,2,3,4,5,6,7,281,2952,3952};
    printf("%d\n",binarySearch(arr,3952,10));
    return 0;
}
