#include<stdio.h>
#include<stdlib.h>
#include "stacklist.h"
int main(){
  stacktype *top=NULL;
  int n,i, x;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Nhap phan tu %d: ", i+1);
    scanf("%d",&x);
    push(&top, x);
  }
  while(!empty(top)){
    printf("%4d", pop(&top));
  }
  return 0;
}
