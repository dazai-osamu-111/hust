#include<stdio.h>
#include<string.h>
typedef struct{
  char name[10];
  int score;
} doibong;
typedef doibong element;
int compare(doibong a, doibong b){
  if(a.score>b.score) return 1;
  if(a.score<b.score) return -1;
  else return 0;
}

int comparename(doibong a, doibong b){
  if(strcmp(a.name, b.name)>0) return 1;
  else if(strcmp(a.name, b.name)<0) return -1;
  else return 0;
}
#include "GenSBTree st.h"
int main(){
  int x,i=0, count=0,x1;
  treetype T,temp1,temp2;
  doibong a,b;
  doibong *arr;
  FILE *fptr;
  char s[10];
  makenulltree(&T);
  do{
    printf("1. Tao cay\n"
	   "2. Ket qua\n"
	   "3. TIm kiem\n"
	   "4. Xuong hang\n"
	   "5. Xuat file\n"
	   "6. thoat\n");
    printf("ban chon: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      fptr=fopen("BongDa.txt","r");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      while(fscanf(fptr,"%s%s%d%d", a.name,b.name, &a.score, &b.score) != EOF){
	if(a.score>b.score){
	  a.score=3;
	  b.score=0;
	}else{
	  if(a.score==b.score){
	    a.score=1;
	    b.score=1;
	  }
	  else{
	    a.score=0;
	    b.score=3;
	  }
	}
	temp1=search(a,T);
	if(temp1==NULL){
	  insertnode(a, &T);
	  printf("node thu %d\n", ++i);
	} else{
	  temp1->key.score+=a.score;
	}
	temp2=search(b,T);
	if(temp2==NULL){
	  insertnode(b,&T);
	  printf("node thu %d\n",++i);
	} else{
	  temp2->key.score+=b.score;
	}
      }
      fclose(fptr);
      break;
    case 2:
      printf("Ket qua cua cac doi:\n");
      inorderprint(T);
      break;
    case 3:
      printf("Nhap ten doi: ");
      scanf("%s", s);
      temp1=searchteam(s, T);
      if(temp1==NULL){
	printf("Khong co doi bong nay\n");
      }else{
	printf("%-20s%d\n", temp1->key.name, temp1->key.score);
      }
      break;
    case 4:
      arr=(doibong*)malloc(MAX * sizeof(doibong));
      printf("Nhap so nguyen X: ");
      scanf("%d", &a.score);
      printf("Cac doi xuong hang:\n");
      arr=inordersearch(a, T);
      count=lowerthankey(a,T);
      for(i=0;i<count;i++){
	deletenode(*(arr+i), &T);
      }
      printf("Cay moi:\n");
      inorderprint(T);
      break;
    case 5:
      fptr=fopen("KetQua.txt", "w");
      if(fptr==NULL){
	printf("Cannot open file KetQua.txt\n");
	return 1;
      }
      printtofile(fptr, T);
      fclose(fptr);
      printf("Done\n");
      break;
    default: break;
    }
  } while(x!=6);
}
