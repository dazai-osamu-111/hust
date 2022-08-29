#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stacktypestr{
  char e[100];
  struct stacktypestr *link;
} stacktypestr;
int emptystr(stacktypestr *p){
  return p==NULL;
}
void pushstr(stacktypestr **p, char e[]){
  stacktypestr *new=(stacktypestr*)malloc(sizeof(stacktype));
  strcpy(new->e, e);
  new->link=*p;
  *p=new;
  return;
}
char *popstr(stacktypestr **p){
  if(emptystr(*p)){
    printf("stack undeflow \n");
    exit(0);
  }
  stacktypestr *temp=*p;
  char *poped=(char*)malloc(sizeof(char) *100);
  strcpy(poped,temp->e); 
  *p=(*p)->link;
  free(temp);
  return poped;
}
void freestackstr(stacktypestr **p){
  while(!emptystr(*p)){
    popstr(p);
  }
}
char *peekstr(stacktypestr *p){
  if(emptystr(p)){
    printf("stack undeflow\n");
    exit(0);
  }
  char *str=(char*)malloc(sizeof(char) *100);
  strcpy(str, p->e);
  return str;
}
