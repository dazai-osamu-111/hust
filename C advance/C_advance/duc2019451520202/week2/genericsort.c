#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int compare(int x, int y){
  if(x==y) return 0;
  return x > y ? 1: -1;
}

void exch(int a[], int i, int j){
  int tmp=a[i];
  a[i]=a[j];
  a[j]=tmp;
  return;
}

void printarray(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d\t", a[i]);
  }
  printf("\n");
  return;
}

void sort(int a[], int l, int r){
  if(r<=l) return;
  int i=l-1, j=r;
  int p=l-1, q=r;
  while(1){
    while(compare(a[++i],a[r])==-1);
    while(compare(a[r] ,a[--j])==-1) if(j==l) break;
    if(i>=j) break;
    exch(a, i, j);
    if(compare(a[i],a[r])==0) exch(a, ++p, i);
    if(compare(a[j], a[r])==0) exch(a, --q, j);
  }
  exch(a, i, r);
  j = i-1;
  i = i+1;
  for(int k = l; k<=p; k++) exch(a, k, j--);
  for(int k = r-1; k >= q; k--) exch(a, k, i++);
  sort(a, l, j);
  sort(a, i, r);
}

int main(){
  int *a;
  int n,i;
  printf("Enter the total number integer: ");
  scanf("%d", &n);
  a=(int*)malloc(n* sizeof(int));
  srand(time(0));
  for(i=0;i<n;i++){
    a[i]=rand()%40;
  }
  int j=2;
  i=1;
  printarray(a, n);
  sort(a, 0, n-1);
  printf("After sort\n");
  printarray(a,n);
  return 0;
}
