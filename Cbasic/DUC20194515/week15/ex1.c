#include<stdio.h>
void insertsionsort(int a[], int n){
  int i,j;
  int next;
  for(i=1;i<n;i++){
    next=a[i];
    for(j=i-1;j>=0 && next<a[j];j--)
      a[j+1]=a[j];
    a[j+1]=next;
  } 
}
int main(){
  int a[100];
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  insertsionsort(a, n);
  printf("Array after sorted\n");
  for(i=0;i<n;i++){
    printf("%d\t", a[i]);
  }
  printf("\n");
  return 0;
}
