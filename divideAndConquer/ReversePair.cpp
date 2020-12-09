#include<stdio.h>
#define inf 0x3f3f3f
#define L 100010
#define ll long long 
int n,arr[L];
ll sum=0;
void mergeSort(int l,int r){
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int leftSize=mid-l+1,rightSize=r-mid;
    int left[leftSize];
    int right[rightSize];
    for(int i=l;i<=mid;i++){
        left[i-l+1]=arr[i];
    }
    for(int i=mid+1;i<=r;i++){
        right[i-mid]=arr[i];
    }
    int i=1,j=1,k=l;
    while(i<=leftSize&&j<=rightSize){
        if(left[i]>right[j]){
            arr[k]=right[j];
            k++;
            j++;
            sum+=(leftSize-i+1);
        }else{
            arr[k]=left[i];
            k++;
            i++;
        }
    }
    // sum+=(leftSize-i+1);
    while(i<=leftSize){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<=rightSize){
        arr[k]=right[j];
        j++;
        k++;
    }
}
int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sum=0;
    mergeSort(1, n);
    printf("%lld\n",sum);
}
