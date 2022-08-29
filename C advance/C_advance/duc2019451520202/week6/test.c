#include<stdio.h>
#include<string.h>
int main(){
  int i;
  FILE *fptr = fopen("test.txt", "r");
  char A[100],c;
  for(i=0;i<3;i++){
    fscanf(fptr, "%[^=]%*c", A);
    printf("%s: ", A);
    while(1){
      fscanf(fptr, "%s", A);
      c= fgetc(fptr);
      printf("%s ", A);
      if(c=='\n') {
	printf("\n");
	break;
      }
    }
  }
}
