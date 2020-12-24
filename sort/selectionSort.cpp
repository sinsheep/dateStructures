#include<stdio.h>
int main(){
  int arr[10]={7,8,9,2,1,3,6,5,4,10};
  int len=10;
  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      if(arr[i]>arr[j]){
        arr[i]^=arr[j];
        arr[j]^=arr[i];
        arr[i]^=arr[j];
      }
    }
  }
  for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
  }
}
