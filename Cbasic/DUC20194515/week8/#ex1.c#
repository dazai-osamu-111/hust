#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
}phonedb;
#include "GenDLL.h"
phonedb inputnode(){
  phonedb a;
  printf("Enter model: ");scanf("%s",a.model);
  printf("Enter space: ");scanf("%s",a.space);
  printf("Enter screen size: "); scanf("%s",a.ssize);
  printf("Enter price: "); scanf("%s",a.price);
  return a;
}
void displaynode(node *p){
  if(p==NULL){
    printf("Null pointer error\n");
    return;
  }
  printf("%-30s%-10s%-10s%s\n",p->element.model,p->element.space,p->element.ssize,p->element.price);
}
void traversinglist(){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
int main(){
  printf("Testing insertafter function.\n");
  insertafter(inputnode());
  displaynode(root);
  printf("Testing insertathead function.\n");
  insertathead(inputnode());
  traversinglist();
  printf("Testting insertattail function.\n");
  insertattail(inputnode());
  traversinglist();
  return 0;
}
