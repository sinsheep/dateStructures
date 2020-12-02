#include<stdio.h>
void shellSort(int v[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap;i<n;i++){
            for(j=i-gap;j>=0&&v[j]>v[j+gap];j-=gap){
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
            }
        }
    }
}
int main(){
    int arr[]={1,4,5,6,7,21,2};
    shellSort(arr,7);
    for(int i=0;i<7;i++){
        printf("%d%c",arr[i],i==7?'\n':' ');
    }
    return 0;
}
