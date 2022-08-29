#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 500
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Error!\n");
    printf("True syntax: fread <filename>\n");
    return 1;
  }
  FILE *fin;
  if((fin=fopen(argv[1],"rb")) == NULL){
    printf("Cannot open file!\n");
    return 1;
  }
 
  phonedb *s=(phonedb*)malloc(sizeof(phonedb));
  while(!feof(fin)){
    fread(s, sizeof(phonedb), 1, fin);
    printf("%-30s%-10s%-10s%s\n",s->model,s->space,s->ssize,s->price);
  }
  return 0;
}
