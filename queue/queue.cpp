#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int date;
    struct node* next;
}Node;
Node* creatNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->date=value;
    newNode->next=NULL;
    return newNode;
}
Node* push(Node* tail,int value){
    Node* newNode=creatNode(value);
    tail->next=newNode;
    tail=newNode;
    return tail;
}
int isEmpty(Node *head){
    return head->next==NULL;
}
int top(Node *head){
    if(isEmpty(head)) {
        printf("this is empty queue!\n");
        return 0;
    }else{
        return head->next->date;
    }
}
void pop(Node *head){
    if(isEmpty(head)) {
        printf("this is empty queue!\n");
    }else{
        Node* tmp=head->next;
        head->next=head->next->next;
        free(tmp);
    }
}
int main(){

    Node *head=creatNode(0);
    Node *tail=head;
    int n;
    for(int i=0;i<5;i++){
        scanf("%d",&n);
        tail = push(tail,n);
        printf("%d\n",top(head));
    }
    for(int i=0;i<5;i++){
        printf("%d\n",top(head));
        pop(head);
    }
    return 0;
}
