#include<stdio.h>
#define MAX 100
int maxleft(int a[], int low, int mid){
  int maxsum = -1000; int sum = 0, k;
  for(k=mid;k>=low;k--){
    sum=sum+a[k];
    if(sum> maxsum) maxsum=sum;
  }
  return maxsum;
}
int maxright(int a[], int  mid, int high){
  int maxsum= -1000, sum=0,k;
  for(k=mid;k<=high;k++){
    sum= sum+a[k];
    if(sum> maxsum) maxsum=sum;
  }
  return maxsum;
}
int maxsub(int a[], int low, int high){
  int mid,wl,wr,wm;
  if(low == high) return a[low];
  else{
     mid = (low+ high)/2;
     wl = maxsub(a,low,mid);
     wr = maxsub(a, mid+1,high);
     wm = maxleft(a, low, mid) + maxright(a, mid, high);
  }
  if(wl>wr && wl>wm) return wl;
  if(wr>wl && wr>wm) return wr;
  if(wm>wl && wm>wr) return wm;
}
int main(){
  int a[MAX];
  int n,i;
  printf("Nhap so phan tu: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("a[%d]: ", i+1);
    scanf("%d",&a[i]);
  }
  printf("Max = %d\n",maxsub(a,1,n));
  return 0;
}
