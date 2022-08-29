#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
typedef struct{
  int masp;
  char ten[30];
  int gia;
  int sl;
} sanpham;

typedef sanpham element;
#include "GenSLL.h"

void traversal(node *root){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    printf("%d %d %d %d %s\n", p, p->element.masp, p->element.gia, p->element.sl, p->element.ten);
  }
}

int listtoarray(sanpham a[], node *root){
  int i=0;
  node *p;
  for(p=root;p!=NULL;p=p->next){
    a[i++]=p->element;
  }
  return i;
}
int main(){
  sanpham a[100], tmp;
  int x,i,n,j, min, sum, cn;
  FILE *fptr;
  node *p, *q;
  do{
    printf("1. Nhap thong tin sap pham\n"
	   "2. Doc tep\n"
	   "3. Sap xep\n"
	   "4. Tinh tong so tien\n"
	   "5. Dem nhom sp trung gia\n"
	   "6. Ten trung nhau\n"
	   "7. Thoat\n"
	   "Your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      i=0;
      while(1){
	printf("Nhap ma so sp: ");
	scanf("%d", &a[i].masp);
	if(a[i].masp == 0){
	  printf("ket thuc\n");
	  break;
	} else{
	  if(i>=1){
	    while(a[i].masp<=a[i-1].masp){
	      printf("ma san pham ko hop le:\n");
	      scanf("%d", &a[i].masp);
	    }
	  }
	  printf("Nhap gia: ");
	  scanf("%d", &a[i].gia);
	  while(a[i].gia < 0){
	    printf("Gia phai lon hon 0, hay nhap lai : ");
	    scanf("%d", &a[i].gia);
	  }
	  printf("Nhap so luong: ");
	  scanf("%d", &a[i].sl);
	  while(a[i].sl<=0){
	    printf("So luong san pham phai lon hon 0: ");
	    scanf("%d", &a[i].sl);
	  }
	  __fpurge(stdin);
	  printf("Nhap ten sp: ");
	  gets(a[i].ten);
	  printf("\n\n");
	  i++;
	}
      }
      n=i;
      fptr=fopen("sanpham.txt","w+");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      for(i=0;i<n;i++){
	printf("%d %d %d %s\n", a[i].masp, a[i].gia, a[i].sl, a[i].ten);
      }
      for(i=0;i<n;i++){
	fprintf(fptr,"%d %d %d %s\n", a[i].masp, a[i].gia, a[i].sl, a[i].ten);
      }
      fclose(fptr);
      break;
    case 2:
      root=NULL, cur=NULL, prev=NULL;
      fptr=fopen("sanpham.txt", "r");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      while(fscanf(fptr, "%d%d%d%[^\n]%*c", &tmp.masp, &tmp.gia, &tmp.sl, tmp.ten)!=EOF){
	insertaftercurrent(tmp);
      }
      traversal(root);
      break;
    case 3:
      for(p=root;p->next!=NULL;p=p->next){
	for(q=p->next;q!=NULL;q=q->next){
	  if(q->element.gia<p->element.gia){
	    tmp=p->element;
	    p->element=q->element;
	    q->element=tmp;
	  }
	}
      }
      traversal(root);
      break;
    case 4:
      sum=0;
      for(p=root;p!=NULL;p=p->next){
	sum=sum+p->element.gia*p->element.sl;
      }
      printf("Tong tien cua tat ca cac san pham la: ");
      printf("%d\n", sum);
      break;
    case 5:
      cn=1;
      n=listtoarray(a, root);
      for(i=1;i<n;i++){
	if(a[i].gia=a[i-1].gia) cn++;
       else{
	 printf("%d xuat hien %d lan\n", a[i].gia, cn);
	 cn=1;
       }
      }
      break;
    case 6:
      break;
    }
  } while(x!=7);
  return 0;
}
