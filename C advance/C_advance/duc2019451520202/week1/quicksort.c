/* Write a program that generates more than 1 milion integer numbers. These number are in range of 40 different discrete values. */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void creatarray(int *a,int size){
  int i;
  a=malloc(size* sizeof(int));
  srand(time(NULL));
  for(i=0;i<n;i++){
    a[i]=rand()%10+1;
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
  for(j=low;j<=high-1;j++){
    if(a[j]<pivot){
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

void exch(int a[], int i, int j){
  int tmp=a[i];
  a[i]=a[j];
  a[j]=tmp;
  return;
} 

void sort(int a[], int l, int r) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (a[++i] < a[r]);
      while (a[r] < a[--j]) if (j == l) break;
      if (i >= j) break;
      exch(a, i, j);
      if (a[i]==a[r]) exch(a, ++p, i);
      if (a[j]==a[r]) exch(a, --q, j);
    }
  exch(a, i, r);
  j = i - 1;
  i = i + 1;
  for (int k = l ; k <= p; k++) exch(a, k, j--);
  for (int k = r-1; k >= q; k--) exch(a, k, i++);
  sort(a, l, j);
  sort(a, i, r);
}
#define SMALL_NUMBER 20
#define BIG_NUMBER 10000000

int main(){
  int *a;
  int i, n;
  clock_t begin, end;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  begin=clock();
  creatnumber(a, n);
  //printarray(a, n);
  quicksort(a, 0, n-1);
  //printarray(a, n);
  end=clock();
  printf("Time when use quicksort is: %f\n", (double)(end-begin)/CLOCKS_PER_SEC);
  
  begin=clock();
  creatnumber(a, n);
  sort(a, 0, n-1);
  //printarray(a, n);
  end=clock();
  printf("Time when use 3-way quicksort is: %f\n", (double)(end-begin)/CLOCKS_PER_SEC);

  return 0;
}
