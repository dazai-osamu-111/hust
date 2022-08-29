#include<stdio.h>
#include "GenSBTree.h"
#include "stacklist.h"
void inorder(treetype root){
  treetype p=root;
  stacktype *s=NULL;
  while(root!=NULL){
    if(p!=NULL){
      push(&s,p->key);
      printf("1\n");
      p=p->left;
    }
    else
      if(empty(s)){
	p->key=pop(&s);
	printf("1\n");
	printf("%d\t", p->key);
	p=p->right;
      }
      else root=NULL;
  }
  
  
}
int main(){
  treetype T;
  int i;
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  makenulltree(&T);
  for(i=0;i<10;i++){
    insertnode(a[i], &T);
  }
  inorderprint(T);
  printf("\n\n");
  inorder(T);
  return 0;
}
