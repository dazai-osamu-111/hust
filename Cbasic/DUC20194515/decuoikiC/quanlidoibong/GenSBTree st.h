#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef element keytype;
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
  else if(strcmp(root->key.name, x.name)==0) // found
    return root;
  else if(strcmp(root->key.name, x.name)<0)
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
  else if(strcmp((*root)->key.name,x.name)>0) insertnode(x, &(*root)->left);
  else if (strcmp((*root)->key.name,x.name)<0) insertnode(x, &(*root)->right);
}

void inorderprint(treetype t){
  if(t==NULL) return;
  else{
    inorderprint(t->left);
    printf("%-20s%d\n", t->key.name, t->key.score);
    inorderprint(t->right);
  }
  return;
}

treetype searchteam(char s[], treetype root){
   if(root == NULL) return NULL;// not found
  else if(strcmp(root->key.name, s)==0) // found
    return root;
  else if(strcmp(root->key.name, s)<0)
    // continue searching in the right sub tree
    return searchteam(s, root->right);
  else{
    // continue searching in the left sub tree
    return searchteam(s, root->left);
  }
}

keytype deletemin(treetype *root){
  // this function find the leftmost node then delete it
  keytype k;
  if((*root)->left == NULL){
    k=(*root)->key;
    (*root)=(*root)->right;
    return k;
  }
  else return deletemin(&(*root)->left);
}

void deletenode(keytype x, treetype *root){
  if(*root != NULL){
    if(comparename(x,(*root)->key)<0) deletenode(x, &(*root)->left);
    else if(comparename(x, (*root)->key)>0)
      deletenode(x, &(*root)->right);
    else if((*root)->left == NULL && (*root)->right == NULL)
      *root=NULL;
    else if((*root)->left == NULL)
      *root = (*root)->right;
    else if((*root)->right == NULL)
      *root = (*root)->left;
    else (*root)->key = deletemin(&(*root)->right);
  }
  return;
}

keytype* inordersearch(keytype x,treetype t){
  static keytype a[MAX];
  static int i=0;
  if(t!=NULL){ 
    inordersearch(x,t->left);
    if(compare(x, t->key)>0){
      printf("%-10s%-15d\n", t->key.name, t->key.score);
      a[i++]=t->key;
    }
    inordersearch(x,t->right);
  }
  return a;
}

int lowerthankey(keytype x, treetype t){
  static int i=0;
  if(t!=NULL){ 
    lowerthankey(x,t->left);
    if(compare(x, t->key)>0){
      i++;
    }
    lowerthankey(x,t->right);
  }
  return i;
}


void freetree(treetype *tree){
  if(*tree!= NULL){
    freetree(&(*tree)->left);
    freetree(&(*tree)->right);
    free(*tree);
  }
}

void printtofile(FILE *fptr, treetype root){
  if(root!=NULL){
    printtofile(fptr, root->left);
    fprintf(fptr, "%s\t%d\n",root->key.name,root->key.score);
    printtofile(fptr, root->right);
  }
  return;
}
/*void preorderprint(treetype tree){
  if(tree != NULL){
    printf("%4d\n", tree->key);
    preorderprint(tree->left);
    preorderprint(tree->right);
  }
}
void postorderprint(treetype tree){
  if(tree!=NULL){
    postorderprint(tree->left);
    postorderprint(tree->right);
    printf("%4d\n", tree->key);
  }
  }*/
