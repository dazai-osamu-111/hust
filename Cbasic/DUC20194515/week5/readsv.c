#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
  int no;
  int Student_number;
  char First_name[30];
  char phone_number[15];
  double score;
} student;
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("ERROR SYNTAX.\n");
    printf("TRUE SYNTAX: readst <filename>\n");
    return 1;
  }
  FILE *fin;
  student a[100];
  int i,irc;
  if((fin = fopen(argv[1], "r")) == NULL){
    printf("Cannot open %s\n", argv[1]);
    return 1; 
  }
  irc=fread(a, sizeof(student), 13, fin);
  for(i=0;i<irc;i++){
    printf("%-5d%-10d%-24s%-15s%.2lf\n",(a+i)->no, (a+i)->Student_number, (a+i)->First_name, (a+i)->phone_number, (a+i)->score);
  }
  fclose(fin);
  return 0;
}
  
