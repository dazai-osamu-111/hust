#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,n, count1=0, count2=0;
  printf("nhap so nguyen n:");
  scanf("%d",&n);
  int *a=(int*)malloc(sizeof(int) * n);
  for(i=0;i<n;i++){
    printf("phan tu %d: ", i+1);
    scanf("%d", a+i);
  }
  for(i=0;i<n-1;i++){
    if(*(a+i+1)>*(a+i)) count1++;
    if(*(a+i+1)<*(a+i)) count2++;
  }
  if(count1==(n-1)|| count2==(n-1)) printf(" tra ve: YES"); else printf("tra ve: NO");
  return 0;
}
