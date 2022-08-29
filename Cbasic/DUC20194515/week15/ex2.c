#include<stdio.h>
#include<stdio.h>
#include<time.h>
#define MIN 1000
#define MAX 100
int random(int min, int max){
  return min+rand()%(max +1 -min);
}
typedef int element;
void adjust(element list[], int root, int n){
  int child, rootkey;
  element temp;
  temp=list[root];
  rootkey=list[root];
  child=2*root;
  while (child <= n){
    if((child < n) && list[child] < list[child+1]) child ++;
    if(rootkey>list[child]) break;
    else{
      list[child/2] = list[child];
      child *= 2;
    }
  }
  list[child/2] =temp;
}
void heapsort(element list[], int n){
  int i,j;
  element temp;
  for(i=n/2;i>0;i--) adjust(list, i, n);
  for(i=n-1;i>0;i--){
    temp=list[1];
    list[1]=list[i+1];
    list[i+1]=temp;
    adjust(list, 1, i);
  }
}
typedef int element;
void insertionsort(element list[], int n){
  int i,j;
  element next;
  for(i=1;i<n;i++){
    next=list[i];
    for(j=i-1;j>=0 && next < list[i];j--)
      list[j+1] = list[j];
    list[j+1] = next;
  }
}
void selection(element a[], int n){
  int i,j,min, tmp;
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<= n-1;j++){
      if(a[j] < a[min])
	min = j;
    }
    tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
  }
}
void quicksort(element list[], int left, int right){
  int pivot, i, j;
  element temp;
  if(left < right){
    i = left;
    j = right +1;
    pivot = list[left];
    do{
      do i++; while(list[i] < pivot);
      do j--; while(list[j]>pivot);
      if(i<j){
	temp=list[i];
	list[i]=list[j];
	list[j]=temp;
      }
    } while(i<j);
    temp=list[i];
    list[i]=list[j];
    list[j]=temp;
    quicksort(list, left, j-1);
    quicksort(list, j+1,right);
  }
}
void merge(int a[],int b[],int e[] ){
  int i,j,k;
  i=j=k=0;
  while(k<MAX){
    if(a[i]<b[j]){
      e[k]=a[i];
      i++;
    }else{
      e[k]=b[j];
      j++;
    }
    k++;
  }
}
void mergesort(element list[], int n){
  int i;
  int e[MAX];
  int a[MAX],b[MAX];
  if(n<MIN) insertionsort(list, n);
  else{
    for(i=0;i<n/2;i++){
      a[i]=list[i];
    }
    for(i=n/2;i<n;i++){
      a[i]=list[i];
    }
    mergesort(a,n/2);
    mergesort(b,n/2);
  }
  merge(a,b,e);
}
int main(){
  
  int a[500000];
  int n,i,j;
  //clock_t tic = clock();
  printf("Nhap so phan tu: ");
  scanf("%d", &n);
  for(i=1;i<n+1;i++){
    a[i]=random(0, 20000);
  }
  mergesort(a,n);
}
  /*heapsort(a, n);
  printf("thoi gian chay heapsort:\n");
  clock_t toc=clock();
  printf("Elapsed: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);

  
  tic = clock();
  for(i=1;i<n+1;i++){
    a[i]=random(0, 20000);
  }
  insertionsort(a, n);
  printf("thoi gian chay insertionsort:\n");
  toc=clock();
  printf("Elapsed: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);

  
  
  tic=clock();
  for(i=1;i<n+1;i++){
    a[i]=random(0, 20000);
  }
  quicksort(a,0,n);
  printf("thoi gian chay quicksort:\n");
  toc=clock();
  printf("Elapsed: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);


  tic = clock();
  for(i=1;i<n+1;i++){
    a[i]=random(0, 20000);
  }
  selection(a, n);
  printf("thoi gian chay selection:\n");
  toc=clock();
  printf("Elapsed: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
  
  tic = clock();
  return 0;
  }*/

