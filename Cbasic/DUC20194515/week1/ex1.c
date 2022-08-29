#include<stdio.h>
#include<math.h>
#define MAX 100

int main(){
  int a[MAX], i, n, sum=0,min;
  double avg, mindiff=1000;
  printf("Nhap so phan tu cua mang:");
  scanf("%d",&n);
  for(i=0;i<n;++i){
    printf("Phan tu thu %d: ", i+1);
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;++i){
    sum+=a[i];
  }
  avg=(double)sum/n;
  printf("Gia tri trung binh la: %.2lf\n", avg);
  for(i=0;i<n;i++){
    if(fabs(a[i]-avg)< mindiff){
      mindiff=fabs(a[i]-avg);
      min=a[i];
    }
  }
  printf("Mean number is %d\n",min);
  return 0;
}
