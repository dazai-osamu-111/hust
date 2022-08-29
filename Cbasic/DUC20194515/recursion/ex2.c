#include<stdio.h>
#include<string.h>
int palindrome(char a[], int x1, int x2){
  if(x1==x2) return 1;
  
  if(a[x1]!=a[x2]) return 0;
  if(x1<x2) return palindrome(a,x1+1, x2-1);
  return 1;
}
int main(){
  char a[100];
  printf("Enter string: ");
  scanf("%s", a);
  if(palindrome(a, 0, strlen(a)-1)) printf("True\n");
  else printf("Fail\n");
  return 0;
}
