#include <stdio.h>
#define MAXL 100005
void build_tree(int arr[], int tree[], int node, int start, int end)
{
  // printf("%d %d %d\n",node, start, end);
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  int left_node = node * 2 + 1;
  int right_node = node * 2 + 2;
  build_tree(arr, tree, left_node, start, mid);
  build_tree(arr, tree, right_node, mid + 1, end);
  tree[node] = tree[left_node] + tree[right_node];
}
void update_tree(int arr[], int tree[], int node, int start, int end, int index, int val)
{

  if (start == end) {
    arr[index] = val;
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  int left_node = 2 * node + 1;
  int right_node = 2 * node + 2;
  if (index >= start && index <= mid) {
    update_tree(arr, tree, left_node, start, mid, index, val);
  } else {
    update_tree(arr, tree, right_node, mid + 1, end, index, val);
  }
  tree[node] = tree[left_node] + tree[right_node];
}
int query_tree(int arr[], int tree[], int node, int start, int end, int l, int r)
{
  if (r < start || l > end) {
    return 0;
  }else if(start == end || (start>=l&&end<=r)){
    return tree[node];
  }
  int mid = (start + end) / 2;
  int left_node = 2 * node + 1;
  int right_node = 2 * node + 2;
  int sum_left = query_tree(arr, tree, left_node, start, mid, l, r);
  int sum_right = query_tree(arr, tree, right_node, mid + 1, end, l, r);

  return sum_left + sum_right;
}
int main()
{

  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int size = 10;
  int tree[MAXL] = { 0 };
  build_tree(arr, tree, 0, 0, size - 1);
  for (int i = 0; i < size * 2; i++) {
    printf("tree[%d]=%d\n", i, tree[i]);
  }
  puts("");
  update_tree(arr, tree, 0, 0, 5, 4, 6);
  for (int i = 0; i < 15; i++) {
    printf("tree[%d]=%d\n", i, tree[i]);
  }
  printf("%d",query_tree(arr, tree, 0, 0, 5, 2, 5));
  return 0;
}
