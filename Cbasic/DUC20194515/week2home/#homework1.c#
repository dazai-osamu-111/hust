#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int main( int argc, char *argv[]){
  if(argc != 4){
    printf("error syntax");
    printf(" TRUE: sde a b c");
  }
  double  x[MAX],a,b,c,delta;
  a = atof(argv[1]);
  b = atof(argv[2]);
  c = atof(argv[3]);
  delta= b*b - 4*a*c;
  if(delta>0){
    x[0] = ((-b + sqrt(delta))/(2*a));
    x[1] = ((-b - sqrt(delta))/(2*a));
    printf("return:\n");
    printf("x1 = %.2f\n",x[0]);
    printf("x2 = %.2f\n",x[1]);
  }
  if(delta < 0) printf("return: can not solve\n");
  if(delta == 0){
    x[0]= -b/(2*a);
    printf("Return: x1 = x2 = %.2f\n", x[0]);
  }
  return 0;
}
