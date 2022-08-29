#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#include "stacklist.h"
stacktype *add(stacktype *r1, stacktype *r2){
  stacktype *r3=NULL;
  int  carry=0, x1,x2,x3;
  while(!empty(r1) && !empty(r2)){
    x1 = pop(&r1)-'0';
    x2 = pop(&r2)-'0';
    x3 = x1+x2;
    if(x3+carry>9){
      push(&r3,x3-10+carry);
      carry=1;
    } else{
      push(&r3, x3+carry);
      carry=0;
    }
  }
  while(!empty(r1)){
    x3=pop(&r1)-'0';
    if(x3+carry>9){
      push(&r3,x3-10+carry);
      carry=1;
    } else{
      push(&r3, x3+carry);
      carry=0;
    }
  }
  while(!empty(r2)){
    x3=pop(&r2)-'0';
    if(x3+carry>9){
      push(&r3,x3-10+carry);
      carry=1;
    } else{
      push(&r3, x3+carry);
      carry=0;
    }
  }
  return r3;
}
stacktype *substract(stacktype *r1, stacktype *r2){
  stacktype *r3=NULL;
  int carry=0,x1,x2,x3;
  while(!empty(r1) && !empty(r2)){
    x1 = pop(&r1)-'0';
    x2 = pop(&r2)-'0';
    x3 = x1-x2;
    if(x3+carry<0){
      push(&r3,x3+10+carry);
      carry=-1;
    } else{
      push(&r3, x3+carry);
      carry=0;
    }
  }
  while(!empty(r1)){
    x3=pop(&r1)-'0';
    if(x3+carry<0){
      push(&r3,x3+10+carry);
      carry=1;
    } else{
      push(&r3, x3+carry);
      carry=0;
    }
  }
  return r3;
}
int compare(stacktype *r1,stacktype *r2){
  stacktype *r3=NULL,*r4=NULL;
  int x1=0,x2=0;
  int y1,y2,y3, count=0;
  while(!empty(r1)){
    push(&r3,pop(&r1));
    x1++;
  }
  while(!empty(r2)){
    push(&r4,pop(&r2));
    x2++;
    
  }
  if(x1>x2) return 1;
  if(x1<x2) return -1;
  if(x1==x2){
    while(!empty(r3)){
      y1=pop(&r3)-'0';
      y2=pop(&r4)-'0';
      if(y1>y2) return 1;
      if(y1<y2) return -1;
      if(y1==y2) count++;
    }
  }
  if(count==x1){
    return 0;
  }
}
int main(){
  int i, sum, x,x1,c;
  char s1[MAX],s2[MAX];
  stacktype *r1=NULL, *r2=NULL, *r3=NULL;
  do{
    printf("***********MENU***********\n");
    printf("1. Add very large integer numbers\n");
    printf("2. Subtract very large integer numbers\n");
    printf("0. Exit\n");
    printf("You choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      r1=NULL;r2=NULL;r3=NULL;
      printf("Enter first number: ");
      scanf("%s", s1);
      printf("Enter second number: ");
      scanf("%s", s2);
      for(i=0;s1[i]!='\0';i++){
	push(&r1,s1[i]);
      }
      for(i=0;s2[i]!='\0';i++){
	push(&r2, s2[i]);
      }
      r3=add(r1,r2);
      printf("Sum = ");
      while(!empty(r3)){
	printf("%d", pop(&r3));
      }
      printf("\n");
      break;
    case 2:
       printf("Enter first number: ");
      scanf("%s", s1);
      printf("Enter second number: ");
      scanf("%s", s2);
      r1=NULL, r2=NULL, r3=NULL;
      for(i=0;s1[i]!='\0';i++){
	push(&r1,s1[i]);
      }
      for(i=0;s2[i]!='\0';i++){
	push(&r2, s2[i]);
      }
      c=compare(r1,r2);
      r1=NULL, r2=NULL, r3=NULL;
      for(i=0;s1[i]!='\0';i++){
	push(&r1,s1[i]);
      }
      for(i=0;s2[i]!='\0';i++){
	push(&r2, s2[i]);
      }
      if(c==1||c==0){
	r3=substract(r1,r2);
	printf("Sum = ");
	while(!empty(r3)){
	  printf("%d", pop(&r3));
	}
	printf("\n");
      }
      if(c==-1){
	r3=substract(r2,r1);
	printf("Sum = ");
	printf("-");
	while(!empty(r3)){
	  printf("%d", pop(&r3));
	}
	printf("\n");
      }
      break;
    default: break;
    }
  } while(x!=0);
  freestack(&r3);
  return 0;
    
}
