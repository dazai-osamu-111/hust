/* Write a program that generates more than 1 milion integer numbers. These number are in range of 40 different discrete values. */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void creatnumber(int a[],int n){
  int i;
  srand(time(0));
  for(i=0;i<n;i++){
    a[i]=rand()%40;
  }
}

void printarray(int a[], int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d\t", a[i]);
  }
  printf("\n");
  return;
}

void swap(int *a, int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
  return;
}
int partition(int a[], int low, int high){
  int i, j, pivot;
  i=low-1;
  pivot=a[high];
  for(j=low;j<high-1;j++){
    if(a[j]<a[pivot]){
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[high], &a[i+1]);
  return i+1;
}

void quicksort(int a[], int low, int high){
  int pivot;
  if(low<high){
    pivot=partition(a, low, high);
    quicksort(a, low, pivot-1); // before pivot
    quicksort(a, pivot+1, high);// after pivot
  }
  return;
}
#define MAX 1000001
int main(){
  int a[MAX];
  int i, n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);
  creatnumber(a, n);
  printarray(a, n);
  quicksort(a, 0, n-1);
  printarray(a, n);
  return 0;
}
