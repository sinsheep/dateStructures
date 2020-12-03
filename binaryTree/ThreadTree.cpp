#include<stdlib.h>
#include<stdio.h>
//线索化  若无左子树，则将左指针指向其前驱节点
//线索化  若无右子树，则将右指针指向其前驱节点
struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
};
typedef struct ThreadNode ThreadNode;
//mid
ThreadNode *Firstnode(ThreadNode *p){//mid search
    while(p->ltag==0){
        p=p->lchild;
    }
    return p;
}
ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag==0)
        return Firstnode(p->rchild);
    else 
        return p->rchild;
}
void inorder(ThreadNode *T){
    for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
        printf("%d\n",T->data);
}
//mid
