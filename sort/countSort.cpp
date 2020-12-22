#include<stdio.h>
#include<string.h>
void CountSort(int *arr,int *dest,int maxNum,int len){
  int c[maxNum+1];
  memset(c,0,sizeof(c));
  for(int i=0;i<len;i++){
    c[arr[i]]++;
  }
  for(int i=1;i<=maxNum;i++){
    c[i]+=c[i-1];
  }
  for(int i=len-1;i>=0;i--){
    dest[c[arr[i]]-1]=arr[i];
    c[arr[i]]--;
  }
}
int main(){
  int arr[10]={8,9,2,4,5,1,2,1,2,9},dest[10];
  int len=10;
  int max=9;
  CountSort(arr, dest, max,len);
  for(int i=0;i<len;i++){
    printf("%d ",dest[i]);
  }
}
