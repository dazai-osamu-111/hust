#include<stdio.h>
#include "stackrec.h"
int main(){
  int a[6]={4,7,1,-9,26,13}; int i;
  stacktype s; initialize(&s);
  for(i=0;i<6;i++) push(a[i],&s);
  printf("Pop all elements in stack!\n");
  while(!isempty(s)){
    printf("%4d\n", pop(&s));
  }
  return 0;
}
