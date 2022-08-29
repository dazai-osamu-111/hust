#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
void replace_char(char *str,char c1, char c2){
  int i;
  for(i=0;*(str+i)!='\0'; i++){
    if(*(str+i)==c1){
      *(str+i)=c2;
    }
  }
}
int main(){
  char c1,c2;
  char *str=(char*)malloc(50*sizeof(char));
  printf("Nhap chuoi:");
  gets(str);
  __fpurge(stdin);
  printf("Bat dau kiem tra ham:\n");
  printf("nhap c1: ");
  scanf("%c",&c1);
  __fpurge(stdin);
  printf("Nhap c2: ");
  scanf("%c", &c2);
  replace_char(str,c1,c2);
  printf("Chuoi moi: ");
  printf("%s\n", str);
  return 0;
}
