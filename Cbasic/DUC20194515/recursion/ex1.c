#include<stdio.h>
int digit(int n){
  if(n/10 == 0) return 1;
  else return 1+ digit(n/10);
}
int sum(int n){
  if(n/10==0) return n%10;
  else return n%10+ sum(n/10);
}
int fibonacci(int n){
  if(n==0) return 0;
  else if(n==1) return 1;
  return fibonacci(n-1)+ fibonacci(n-2);
}
int main(){
  long int n,i;
  printf("Enter N: ");
  scanf("%ld", &n);
  printf("Number of digits: %d\n", digit(n));
  printf("Sum: %d\n", sum(n));
  for(i=0;i<n;i++){
    printf("%d\t", fibonacci(i));
  }
  return 0;}
  
