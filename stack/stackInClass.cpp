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
   ElemType *top;
   ElemType *bot;
   int  stackSize;
}Stack;
Status  InitStack(Stack *s){
    s->bot = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->bot){
        return ERROR;
    }
    s->top = s->bot;
    s->stackSize = STACK_INIT_SIZE;
    return OK;
}
Status GetTop(Stack *s,ElemType *e){

    if(s->top == s->bot){
        return ERROR;
    }
    e = s->top - 1;
    return OK;
}
int StackLenth(Stack *s){
    return s->top - s->bot;
}
Status DestoryStack(Stack *s){

    free(s);
    if(s)return ERROR;
    return OK;
}
Status Push(Stack *s,ElemType a){
    if(s->top - s->bot >= s->stackSize){
        s->bot = (ElemType*) realloc(s->bot,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!s->bot)
            return ERROR;
        s->top = s->bot + s->stackSize;
        s->stackSize += STACKINCREMENT;
    }
    *s->top++ = a;
    return OK;
}
Status Pop(Stack *s, ElemType * a){
    if(s->top == s->bot){
        return ERROR;
    }
    *a = *s->top--;
    return OK;
}
Status ClearStack(Stack* s){
    free(s->bot);
    if(s->bot)return ERROR;
    return OK;
}
Status StackEmpty(Stack s){
    return s.top - s.bot == 0;
}
int main(){
    return 0;
}
