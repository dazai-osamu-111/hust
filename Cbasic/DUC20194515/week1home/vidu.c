#include<stdio.h>
#include<string.h>
#include<stdio_ext.h> 
#define MAX 100

void  ten(char *A,char *B){
  int i;
  for(i=strlen(A);A[i] !=' ';--i){
    strcpy(B,&A[i]);
  }
  return;
}
void doicho(char *A, char *B){
  char t[MAX];
  strcpy(t,A);
  strcpy(A,B);
  strcpy(B,t);
  return;
}
int main(){
  int n,i,j;
  char A[MAX][MAX], B[MAX][MAX];
  printf("Nhap so sinh vien:");
  scanf("%d",&n);
  __fpurge(stdin);
  for(i=0;i<n;i++){
    printf("Sinh vien %d: ",i+1);
    fgets(A[i],sizeof(A[i]),stdin);
  } 
  for(i=0;i<n;i++){
    ten(A[i],B[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(strcmp(B[j],B[i])<0){
	doicho(B[i],B[j]);
	doicho(A[i],A[j]);
      }
    }
  }
  printf("Danh sach sinh vien da duoc sx:\n");
  for(i=0;i<n;i++){
    puts(A[i]);
    printf("\n");
  }
  return 0;
}
