#include<stdio.h>
#include<stdlib.h>
struct list_el{
  int a;
  struct list_el *next;
};
typedef struct list_el listint;
listint *root=NULL, *cur=NULL, *prev=NULL;
listint* makenewnode(int x){
  listint *new=(listint*)malloc(sizeof(listint));
  new->a=x;
  new->next=NULL;
  return new;
}
void displaynode(listint *p){
  if(p==NULL){
    printf("NULL pointer error.\n");
    return;
  }
  printf("%d ", p->a);
}
void displaylist(){
  listint *p;
  for(p=root;p!=NULL;p=p->next)
    displaynode(p);
}
void insertafter(int x){
  listint *new=makenewnode(x);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  } else if(cur == NULL) return;
  else{
    new->next=cur->next;
    cur->next=new;
    prev=cur;/*update poiter for use*/;
    cur=cur->next;
  }
}
int readnode(){
  int x;
  printf("Enter integer number: ");
  scanf("%d", &x);
  return x;
}


int main(){
  int n,i;
  printf("Nhap so nguyen n:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    insertafter(readnode());
  }
  displaylist();
  return 0;
}
