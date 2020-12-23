#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct tree* treeChild;
char pre[100];
int n=0;
struct tree{
	char data;
	treeChild lChild,rChild; 
};
treeChild creatNode(){
	treeChild newNode=(treeChild)malloc(sizeof(tree));
	newNode->data='.';
	newNode->lChild=NULL;
	newNode->rChild=NULL;
	return newNode;
}
void mid(treeChild &x){
	if(x!=NULL){
		mid(x->lChild);
		printf("%c",x->data);
		mid(x->rChild);
	}

} 
void post(treeChild &x){
	if(x!=NULL){
		post(x->lChild);
		post(x->rChild);
		printf("%c",x->data);
	}
	
} 
void build(treeChild &x){
	if(pre[++n]!='.'){
		x=creatNode();
		x->data=pre[n];
		build(x->lChild);
		build(x->rChild);
	}
	else{
		x=NULL;
	}
}

int main(){
	scanf("%s",pre);
	treeChild fa;
	n=-1;
	build(fa);
	mid(fa);
	putchar('\n');
	post(fa);
	putchar('\n');
	return 0;
}
