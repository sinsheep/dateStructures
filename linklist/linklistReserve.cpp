#include<bits/stdc++.h>
#define mset(a) memset(a,0,sizeof(a))
#define inf 0x3f3f3f
using namespace std;
struct node{
    int data;
    struct node* next;
};
node* createNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
void insert(node *p,int x){
    node *newNode=createNode(x);
    newNode->next=p->next;
    p->next=newNode;
    p->data++;
}
int main(){
    int n;
    node* head=createNode(0);
    while(scanf("%d",&n),n>0){
        insert(head, n);
    }
    n=0;
    head=head->next;
    while(head!=NULL){
        if(n++)putchar(' ');
        printf("%d",head->data);
        head=head->next;
    }
    return 0;
}

