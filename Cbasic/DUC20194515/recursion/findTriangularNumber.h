#include<stdio.h>
int triangle(int n){
  int total = 0;
  while(n>0){
    total = total + n;
    --n;
  }
  return total;
}
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("%d\n", triangle(n));
  return 0;
}
