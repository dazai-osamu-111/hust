#include<stdio.h>
#include "GenBTree.h"
void inorderprint(treetype t){
  if(t==NULL) return;
  else{
    inorderprint(t->left);
    printf("%4d\n", t->element);
    inorderprint(t->right);
  }
  return;
}
int main(){
  treetype T;
  int a[11]={3,5,6,9,8,7,1,2,4,20,33};
  int i;
  makenulltree(&T);
  /* addright(&T, 3);
  addleft(&T, 5);
  addleft(&T, 6);
  addright(&T->left, 9);
  addright(&T, 8);
  addright(&T, 7);*/
 
  for(i=0;i<7;i++){
    addleft(&T, a[i]);
  }
  for(i=7;i<11;i++){
    addright(&T, a[i]);
  }
  inorderprint(T);
  printf("the number of node: %d\n", nbnode(T));
  printf("The height of tree: %d\n", high(T));
  printf("The number of leaf: %d\n", nbleaf(T));
  printf("The number of internal node: %d\n", nbinnode(T));
  printf("The number of rightchild(DUC): %d\n", nbrightchild(T));
  printf("The number of rightchild (hai): %d\n", NumRChild(T));
  return 0;
}
