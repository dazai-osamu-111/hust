#include<stdio.h>
#include "stackrec.h"
int main(){
  int a[6]={1,2,3,4,5,6};
  int i;
  stacktype s;
  initialize(&s);
  for(i=0;i<6;i++){
    push(a[i], &s);
  }
  printf("pop all element in stack!\n");
  while(!empty(s)){
    printf("%4d\n", pop(&s));
    }
  return 0;
}
