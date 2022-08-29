#include<stdio.h>
#include<string.h>
#define MAX 81
void LineReadWrite(FILE *fin, FILE *fout){
  char buff[MAX];
  int len;
  while(fgets(buff, MAX, fin) != NULL){
    len = strlen(buff) - 1;
    fprintf(fout, "%d %s", len, buff);
    printf("%s", buff);
  }
}
int main(int argc, char *argv[]){
  if(argc != 3){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: name <file1> <file2>\n");
    return 1;
  }
  FILE *fin, *fout;
  if( (fin=fopen(argv[1],"r")) == NULL || (fout=fopen(argv[2],"w")) == NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  LineReadWrite(fin, fout);
  return 0;
}
