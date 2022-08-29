#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*  argv[]){
  double height,width;
  if(argc != 3){
    printf("error syntax\n");
    return 1;
  }
  height = atof(argv[1]);
  width = atof(argv[2]);
  printf("Area: %.2f\n", height*width);
  printf("perimeter: %.2f\n", 2*(height+width));
  return 0;
}
