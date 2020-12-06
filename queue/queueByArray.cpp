#include<stdio.h>
#include<stdlib.h>
#define MAXN 50
void insert(int* arr,int* rear,int n){
    arr[*rear]=n;
    ( *rear )++;
}
void pop(int *arr,int *front,int *rear){
    if(*rear==0){
        printf("queue is empty");
        return ;
    }
    for(int i=0;i<(*rear)-1;i++){
        arr[i]=arr[i+1];
    }
    (*rear)--;
}
int main(){
    int queue[MAXN];
    int n,front,rear;
    scanf("%d",&n);
    front=0;
    rear=0;
    for(int i=0;i<n;i++){ 
        insert(queue,&rear,i+1);
    }
    for(int i=0;i<rear;i++){
        printf("%d\n",queue[i]);
    }
    for(int i=0;i<n;i++){ pop(queue,&front,&rear);
        for(int j=0;j<rear;j++){
            printf("%d ",queue[j]);
        }
        putchar('\n');
    }
    return 0;
}
