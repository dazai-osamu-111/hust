#include<stdio.h>
#define MAX 100
#include "stacklist.h"
#include "stacklistforstring.h"
int main(){
  stacktype *r1=NULL, *r3=NULL;
  stacktypestr *r2=NULL;
  int x,x1,x2;
  char s[MAX];
  do{
    printf("\n************Simulate undo funtion******************\n");
    printf("1. Add 1 integer to the stack\n2. View top\n");
    printf("3. Remove from the stack contains integers 1 element\n4. Undo\n");
    printf("5. exit\n");
    printf("Your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      printf("Enter 1 integer: ");
      scanf("%d",&x1);
      push(&r1,x1);
      pushstr(&r2,"push");
      printf("Done!\n");
      break;
    case 2:
      printf("Top is: %d\n", peek(r1));
      break;
    case 3:
      push(&r3, pop(&r1));
      pushstr(&r2,"pop");
      printf("%d was removed.\n",peek(r3));
      printf("Done!\n");
      break;
    case 4:
      if(strcmp(peekstr(r2), "push")==0){
	popstr(&r2);
	printf("Undo function done!\n");
	if(empty(r1)){
	  printf("stack empty\n");break;
	} else{
	  printf("Top is: %d\n", peek(r1));
	  break;
	}
      }
      if(strcmp(peekstr(r2), "pop")==0){
	popstr(&r2);
	push(&r1, pop(&r3));
	printf("Undo function done!\n");
	printf("Top is: %d\n", peek(r1));
	break;
      }
    default: break;
    }
  } while(x!=5);
  freestack(&r1);
  freestackstr(&r2);
  return 0;
}
