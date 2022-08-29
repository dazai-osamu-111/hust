#include<stdio.h>
#define MAX 100
int check(int a[], int m, int b[], int n){
  int i;
  if(m != n) return 0; else{
    for(i=0;i<n;i++){
      if(a[i] != b[i]){
	for(i=0;i<n/2;i++){
	  if(a[i] != a[n-1-i] || b[i] != b[n-1-i]) return 0;
	  return -1;
	} ;
      } else return 1;
    }  
  }
}
int main(){
  int a[MAX], b[MAX], m, n, i;
  printf("nhap so phan tu mang 1: ");
  scanf("%d",&m);
  printf("Nhap vao lan luot %d cac phan tu cua mang 1:\n",m);
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }
  printf("Nhap so phan tu mang 2: ");
  scanf("%d",&n);
  printf("Nhap vao lan luot %d cac phan tu cua mang 2:\n",n);
  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  printf("Ham tra ve: %d\n",check(a,m,b,n));
  return 0;
}
