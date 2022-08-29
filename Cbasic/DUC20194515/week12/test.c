#include<stdio.h>
#include "GenBTree.h"
void inorderprint1(treetype t){
  if(t==NULL) return;
  else{
    inorderprint1(t->left);
    printf("%4d\n", t->element);
    inorderprint1(t->right);
  }
  return;
}
void inorder(treetype root){
  treetype current, pre;
  
  if (root == NULL)
    return;
  
  current = root;
  while (current != NULL) {
    
    if (current->left == NULL) {
      printf("%d ", current->element);
      current = current->right;
    }
    else {
      pre = current->left;
      while (pre->right != NULL
	     && pre->right != current)
	pre = pre->right;
      if (pre->right == NULL) {
	pre->right = current;
	current = current->left;
      }
      else {
	pre->right = NULL;
	printf("%d ", current->element);
	current = current->right;
      } 
    } 
  } 
}
void preeorder(treetype T){
  
}
int main(){
  /*                Binary tree        
                        3                
	               / \                
	              2   1               
	             /\   /\              
	            /  \ 7  8             
	           4    5            
	          /\   /\           
                 6 7  8 9         
                     /
                    10
                                   */
  treetype T;
  makenulltree(&T);
  T=creatnode(3);
  T->left=creatnode(2);
  T->right=creatnode(1);
  T->left->left=creatnode(4);
  T->left->right=creatnode(5);
  T->left->left->left=creatnode(6);
  T->left->left->right=creatnode(7);
  T->left->right->left=creatnode(8);
  T->left->right->left->left=creatnode(10);
  T->left->right->right=creatnode(9);
  T->right->left=creatnode(7);
  T->right->right=creatnode(8);
  inorderprint1(T);
  printf("\n\n");
  inorder(T);
  return 0;
}
