#include<stdio.h>
#define MAX 50
typedef int eltype;
typedef eltype stacktype[MAX];
int top;

void initialize(stacktype stack){
  top=0;
}
int empty(stacktype stack){
  return top==0;
}
int full(stacktype stack){
  return top==MAX;
}
void  push(eltype el, stacktype stack){
  if(full(stack)){
    printf("stack overflow\n");
  } else stack[top++]=el;
}
eltype pop(stacktype stack){
  if(empty(stack)){
    printf("Stack underflow.\n");
  } else return stack[--top];
}
eltype peek(stacktype stack){
  if(empty(stack)){
    printf("stack underflow\n");
    return -999999;
  }
  else return stack[top-1];
}
