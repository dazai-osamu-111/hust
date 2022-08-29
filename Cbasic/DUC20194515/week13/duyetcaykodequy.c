#include<stdio.h>
#include<stdlib.h>
typedef int keytype;
typedef struct node{
  keytype key;
  struct node *left, *right;
} nodetype;
typedef nodetype* treetype;

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

nodetype *creatnode(keytype e){
  nodetype *new=(nodetype*)malloc(sizeof(nodetype));
  if(new != NULL){
    new->left=NULL;
    new->right=NULL;
    new->key=e;
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

treetype search(keytype x, treetype root){
  if(root == NULL) return NULL;// not found
  else if(root->key == x) // found
    return root;
  else if(root->key < x)
    // continue searching in the right sub tree
    return search(x, root->right);
  else{
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

void insertnode(keytype x, treetype *root){
  if(*root == NULL){
    // Creat a new node for key x
    *root=(nodetype*)malloc(sizeof(nodetype));
    (*root)->key = x;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if(x < (*root)->key) insertnode(x, &(*root)->left);
  else if (x> (*root)->key) insertnode(x, &(*root)->right);
}
void inorder(treetype root){
  treetype p;
  while(root!=NULL){
    if(root->left == NULL){
      printf("%d\t", root->key);
      root=root->right;
    }
    else{
      p=root->left;
      while(p->right!=NULL && p->right != root) p=p->right;
      if(p->right == NULL){
	p->right=root;
	root=root->left;
      }
      else{
	p->right=NULL;
	printf("%d\t", root->key);
	root=root->right;
      }
    }
  }
  printf("\n");
}
void preorder(treetype root){
  treetype p;
  while(root){
    if(root->left==NULL){
      printf("%d\t", root->key);
      root=root->right;
    }
    else{
      p = root->left;
      while(p->right  && p->right != root){
	p=p->right;
      }
      if(p->right == NULL){
	p->right = root;
	printf("%d\t", root->key);
	root=root->left;
      }
      else{
	p->right= NULL;
	root = root->right;
      }
    }
  }
  printf("\n");
}

int main(){
  treetype T;
  int i;
  int a[8]={1,4,5,7,6,3,9,8};
  makenulltree(&T);
  for(i=0;i<8;i++){
    insertnode(a[i], &T);
  }
  printf("\n\n");
  printf("Thu tu giua:\n");
  inorder(T);
  printf("Thu tu truoc:\n");
  preorder(T);
  return 0;
}
