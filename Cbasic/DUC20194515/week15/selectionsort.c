#include<stdio.h>
void selectionsort(int a[], int n){
  int i,j,min,tmp;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<=n;j++){
      if(a[j]<a[min]){
	min=j;
	tmp=a[i];
	a[i]=a[min];
	a[min]=tmp;
      }
    }
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
  selectionsort(a, n);
  printf("Array after sorted\n");
  for(i=0;i<n;i++){
    printf("%d\t", a[i]);
  }
  printf("\n");
  return 0;
}
