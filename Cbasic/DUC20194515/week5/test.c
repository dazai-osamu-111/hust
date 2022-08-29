#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int main(int argc, char *argv[]){
  if(argc!=2){
    printf("ERROR!\n");
    return 1;
  }
  FILE *f1;
  int irc;
  char a[MAX];
  f1=fopen(argv[1],"w+b");
  if(f1==NULL){
    printf("Cannot open file\n");
    return 1;
  }
  printf("Nhap chuoi: ");
  gets(a);
  fwrite(a,sizeof(char),MAX,f1);

  fclose(f1);
  return 0;
}
