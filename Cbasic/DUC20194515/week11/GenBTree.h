#include<stdio.h>
typedef int elmtype;
// whatever type of element
typedef struct nodetype{
  emltype element;
  struct nodetype *left, *right;
};
typedef struct nodetype *treetype;
void makenulltree(treetype *T){
  (*T)=NULL;
}
int emptytree(treetype T){
  return T=NULL;
}

treetype leftchild(treetype n){
  if(n!=NULL) return n->left;
  else return NULL;
}

treetype rightchild(treetype n){
  if(n!=NULL) return n->right;
  else return NULL;
}

treetype *creatnode(elmtype e){
  treetype *new=(treetype*)malloc(sizeof(treetype));
  if(new != NULL){
    new->left=NULL;
    new->right=NULL;
    new->element=e;
  }
  return new;
}

int isleaf(treetype n){
  if(n!=NULL){
    return (leftchild(n)==NULL) && (rightchild(n) == NULL);
  }
  else return -1;
}

int nbnode(treetype T){
  if(emptytree(T)) return 0;
  else return 1+nbnode(leftchild(T))+ nbnode(rightchild(T));
}
treetype creatfrom2(element v, treetype l, treetype r){
  treetype N;
  N=(treetype*)malloc(sizeof(treetype));
  N->element=v;
  N->left=l;
  N->right=r;
  return N;
}

treetype addleft(treetype *tree, elmtype e){
  treetype *new=creatnode(e);
  if(new==NULL) return new;
  if(*tree==NULL)
    *tree = newnode;
  else{
    treetype *lnode = *tree;
    while (lnode->left != NULL)
      
  }
}
