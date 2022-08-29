#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int BinarySearch(void *arr, size_t num, size_t size, int l, int r, void *x, int (*compare)(void* a, void *b))
{
  if(r<l)
    return -1;
  int mid=l+(r-l)/2;
  int result = compare(x, (char*)arr+size*mid);
  if(result==0)
    return mid;
  else if(result < 0)
    return BinarySearch(arr, num, size, l, mid-1, x, compare);
  else
    return BinarySearch(arr, num,size , mid+1, r, x, compare);
}

int int_compare(void  *x, void  *y){
  int m=*((int*)x);
  int n=*((int*)y);
  return m-n;
}

void swap(void *a, void *b, size_t size){
  void *tmp=malloc(size);
  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);
  return;
}
void exch(void *arr, int size, int i, int j){
  swap(arr+ size*i, arr + size*j, size);
  return;
}

void sort(void* a, int size, int l, int r,
	  int (*compare)(void*, void*)) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (compare((char*)a+(++i)*size, (char*)a+r*size) < 0 );
      while (compare((char*)a+r*size, (char*)a+(--j)*size) < 0 )
	if (j == l) break;
      if (i >= j) break;
      exch(a, size, i, j);
      if (compare((char*)a+i*size, (char*)a+r*size)==0)
	exch(a, size, ++p, i);
      if (compare((char*)a+j*size, (char*)a+r*size)==0)
	exch(a, size, --q, j);
    }
  exch(a, size, i, r);
  j = i - 1;
  i = i + 1;
  for (int k = l ; k <= p; k++) exch(a, size, k, j--);
  for (int k = r-1; k >= q; k--) exch(a, size, k, i++);
  sort(a, size, l, j, compare);
  sort(a, size, i, r, compare);
}
void creatarray(int a[], int n){
  srand(time(NULL));
  for(int i=0;i<n;i++){
    a[i]=rand()%10+1;
  }
  return;
}

void printarray(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d\t", a[i]);
    }
  printf("\n");
  return;
}
int main(){
  int *a, x;
  int n,i, tmp;
  printf("Enter total numbers in array: ");
  scanf("%d", &n);
  a=malloc(sizeof(int) * n);
  creatarray(a, n);
  printarray(a, n);
  sort(a, sizeof(int), 0, n-1, int_compare);
  printarray(a, n);
  printf("Enter element you want to find: ");
  scanf("%d", &x);
  tmp=BinarySearch(a, n, sizeof(int),0, n-1, &x,int_compare );
  if(tmp==-1){
    printf("Not found\n");
  } else{
    printf("BinaruSearch return %d\n", tmp);
  }
  return 0;
}
