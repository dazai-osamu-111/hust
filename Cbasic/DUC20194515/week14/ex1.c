#include<stdio.h>
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
int main(){
  int a[100];
  int n,i,j;
  printf("Nhap so phan tu: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Phan tu thu %d: ", i+1);
    scanf("%d", &a[i]);
  }
  insertionsort(a, n);
  printf("Mang sau khi sap xep:\n ");
  for(i=0;i<n;i++){
    printf("%d\t",a[i]);
  }
  printf("\n");
  printf("Nhap mang moi:\n ");
  printf("Nhap so phan tu: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Phan tu thu %d: ", i+1);
    scanf("%d", &a[i]);
  }
  selection(a,n);
   printf("Mang sau khi sap xep:\n ");
  for(i=0;i<n;i++){
    printf("%d\t",a[i]);
  }
  printf("\n");
  return 0;
}
