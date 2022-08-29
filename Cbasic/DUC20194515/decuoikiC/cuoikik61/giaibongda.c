#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct{
  int id;
  char  ten[30];
  int diem;
  int sobanthang;
  int sobanthua;
} doibong;
typedef doibong element;
#include "GenSLL.h"
int main(){
  node *p;
  FILE *fptr,*fout;
  int n,x1,x2;
  int i,j,min;
  doibong a,b;
  char s[10], x;
  do{
    printf("             MENU          \n"
	   "1. In thong tin cac doi bong\n"
	   "2. In thong tin lich thi dau\n"
	   "3. Cap nhat ket qua vong dau\n"
	   "4. Thong ke\n"
	   "5. thoat\n"
	   "ban chon: ");
    __fpurge(stdin);
    scanf("%c", &x);
    switch(x){
    case '1':
       fptr=fopen("bongda.txt", "r");
       if(fptr==NULL){
	 printf("Cannot open file\n");
	 return 1;
       }
       fgets(s, MAX, fptr);
       n=atoi(s);
       for(i=0;i<n;i++){
	 fscanf(fptr,"%d%*c%[^\n]%*c", &a.id, a.ten);
	 a.diem=a.sobanthang=a.sobanthua=0;
	 insertathead(a);
       }
       for(p=root;p!=NULL;p=p->next){
	 printf("%d\t%-20s%d\t%d\t%d\t\n",p->element.id,p->element.ten,p->element.diem,p->element.sobanthang,p->element.sobanthua);
       }
       fclose(fptr);
       break;
    case '2':
      fptr=fopen("bongda.txt", "r");
       if(fptr==NULL){
	 printf("Cannot open file\n");
	 return 1;
       }
       fgets(s, MAX, fptr);
       n=atoi(s);
       for(i=0;i<n;i++){
	 fscanf(fptr,"%d%*c%[^\n]%*c", &a.id, a.ten);
       }
       fout=fopen("lichdau.txt", "w");
       for(i=0;i<n-1;i++){
	fgets(s, MAX, fptr);
	
	printf("%s", s);
	for(j=0;j<2;j++){
	  fscanf(fptr,"%d%d%*c", &x1,&x2);
	  for(p=root;p!=NULL;p=p->next){
	    if(p->element.id==x1){
	      printf("%s - ", p->element.ten);
	      fprintf(fout, "%s:", p->element.ten);
	    }
	  }
	  for(p=root;p!=NULL;p=p->next){
	    if(p->element.id==x2){
	      printf("%s\n", p->element.ten);
	      fprintf(fout,"%s\n", p->element.ten);
	    }
	  }
	}
       }
       fclose(fptr);
       fclose(fout);
       fout=fopen("lichdau.txt", "r");
       if(fout==NULL){
	 printf("Cannot open file\n");
       }
       i=0;
       break;
    case '3':
      if(i<n-1){
	printf("Vong %d\n", ++i);
	for(j=0; j<2  ;j++){
	  fscanf(fout,"%[^:]%*c%[^\n]%*c", a.ten, b.ten);
	  printf("%s-%s: ",a.ten, b.ten);
	  scanf("%d%*c", &x1);
	  scanf("%d", &x2);
	  for(p=root;p!=NULL;p=p->next){
	    if(strcmp(p->element.ten, a.ten)==0){
	      p->element.sobanthang+=x1;
	      p->element.sobanthua+=x2;
	      if(x1<x2)
		p->element.diem+=0;
	      else if(x1==x2)
		p->element.diem+=1;
	      else p->element.diem+=3;
	    }
	  }
	  for(p=root;p!=NULL;p=p->next){
	    if(strcmp(p->element.ten, b.ten)==0){
	      p->element.sobanthang+=x2;
	      p->element.sobanthua+=x1;
	      
	      if(x2<x1)
		p->element.diem+=0;
	      else if(x2==x1)
		p->element.diem+=1;
	      else p->element.diem+=3;
	    }
	  }
	}
      } else{
	printf("tat ca cac doi da duoc nhap\n");
	break;
      }
      for(p=root;p!=NULL;p=p->next){
	printf("%d\t%-20s%d\t%d\t%d\t\n",p->element.id,p->element.ten,p->element.diem,p->element.sobanthang,p->element.sobanthua);
      }
      break;
    case '4':
      min=root->element.diem;
      for(p=root;p!=NULL;p=p->next){
	if(p->element.diem<min) min=p->element.diem;
      }
      printf("Cac doi co diem thap nhat la:\n");
      for(p=root;p!=NULL;p=p->next){
	if(p->element.diem==min){
	  printf("%d\t%-20s%d\t%d\t%d\t\n",p->element.id,p->element.ten,p->element.diem,p->element.sobanthang,p->element.sobanthua);
	}
      }
      printf("Cac doi con lai:\n");
      for(p=root;p!=NULL;p=p->next){
	if(p->element.diem>min){
	  printf("%d\t%-20s%d\t%d\t%d\t\n",p->element.id,p->element.ten,p->element.diem,p->element.sobanthang,p->element.sobanthua);
	}
      }
      break;
    default: break;
    }
  }while(x!='5');
  freelist(root);
  return 0;
}

