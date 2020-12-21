#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
struct reg{
  int maxLeft;
  int maxRight;
  int sum;
};
void insertNum(int *l,int *r,int *s,reg x){
  *l=x.maxLeft;
  *r=x.maxRight;
  *s=x.sum;
}
reg returnNum(int l,int r,int s){
  reg x;
  x.maxLeft=l;
  x.maxRight=r;
  x.sum=s;
  return x;
}
reg findMaxCrossingSubarr(int A[],int low,int mid,int high){
  int leftNum=-INF,maxLeft,maxRight;
  int sum=0;
  for(int i=mid;i>=low;i--){
      sum+=A[i];
      if(sum>leftNum){
        leftNum=sum;
        maxLeft=i;
      }
  }
  int rightNum=-INF;
  sum=0;
  for(int i=mid+1;i<=high;i++){
    sum+=A[ i ];
    if(sum>rightNum){
      rightNum=sum;
      maxRight=i;
    }
  }
  return returnNum( maxLeft,maxRight,rightNum+leftNum );
}
reg findMaxNumber(int A[],int low,int high){
  if(low==high){
    return returnNum( low,high,A[low] );
  }
  else {
    int mid=(low+high)/2;
    int leftLow,leftHigh,leftSum;
    int rightLow,rightHigh,rightSum;
    int crossLow,crossHigh,crossSum;
    insertNum(&leftLow, &leftLow, &leftSum,findMaxNumber(A,low,mid));
    insertNum(&rightLow, &rightLow, &rightSum,findMaxNumber(A,mid+1,high));
    insertNum(&crossLow, &crossLow, &crossSum,findMaxCrossingSubarr(A,low,mid,high));
    if(leftSum>rightSum && leftSum>crossSum)
      return returnNum( leftLow,leftHigh,leftSum );
    if(leftSum<rightSum && rightSum>crossSum)
      return returnNum( rightLow,rightHigh,rightSum );
    return returnNum( crossLow,crossHigh,crossSum );
  }

}
int main(){
  int arr[]={99,3,-5,-15,99,2,25,-1000,22,33};
  reg x;
  x=findMaxNumber(arr,0,9);
  printf("%d",x.sum);
  return 0;
}
