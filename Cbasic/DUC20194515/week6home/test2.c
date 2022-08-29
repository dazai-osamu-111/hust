#include<stdio.h>
#include<stdlib.h>
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
int main(){
  FILE *f1;
  int irc=0;
  phonedb a;
  if((f1=fopen("PhoneDB.dat","rb"))==NULL){
    printf("Cannot open file\n");
    return 1;
  }
  while( fread(&a,sizeof(phonedb),1,f1) != 0){
    irc++;
    printf("%-30s%-10s%-10s%s\n",a.model,a.space,a.ssize,a.price);
      }
  printf("%d\n",irc);
  return 0;
}
