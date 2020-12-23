#include<stdio.h>
int  findNum(int num,int n){
  for(int i=0;i<n-1;i++){
    num/=10;
  }
  return num%10;
}
void swap(int *a,int *b){
  int c=*a;
  *a=*b;
  *b=c;
}
void RadixSort(int arr[],int len,int k){
  for(int i=1;i<=k;i++){
    int c[10]={0};
    int b[len];
    for(int j=0;j<len;j++){
      int d=findNum(arr[j], i);
      c[d]++;
    }
    for(int j=1;j<10;j++){
      c[j]=c[j]+c[j-1];
    }
    for(int j=len-1;j>=0;j--){
      int d=findNum(arr[j], i);
      c[d]--;
      b[c[d]]=arr[j];
    }
    for(int j=0;j<len;j++){
      arr[j]=b[j];
    }
  }

}
int main(){
  int arr[10]={123,523,251,521,523,643,972,922,291};
  int len=9,k=3;
  RadixSort(arr, len, k);
  for(int i=0;i<9;i++){
    printf("%d ",arr[i]);
  }
}
