#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("Test function.\n");
  int *a;
  a = (int*)malloc(sizeof(int) * 50);
  for(int i=0;i<50;i++){
    a[i]=i;
  }
  printf("%d\n", a[15]);
  return 0;
}
