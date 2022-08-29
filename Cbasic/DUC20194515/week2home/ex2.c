#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int main(int argc, char *argv[]){
  int n,i;
  char c[MAX];
  n = atoi(argv[2]);
  strcpy(c,argv[1]);
  for(i=0;i<n;i++){
    printf("%s",c);
  }
  printf("\n");
return 0;
}
