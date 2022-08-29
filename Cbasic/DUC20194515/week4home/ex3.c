#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int main(int argc,char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: ex3 <filename1> <filename2>");
    exit(1);
  }
  FILE *f1,*f2;
  char buff[MAX];
  if((f1= fopen(argv[1],"r")) == NULL){
    printf("Cannot open %s\n",argv[1]);
    return 1;
  }
  if((f2 = fopen(argv[2],"w")) == NULL){
    printf("Cannot open %s\n",argv[2]);
    return 1;
  }
  while(fread(buff, sizeof(char), MAX, f1)){
    printf("%s", buff);
    fwrite(buff, sizeof(char), MAX, f2);
  }
  fclose(f1);
  fclose(f2);
  return 0;
}
