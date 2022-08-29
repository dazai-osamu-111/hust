#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 100
typedef struct{
  char anh[25];
  char viet[25];
} dic;
typedef dic element;
#include "GenSBTree st.h"
int tachchu(char a[][MAX],char s[]){
  int i,j,k;
  j=0;k=0;
  for(i=0;i<=strlen(s);i++){
    if(s[i]==' '||s[i]=='\0'){
      a[k][j]='\0';
      k++;
      j=0;
    }
    else{
      a[k][j]=s[i];
      j++;
    }
  }
  return k;
}
void intolower(char s[]){
  int i;
  for(i=0;i<strlen(s);i++){
    if(s[i]>64 && s[i]<91){
      s[i]=s[i]+32;
    }
  }
  return;
}
int main(){
  char str[MAX][MAX];
  FILE *fptr;
  treetype T, temp; 
  dic a;
  int x,i,k;
  char s[25],x1;
  fptr=fopen("dic.txt", "r+");
  if(fptr==NULL){
    printf("Cannot open file dict.txt\n");
    return 1;
  }
  do{
    printf("\n\n1. Nap tu dien\n"
	   "2. in tu dien\n"
	   "3. tim kiem va cap nhat\n"
	   "4. Dich cau tieng anh\n"
	   "5.exit\n");
    printf("ban chon? ");
    scanf("%d", &x);
    switch(x){
    case 1:
      makenulltree(&T);
      if(fseek(fptr, 0, SEEK_SET) !=0){
	printf("fseek failed\n");
	return 1;
      }
      while(fscanf(fptr,"%s%s",a.anh,a.viet)!=EOF){
	insertnode(a, &T);
      }
      printf("Done!\n");
      break;
    case 2:
      inorderprint(T);
      break;
    case 3:
      printf("nhap 1 tu tieng anh: ");
      scanf("%s",s);
      __fpurge(stdin);
      temp=search(s,T);
      if(temp!=NULL){
	printf("Ban co cap nhat noi dung moi  vao tu dien ko?(y\n)\n");
	printf("Ban chon: ");
	scanf("%c", &x1);
	if(x1=='n'){
	  printf("ok bro\n");
	};
	if(x1=='y'){
	  printf("giai nghia tieng viet? ");
	  scanf("%s",temp->key.viet);
	}
      } else{
	printf("Nhap tu giai nghia: ");
	scanf("%s", a.viet);
	strcpy(a.anh, s);
	insertnode(a, &T);
      }
      break;
    case 4:
      printf("\n\n");
      __fpurge(stdin);
      do{
	printf("\na. Tach cau\n"
	       "b. Dich cau\n"
	       "c. Cap nhat tu con thieu\n"
	       "d. thoat\n");
	printf("Ban chon: ");
	scanf("%c", &x1);
	switch(x1){
	case 'a':
	  printf("\n\n");
	  __fpurge(stdin);
	  printf("Nhap cau tieng anh: ");
	  gets(s);
	  k=tachchu(str,s);
	  for(i=0;i<k;i++){
	    intolower(str[i]);
	    printf("%s\n",str[i]);
	  }
	  break;
	case 'b':
	  for(i=0;i<k;i++){
	    temp=search(str[i], T);
	    if(temp==NULL){
	      printf(" <thieu tu>");
	    }
	    else{
	      printf(" %s", temp->key.viet);
	    }
	  }
	  break;
	case 'c':
	  printf("Nhap tu ban muon giai nghia:");
	  scanf("%s",a.anh);
	  printf("nghia cua tu: ");
	  scanf("%s",a.viet);
	  insertnode(a, &T);
	  printf("Tu da duoc them vao t dien\n");
	  break;
	default: break;
	}
      } while(x1!='d');
      break;
    default:
      break;
    }
  } while(x!=5);
  return 0;
}
