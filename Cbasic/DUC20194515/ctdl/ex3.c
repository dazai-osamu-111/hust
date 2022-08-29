#include<stdio.h>
#define MAX 100
int maxsub(int a[], int n){
  int smax = a[0],ei = a[0], imax = 0, i, u, v;
  for(i=1;i<=n;i++){
    u = ei + a[i];
    v = a[i];
    if(u>v) ei = u;
    else ei = v;
    if(ei > smax){
    smax = ei;
    imax = i;
    }
  }
  return smax;
}
int main(){
  int a[MAX],i,n;
  printf("Nhap so phan tu: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("a[%d] = ",i+1);
    scanf("%d",&a[i]);
  }
  printf("max: %d\n", maxsub(a, n));
  return 0;
}
