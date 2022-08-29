#include<stdio.h>
int main(int a, char *b[]){
  FILE *f;
  f=fopen(b[1],"r+");
  if(f == NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  fputs("gangbare", f);
  return 0;
}
