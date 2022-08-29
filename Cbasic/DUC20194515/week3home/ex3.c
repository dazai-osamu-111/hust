#include<stdio.h>
#define MAX 81
int main(int argc, char *argv[]){
  if( argc != 4){
    printf("ERROR SYNTAX!\n");
    printf("TRUE SYNTAX: name <file1> <file2> <file3>\n");
    return 1;
  }
  char s1[MAX], s2[MAX];
  FILE *f1,*f2,*f3;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"r");
  f3=fopen(argv[3],"w");
  if(f1 == NULL || f2 == NULL || f3 == NULL){
    printf("Can not open file\n");
  }
  while(fgets(s1, MAX, f1) != NULL && fgets(s2, MAX, f2) != NULL){
    fputs(s1, f3);
    fputs(s2, f3);
  }
  while(fgets(s1, MAX, f1) != NULL) fputs(s1, f3);
  while(fgets(s2, MAX,f2) != NULL) fputs(s2, f3);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 0;
}
