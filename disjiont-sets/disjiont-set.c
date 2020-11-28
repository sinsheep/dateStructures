#include <stdio.h>
#include <stdlib.h>
#define NUM 6
void arrInitialize(int parent[])
{
  for (int i = 1; i <= NUM; i++) {
    parent[i] = i;
  }
}
int findParent(int child, int* parent)
{
  while (child != parent[child]) {
    child = parent[child];
  }
  return child;
}
int union_parent(int x, int y, int* parent)
{
  int x_root = findParent(x, parent);
  int y_root = findParent(y, parent);
  if (x_root != y_root) {
    parent[x_root] = y_root;
    return 1;
  }else return 0;
}
int main()
{
  int arr[][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 2 } };
  int parent[NUM];
  arrInitialize(parent);
  for (int i = 0; i < 4; i++) {
    int status = union_parent(arr[i][0], arr[i][1], parent) ;
    if(!status){
      printf("cycle detected");
      exit(0);
    }
  }
  printf("cycle not find");
  return 0;
}
