#include<stdio.h>
typedef struct{
  char name[25];
  char date[20];
  char hometown[20];
} sinhvien;
int main(){
  FILE *fptr;
  sinhvien a[20];
  fptr=fopen("dssv.txt", "w");
  int i;
  for(i=0;i<20;i++){
    printf("Ho va ten: ");
    scanf("%s", a[i].name);
    printf("ngay sinh: ");
    scanf("%s", a[i].date);
    printf("Que quan: ");
    scanf("%s", a[i].hometown);
  }
  for(i=0;i<20;i++){
    fprintf(fptr, "%-25s%-20s%-20s\n", a[i].name,a[i].date,a[i].hometown); 
  }
  return 0;
}
