#include<stdio.h>
#define MAX 50
typedef int eltype;
typedef struct stackrec{
  eltype storage[MAX];
  int top;
} stacktype;
void initialize(stacktype *stack){
  (*stack).top=0;
}
int empty(stacktype stack){
  return stack.top==0;
}
int full(stacktype stack){
  return stack.top==MAX;
}
void push(eltype e,stacktype *stack){
  if(full(*stack)){
    printf("Stack over flow\n");
  } else{
    (*stack).storage[(*stack).top++]=e;
  }
}
eltype pop(stacktype *stack){
  if(empty(*stack)){
    printf("stack underflow\n");
  }else{
    return (*stack).storage[--(*stack).top];
  }
}
eltype peek(stacktype stack){
  if(empty(stack)){
    printf("stack underflow\n");
  } else{
    return stack.storage[stack.top-1];
  }
}
  
