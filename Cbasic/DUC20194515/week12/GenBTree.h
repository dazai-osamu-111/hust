#include<stdio.h>
#include<stdlib.h>
typedef int elmtype;
// whatever type of element
typedef struct nodetype{
  elmtype element;
  struct nodetype *left, *right;
} node;
typedef node *treetype;
void makenulltree(treetype *T){
  (*T)=NULL;
}
int emptytree(treetype T){
  return T==NULL;
}

treetype leftchild(treetype n){
  if(n!=NULL) return n->left;
  else return NULL;
}

treetype rightchild(treetype n){
  if(n!=NULL) return n->right;
  else return NULL;
}

node *creatnode(elmtype e){
  node *new=(node*)malloc(sizeof(node));
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
  else return 1+nbnode(T->left)+ nbnode(T->right);
}
treetype creatfrom2(elmtype v, treetype l, treetype r){
  treetype N;
  N=(node*)malloc(sizeof(node));
  N->element=v;
  N->left=l;
  N->right=r;
  return N;
}

treetype addleft(treetype *tree, elmtype e){
  node *new=creatnode(e);
  if(new==NULL) return new;
  if(*tree==NULL)
    *tree = new;
  else{
    node *lnode = *tree;
    while (lnode->left != NULL){
      lnode=lnode->left;
    }
    lnode->left=new;
  }
  return new;
}

treetype addright(treetype *tree, elmtype e){
  treetype new=creatnode(e);
  if(new==NULL) return new;
  if(*tree == NULL) *tree=new;
  else{
    node *rnode=*tree;
    while(rnode->right  !=NULL) rnode=rnode->right;
    rnode->right=new;
  }
  return new;
}

int max1(int a, int b){
  if(a>b) return a;
  return b;
}

int high(treetype t){
  if(t==NULL)
    return 0;
  else return 1+max1(high(t->left), high(t->right));
}

int nbleaf(treetype T){
  if(T==NULL){
    return 0;
  }else{
    if(T->left==NULL && T->right==NULL){
      return 1;
    }else{
      return  nbleaf(T->left)+nbleaf(T->right);
    }
  }
}
int nbinnode(treetype T){
  return nbnode(T)-nbleaf(T)-1;
}

int nbrightchild(treetype T){
  if(T==NULL){
    return 0;
  } else{
    if(T->right != NULL)
      return 1+ nbrightchild(T->left)+ nbrightchild(T->right);
  }
}
int NumRChild(treetype t)
{
  if (t == NULL)
    return 0;
  if (t->right == NULL)
    return NumRChild(t->left);
  return 1 + NumRChild(t->left) + NumRChild(t->right);
}
