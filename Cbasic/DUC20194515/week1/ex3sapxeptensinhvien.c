#include<stdio.h>
#include<string.h>
#define MAX 100
char ten(char str[MAX]){
  char name[MAX];
  int i;
  for(i=strlen(str);str[i] != ' ';--i){
    strcpy(name,str[i-1]);
  }
  return name;
}
int main(){
  int *s[MAX];
  int n,i;
  printf("Nhap so sinh vien");
  scanf("%d",&n);
  for(i=0;i<n;++i){
    printf("SInh vien Thu %d, Ho va ten: ", i+1);
    fgets(*s[i],sizeof(*s[i]), stdin);
  }
}
