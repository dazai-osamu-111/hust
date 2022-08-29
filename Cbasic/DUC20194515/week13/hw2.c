#include<stdio.h>
#include<string.h>
typedef struct{
  char firstname[10];
  char midname[10];
  char lastname[10];
} tensv;
int compare(tensv s1, tensv s2){
  if(strcmp(s1.firstname,s2.firstname)>0) return 1;
  if(strcmp(s1.firstname,s2.firstname)<0) return -1;
  if(strcmp(s1.firstname,s2.firstname)==0){
    if(strcmp(s1.midname,s2.midname)>0) return 1;
    if(strcmp(s1.midname,s2.midname)<0) return -1;
    if(strcmp(s1.midname,s2.midname)==0){
      if(strcmp(s1.lastname,s2.lastname)>0) return 1;
      if(strcmp(s1.lastname,s2.lastname)<0) return -1;
      if(strcmp(s1.lastname,s2.lastname)==0) return 0;
    }
  }
}
void inten(tensv a){
  printf("%s %s %s\n", a.lastname,a.midname,a.firstname);
  return;
}
typedef struct{
  int  stt;
  tensv ten;
  char mssv[20];
  char sdt[20];
} sinhvien;
typedef sinhvien element;
#include "GenSBTree string.h"
int main(){
  treetype T, subT;
  FILE *fptr;
  sinhvien a[20];
  tensv x;
  fptr=fopen("dssv.txt", "r+");
  if(fptr==NULL){
    printf("cannot open file.\n");
    return 1;
  }
  int i=0, count=0;
  
  while((fscanf(fptr, "%d%s%s%s%s%s", &a[i].stt,a[i].mssv,a[i].ten.lastname,a[i].ten.midname,a[i].ten.firstname,a[i].sdt))!=EOF){
      i++;
      count++;
    }
  for(i=0;i<count;i++){
    printf( "%-10d%-20s%s %s %s\t\t%s\n", a[i].stt,a[i].mssv,a[i].ten.lastname,a[i].ten.midname,a[i].ten.firstname,a[i].sdt); 
  }
  fclose(fptr);
  makenulltree(&T);
  for(i=0;i<count;i++){
    insertnode(a[i], &T);
  }
  /* for(i=1;i<count;i++){
    printf("%d\n", compare(a[0].ten,a[i].ten));
    }*/
  printf("Danh sach sinh vien theo tu tu tu dien tang dan\n");
  inorderprint(T);
  printf("Nhap ten sinh vien muon tim:");
  scanf("%s%s%s", x.lastname, x.midname, x.firstname);
  subT=search(x, T);
  if(subT!=NULL){
    printf( "%-10d%-20s%s %s %s\t\t%s\n", subT->key.stt,subT->key.mssv,subT->key.ten.lastname,subT->key.ten.midname,subT->key.ten.firstname,subT->key.sdt); 
  } else printf("Not found\n");
  return 0;
}
