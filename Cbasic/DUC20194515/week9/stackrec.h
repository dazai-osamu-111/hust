#include<stdio.h>
#define MAX 50
typedef int eltype;
typedef struct stackrec{
  eltype storage[MAX];
  int top;
};
typedef struct stackrec stacktype;
int isempty(stacktype stack){
  return stack.top == 0;
}
int isfull(stacktype stack){
  return stack.top == MAX;
}
int initialize(stacktype *stack){
  (*stack).top = 0;
}
eltype push(eltype el, stacktype *stack){
  if(isfull(*stack))
    printf("Stack overflow");
  else(*stack).storage[(*stack).top++]=el;
}
eltype pop(stacktype *stack){
  if(isempty(*stack))
    printf("stack underflow");
  else return (*stack).storage[--(*stack).top];
}
eltype peek(stacktype stack){
  if(isempty(stack))
    printf("stack underflow");
  else return stack.storage[stack.top-1];
}
