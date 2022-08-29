#include<stdio.h>
int findGCD(int m, int n){
  if(m==n) return m;
  if(m<n) return findGCD(n,m);
  if(m>n) return findGCD(m-n,n);
}
int findLCM(int m, int n){
  static  int temp = 1;
  printf("%d\t", temp);
  // static variable is initialized only once for each function call
  if(temp%m == 0 && temp % n ==0){
    return temp;
  }
  else
    {
      temp++;
      findLCM(m,n);
    }
}
int main(){
  int x,y;
  printf("Enter x, y\n");
  scanf("%d",&x);
  scanf("%d",&y);
  printf("GCD is %d\n", findGCD(x, y));
  printf("LCM is %d\n", findLCM(x, y));
  return 0;
}
