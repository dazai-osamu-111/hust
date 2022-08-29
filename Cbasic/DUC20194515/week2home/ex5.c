#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int main(int argc, char *argv[]){
  FILE *fptr1,*fptr2;
  char filename1[MAX],filename2[MAX];
  if(argc != 3){
    printf("ERROR SYNTAX\N");
    printf("TRUE: mycp filefrom fileto \n");
  }
  filename1=argv[1];
  filename2=argv[2];
  if((fptr1=(filename1,"r")) == NULL){
    printf("Cannot open %s.\n",filename1);
    return 1;
  }
  if((fptr2=(filename2,"w")) == NULL){
    printf("Cannot open %s.\n",filename2);
    return 1;
  }
  while((c=fgetc(fptr1)) != EOF){
    fputc(c, fptr2);
    printf("Noi dung doc duoc");
    putchar(c);
  }
  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
