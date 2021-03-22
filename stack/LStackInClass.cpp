#include<stdlib.h>
#include<stdio.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct  stack{
    struct stack* next;
    ElemType data;
}LStack;
Status InitStack(LStack* s){
    if(!s)
        return ERROR;
    s->data = 0;
    s->next = NULL;
    return OK;
}
Status GetTop(LStack* s, ElemType *e){
    if(s->next == NULL){
        return ERROR;
    }
    *e = s->next->data;
    return OK;
}
Status Push(LStack* s, ElemType e){
    LStack* p = (LStack*)malloc(sizeof(LStack));
    if(!p) return ERROR;
    p->data = e;
    p->next = s->next;
    s->next = p;
    s->data++;
    return OK;
}
Status Pop(LStack* s,ElemType* e){
    if(s->next == NULL){
        return ERROR;
    }
    *e = s->next->data;
    s->next = s->next->next;
    return OK;
}
int isEmptyStack(LStack* s){
    return s->next == NULL;
}
int main(){
    LStack s;
    InitStack(&s);
    // printf("%d+-+-+_+_+\n",s.next==NULL);
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        printf("%d+++++\n",t);
        Push(&s,t);
    }
    Pop(&s,&t);
    printf("%d-----\n",t);
    int p = GetTop(&s,&t);
    printf("%d-----\n",t);
    return 0;
}

