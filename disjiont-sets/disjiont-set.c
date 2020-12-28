#include <stdio.h>
#include <stdlib.h>
#define NUM 6
void arrInitialize(int parent[],int *sz,int *rank)
{
    for (int i = 1; i <= NUM; i++) {
        
        parent[i] = i;
        sz[i]=1;
        rank[i]=1;
    }
}
int findParent(int child, int* parent)
{
    while (child != parent[child]) {

        child = parent[child];
    }
    return child;
}
int union_parent(int x, int y, int* parent,int *sz,int *rank)
{
    int x_root = findParent(x, parent);
    int y_root = findParent(y, parent);
    if (x_root != y_root) {
        if(sz[x_root]<sz[y_root]){
            parent[x_root] = y_root;
            sz[y_root]+=sz[x_root];
        }else{
            parent[y_root] = x_root;
            sz[x_root]+=sz[y_root];
        }
        return 1;
    } else
        return 0;
}
int union_parentRank(int x, int y, int* parent,int *rank)
{
    int x_root = findParent(x, parent);
    int y_root = findParent(y, parent);
    if(rank[x_root]<rank[y_root]){
        parent[x_root]=y_root;
        return 1;
    }else if(rank[x_root>rank[y_root]]){
        parent[y_root]=x_root;
        return 1;
    }else{
        parent[y_root]=x_root;
        rank[x_root]+=1;
    }
    return 0;
}
int main()
{
    int arr[][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 2 } };
    int parent[NUM],size[NUM],rank[NUM];
    arrInitialize(parent,size,rank);
    for (int i = 0; i < 4; i++) {
        int status = union_parent(arr[i][0], arr[i][1], parent,size,rank);
        if (!status) {
            printf("cycle detected");
            exit(0);
        }
    }
    printf("cycle not find");
    return 0;
}
