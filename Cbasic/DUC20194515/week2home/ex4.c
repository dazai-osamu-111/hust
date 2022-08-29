#include<stdio.h>
int main(){
  FILE* fin,fout;
  fin=fopen("lab1.txt","r");
  fout=fopen("lab1w.txt","w");
  if(fin==NULL || fout == NULL){
    printf("cannot open file.\n");
    return 0;
  }
  
}
