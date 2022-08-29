#include<stdio.h>
#include<time.h>
#define MAX 500000
void sequential(int a[],int x1){
  clock_t begin=clock();
  int i=0;
  while(a[i] != x1 && i<MAX)
    i++;
  if (i<MAX)
    printf("Element a[%d]\n", i);
  else
    printf("Not exist\n");
  printf("Time = %.6lf\n", ((double)(clock()-begin))/CLOCKS_PER_SEC);
  return ;
}
void sentinel(int a[], int x1){
  clock_t begin=clock();
  int i = 0;
  a[MAX]=x1;
  while(a[i] != x1)
    i++;
  if(i!=MAX)
    printf("Element a[%d]\n", i);
  else
    printf("Not exist\n");
  printf("Time = %.6lf\n", ((double)(clock()-begin))/CLOCKS_PER_SEC);
  return;
}
void binary(int a[], int x1){
  clock_t begin=clock();
  int low=0, high = MAX -1, mid;
  while(low<=high){
    mid=(low+high)/2;
    if(a[mid] == x1){
      printf("Element a[%d]", mid);
      printf("\nTime = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
      return;
    }
    else if(x1<a[mid])
      high=mid-1;
    else
      low=mid+1;
  }
  printf("Not found\n");
  printf("Time = %.6lf\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
}
int main(){
  int a[MAX+1];
  int i,x,x1;
  for(i=0;i<MAX;i++){
    a[i]=2*i+3;
  }
  do{
    printf("1. Sequential search\n"
	   "2. Sequential search using Sentinel\n"
	   "3. Binary search\n"
	   "4. exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      printf("Enter number: ");
      scanf("%d", &x1);
      sequential(a,x1);
      break;
    case 2:
      printf("Enter number: ");
      scanf("%d", &x1);
      sentinel(a,x1);
      break;
    case 3:
      printf("Enter number: ");
      scanf("%d", &x1);
      binary(a,x1);
    default: break;
    }	
  } while(x!= 4);
  return 0;
}
