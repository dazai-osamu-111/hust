#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
  long *arr;
  arr=malloc(sizeof(long) * 2);
  arr[0]=5;
  arr[1]=10;
  printf("%d\t%d\n", &arr[0], &arr[1]);
  printf("%d\n", (int)&arr[1]-(int)&arr[0]);
}
