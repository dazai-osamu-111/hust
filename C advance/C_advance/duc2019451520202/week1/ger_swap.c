#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a, int *b, size_t size){
  void *tmp=malloc( sizeof(char) *size);
  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);
  return;
}
int main(){
  int a, b;
  printf("Enter a, b: ");
  scanf("%d%d", &a, &b);
  swap(&a, &b, sizeof(int));
  
  printf("%d\t%d", a, b);
  printf("\n");
  return 0;
}
