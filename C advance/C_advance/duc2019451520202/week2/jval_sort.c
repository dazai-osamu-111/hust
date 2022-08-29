#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef union{
  int i;
  long l;
  float f;
  double d;
  void *v;
  char *s;
  char c;
} Jval;

Jval new_jval_i(int i){ Jval j; j.i=i; return j;}
Jval new_jval_l(long l){ Jval j; j.l=l; return j;}
Jval new_jval_f(float f){ Jval j; j.f=f; return j;}
Jval new_jval_d(double d){ Jval j; j.d=d; return j;}
Jval new_jval_v(void *v){ Jval j; j.v = v; return j;}

int jval_i(Jval j){ return j.i;}
int jval_l(Jval j){ return j.l;}
int jval_f(Jval j){ return j.f;}
int jval_d(Jval j){ return j.d;}
int *jval_v(Jval j){ return j.v;}

int int_compare(Jval *a, Jval*b){
  return jval_i(*a) - jval_i(*b);
}

void swap(Jval *a, Jval *b){
  Jval tmp=*a;
  *a=*b;
  *b=tmp;
  return;
}
void exch(Jval *arr, int i, int j){
  swap(arr+i, arr + j);
  return;
}

void sort_gen(Jval a[], int l, int r,
	  int (*compare)(Jval*, Jval*)) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (compare(&a[++i], &a[r]) < 0 );
      while (compare(&a[r], &a[--j]) < 0 )
	if (j == l) break;
      if (i >= j) break;
      exch(a, i, j);
      if (compare(&a[i], &a[r])==0)
	exch(a, ++p, i);
      if (compare(&a[j], &a[r])==0)
	exch(a, --q, j);
    }
  exch(a, i, r);
  j = i - 1;
  i = i + 1;
  for (int k = l ; k <= p; k++) exch(a, k, j--);
  for (int k = r-1; k >= q; k--) exch(a, k, i++);
  sort_gen(a, l, j, compare);
  sort_gen(a, i, r, compare);
}


void print_i(Jval a[], int n){
  for(int i=0;i<n;i++){
    printf("%d\t", jval_i(a[i]));
  }
  printf("\n");
}

int Search_gen(Jval a[], int l, int r, Jval item, int (*compare)(Jval*, Jval*)){
  if(r<l)
    return -1;
  int mid=(l+r)/2;
  int result = compare(&item, &a[mid]);
  if(result == 0)
    return mid;
  else if(result < 0)
    return Search_gen(a, l, mid-1, item, compare);
  else
    return Search_gen(a, mid+1, r, item, compare);
}
#define MAX 10
int main(){
  Jval a[MAX], tmp;
  int n,i;
  
  // printf("Enter N: ");
  //scanf("%d", &n);
  //a=malloc(n * sizeof(Jval));
  srand(time(NULL));
  for(i=0;i<MAX;i++){
    a[i].i=rand()%10 + 1;
  }
  print_i(a, MAX);
  sort_gen(a, 0, MAX-1, int_compare);
  print_i(a, MAX);
  printf("Enter number you want to find: ");
  scanf("%d", &tmp.i);
  i=Search_gen(a, 0, MAX, tmp, int_compare);
  if(i==-1){
    printf("Not found\n");
  } else{
    printf("Search_gen return %d.\n", i);
  }
  return 0;
}
