#include<stdio.h>
#include<math.h>
#define MAX 100
int equal(int a[], int b[], int m, int n){
  int i;
  if(m!=n) return 0; else{
    for(i=0;i<m;++i){
      if(a[i]!=b[i]) return 0;
    }
  }
  return 1;
}
int symetric(int a[], int m){
  int i;
  for(i=0;i<m/2;++i,--m){
    if(a[i]!=a[m]) return 0;
  }
  return 1;
  
}

int check(int a[], int b[], int m, int n){
  if(equal(a,b,m,n)==1 && symetric(a,m)==0 && symetric(b,n)==0) return 1;
  if(equal(a,b,m,n)==0 && symetric(a,m)==0 && symetric(b,n)==0) return -1;
  if(symetric(a,n)==1 && symetric(b,n)==1) return 0;
}
int main(){
  int a[MAX], b[MAX],m, n,i;
  printf("mang 1, nhap so phan tu:");
  scanf("%d",&m);
  for(i=0;i<m;++i){
    printf("Phan tu %d: ",i+1);
    scanf("%d",&a[i]);
  }
  printf("mang 2, nhap so phan tu: ");
  scanf("%d", &n);
  for(i=0;i<n;++i){
    printf("Phan tu thu %d: ",i+1);
    scanf("%d",&b[i]); 
  }
  printf("Ket qua ham tra ve: %d\n", check(a,b,m,n));
  return 0;
}
