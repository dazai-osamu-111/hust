#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char *my_cat(char *s1, char *s2){
  int i,len1, len2;
  len1 = strlen(s1);
  len2 = strlen(s2);
  char *result;
  result =(char*)malloc(len1+len2+1);
  if(result == NULL){
    printf("Allocation fail! Check memory\n");
    return NULL;
  }
  for(i=0;i<len1;i++){
    result[i] = s1[i];
  }
  for(i=0;i<len2;i++){
    result[i+len1] = s2[i];
  }
  result[len1+len2+1] ='\0';
  return result;
}
int main(){
  char s1[MAX], s2[MAX], *s3;
  printf("Nhap chuoi thu nhat: ");
  gets(s1);
  printf("Nhap chuoi thu 2: ");
  gets(s2);
  s3 =  my_cat(s1, s2);
  printf("ket qua: %s\n",s3);
  free(s3);
  return 0;
}

