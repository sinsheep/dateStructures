#include<stdlib.h>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;
typedef struct TreeNode* binaryTree;
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
void PreOrder(binaryTree T){//先序遍历
    if(T!=NULL){
        printf("%d\n",T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}
void InOrder(binaryTree T){//中序遍历
    if(T!=NULL){
        InOrder(T->left);
        printf("%d\n",T->data);
        InOrder(T->right);
    }
}
void InOrder2(binaryTree T){//中序遍历
    stack<binaryTree> s;
    binaryTree p=T;
    while(p!=NULL||s.empty()){
        if(p){
            s.push(p);
            p=p->left;
        }else{
            p=s.top();
            printf("%d\n",p->data);
            s.pop();
            p=p->right;
        }
    }
}
void levelOrder(binaryTree T){//层级便利
    binaryTree p=T;
    queue<binaryTree> q;
    q.push(p);
    while(!q.empty()){
        printf("%d\n",p->data);
        if(p->left!=NULL)q.push(p->left);
        if(p->right!=NULL)q.push(p->right);
        q.pop();
    }
}
void PostOrder(binaryTree T){//后序遍历
    if(T!=NULL){
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d\n",T->data);
    }
}
int main(){
    return 0;
}
