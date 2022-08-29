#include<stdio.h>
#include<stdlib.h>
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

treetype search(tensv  x, treetype root){
  if(root == NULL) {
    return NULL;// not found
  }
  else if(compare(root->key.ten, x)==0) // found
    return root;
  else if(compare(root->key.ten , x)<0)
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
    //printf("%s %s %s\n", x.lastname,x.midname,x.firstname);
    (*root)->left = NULL;
    (*root)->right = NULL;
    return;
  }
  else if(compare(x.ten,(*root)->key.ten)==-1) insertnode(x, &(*root)->left);
  else if (compare(x.ten, (*root)->key.ten)==1) insertnode(x, &(*root)->right);
}
void inorderprint(treetype t){
  if(t==NULL) return;
  else{
    inorderprint(t->left);
    printf("%-10d%-20s%s %s %s\t\t%s\n",t->key.stt,t->key.mssv, t->key.ten.lastname,t->key.ten.midname,t->key.ten.firstname, t->key.sdt);
    
    inorderprint(t->right);
  }
  return;
}


/*keytype deletemin(treetype *root){
  // this function find the leftmost node then delete it
  keytype k;
  if((*root)->left == NULL){
    k=(*root)->key;
    (*root)=(*root)->right;
    return k;
  }
  else return deletemin(&(*root)->left);
}

/*void deletenode(keytype x, treetype *root){
  if(*root != NULL){
    if(x < (*root)->key) deletenode(x, &(*root)->left);
    else if(x > (*root)->key)
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
void freetree(treetype *tree){
  if(*tree!= NULL){
    freetree(&(*tree)->left);
    freetree(&(*tree)->right);
    free(*tree);
  }
  }
  
void preorderprint(treetype t){
  if(t != NULL){
    printf("%s %s %s\n", t->key.ten.lastname,t->key.ten.midname,t->key.ten.firstname);
    preorderprint(t->left);
    preorderprint(t->right);
  }
}



void postorderprint(treetype t){
  if(t!=NULL){
    postorderprint(t->left);
    postorderprint(t->right);
    printf("%s %s %s\n", t->key.lastname,t->key.midname,t->key.firstname);
  }
  }*/
