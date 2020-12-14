#include <stdio.h>
void insertSort(int *arr,int len){
    for(int i=1;i<len;i++){
        int j=i-1,key=arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){

    int len=10;
    int arr[10]={6,12,4,24,1,4,2,5,77,1};
    insertSort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
