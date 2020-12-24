#include<stdio.h>
int main(){
  int arr[10]={7,8,9,2,1,3,6,5,4,10};
  int len=10;
  for(int i=0;i<len-1;i++){
    for(int j=0;j<len-1-i;j++){
      if(arr[j]>arr[j+1]){
        arr[j]^=arr[j+1];
        arr[j+1]^=arr[j];
        arr[j]^=arr[j+1];
      }
    }
  }
  for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
  }
}
