#include<stdio.h>
int main(){
  int x;
  int x1, x2;
  do{
    printf("Simple Menu Driven Program\n"
	   "_____________________________\n"
	   "1. Sum\n"
	   "2. Subtract\n"
	   "3. Multiply\n"
	   "4. Divide\n"
	   "5. Exit\n"
	   "Select option: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      printf("Enter two number: ");
      scanf("%d%*c%d", &x1, &x2);
      printf("Sum: %d\n", x1+x2);
      break;
    case 2:
      printf("Enter two number: ");
      scanf("%d%*c%d", &x1, &x2);
      printf("Subtraction: %d\n", x1-x2);
      break;
    case 3:
      printf("Enter two number: ");
      scanf("%d%*c%d", &x1, &x2);
      printf("Multiplication: %d\n", x1*x2);
      break;
    case 4:
      printf("Enter two number: ");
      scanf("%d%*c%d", &x1, &x2);
      if(x2==0){
	printf("X2 = 0, cannot divide.\n");
	break;
      }
      printf("Division: %d\n", x1/x2);
      break;
    }
  }while(x!=5);
  return 0;
}
