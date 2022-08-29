#include<stdio.h>
#define MAX 100
int main(){
    int a[MAX],n,i,j,k;
    int maxsum = 0;
    printf("Nhap n: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
	printf("Nhap a[%d] ",i+1);
	scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	int sum=0;
	for(k=i;k<=j;k++)
	  sum+=a[k];
	if(sum> maxsum) maxsum = sum;
      }
    }
    printf("maxsum: %d\n",maxsum);
    return 0;
}
