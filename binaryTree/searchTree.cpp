#include<stdlib.h>
#include<stdio.h>
typedef struct TreeNode* SearchTree;
struct TreeNode{
    int data;
    SearchTree left;
    SearchTree right;
};

void Error(char *str){
    printf("%s\n",str);
}
void makeEmpty(SearchTree T){
    if(T!=NULL){
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
}

SearchTree FindTreeNode(SearchTree T,int value){
    if(T==NULL){
        return NULL;
    }
    if(value<T->data)
        return FindTreeNode(T->left,value);
    else if(value>T->data)
        return FindTreeNode(T->right,value);
    else
        return T;
}

SearchTree FindMin(SearchTree T){
    if(T==NULL){
        return NULL;
    }
    if(T->left==NULL)
        return T;
    else
        return FindMin(T->left);
}

SearchTree FindMax(SearchTree T){
    if(T==NULL){
        return NULL;
    }
    if(T->right==NULL)
        return T;
    else
        return FindMax(T->right);
}
SearchTree Insert(SearchTree T,int value){
    if(T==NULL){
        T=(SearchTree)malloc(sizeof(struct TreeNode));
        T->data=value;
        T->left=T->right=NULL;
    }else{
        if(T->data<value){
            T->right=Insert(T->right,value);
        }else{
            T->left=Insert(T->left,value);
        }
    }
    return T;
}
SearchTree Delete(SearchTree T,int value){
    SearchTree TmpCell;
    if(T==NULL){
        printf("Element not found\n");
    }else{
        if(value<T->data)
            T->left=Delete(T->left,value);
        else if(value>T->data)
            T->right=Delete(T->right,value);
        else if(T->left&&T->right){
            TmpCell=FindMin(T->right);
            T->data=TmpCell->data;
            T->right=Delete(T->right,value);
        }
        else{
            TmpCell =T;
            if(T->left==NULL){
                T=T->left;
            }else if(T->right==NULL){
                T=T->right;
            }
            free(TmpCell);
        }

    }
    return T;
}
int main(){
    
    return 0;
}
