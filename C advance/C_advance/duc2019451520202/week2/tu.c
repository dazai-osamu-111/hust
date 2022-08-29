#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void exch(void *arr, int size, int i, int j){
  char *tmp=malloc(sizeof(char) * size);
  char *region1= (char*)arr+ size* i;
  char *region2= (char*)arr + size*j;
  
  for(int i=0;i< size;i++){
    tmp[i] = region1[i];
    region1[i] = region2[i];
    region2[i] = tmp[i];
  }
  return;
}

int main(){
  int arr[2];
  arr[0]=1;
  arr[1]=5;
  exch(arr, sizeof(int), 0, 1);
}
