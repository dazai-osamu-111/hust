
#include<stdio.h>
int main(){
  int a[100];
  int i,j,n,k,maxsum = 0;
  printf("Nhap so phan tu :");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Phan tu %d",i+1);
    scanf("%d",&a[i]);
  }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	int sum=0;
	for(k=i;k<=j;k++)
	  sum=sum+a[k];
	    if(sum>maxsum) maxsum=sum;
      }
      
    }
    printf("Maxsum = %d",maxsum);
    return 0;
}
