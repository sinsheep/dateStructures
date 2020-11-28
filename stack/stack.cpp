#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int date;
    struct node* next;
}Node;
Node* creatNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->date=value;
    newNode->next=NULL;
    return newNode;
}
int isEmpty(Node *stack){
    return stack->next==NULL;
}
int top(Node* stack){
    if(isEmpty(stack)){
        printf("这是一个空表\n");
        return 0;
    }else{
        return stack->next->date;
    }
}
void push(Node* stack,int value){
    Node* newNode=creatNode(value);
    newNode->next=stack->next;
    stack->next=newNode;
}
void pop(Node *stack){
    if(isEmpty(stack)){
        printf("这是一个空表\n");
    }else{
        Node* tmp=stack->next;
        stack->next=stack->next->next;
        stack->date--;
        free(tmp);
    }
}
int main(){
    Node *stack=creatNode(0);
    int n;
    for(int i=0;i<5;i++){
        scanf("%d",&n);
        push(stack,n);
    }
    for(int i=0;i<5;i++){
        printf("%d\n",top(stack));
        pop(stack);
    }
    return 0;
}
