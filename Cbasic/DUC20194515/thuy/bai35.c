#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
typedef struct{
  char name[30];
  char password[30];
} element;
int compare(element x, element y){
  if(strcmp(x.name,y.name)<0) return -1;
  if(strcmp(x.name,y.name)==0) return 0;
  else return 1;
}
#include "GenBST35.h"
int main(){
  FILE *fptr;
  char c;
  int x, count;
  element a;
  treetype tmp, root;
  makenulltree(&root);
  do{
    printf("1. Login\n"
	   "2. Export to file\n"
	   "3. Eixt\n"
	   "Your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      fptr=fopen("pass.txt","r+");
      if(fptr==NULL){
	printf("Can not open file\n");
	return 1;
      }
      while(fscanf(fptr,"%s%s", a.name, a.password)!=EOF){
	insertnode(a, &root);
      }
      count = 1;
      do{
	__fpurge(stdin);
	printf("Enter usename: ");
	gets(a.name);
	__fpurge(stdin);
	printf("Enter password: ");
	gets(a.password);
	tmp=search(a, root);
	if( tmp==NULL || strcmp(tmp->key.password, a.password)!=0){
	  printf("usename or password is not correct\n");
	  count++;		
	} else count=3;
      } while(count<3);
      
      if(strcmp(a.name,"admin")==0){
	do{
	  printf("1. Insert a new user\n");
	  printf("2. Change password\n");
	  printf("3. Print list of users\n");
	  printf("4. Exit\n"
		 "Your choice: ");
	  scanf("%d", &x);
	  switch(x){
	  case 1:
	    printf("Enter new user\n");
	    __fpurge(stdin);
	    printf("Enter usename: ");
	    gets(a.name);
	    __fpurge(stdin);
	    printf("Enter password: ");
	    gets(a.password);
	    tmp=search(a, root);
	    if(tmp==NULL){
	      insertnode(a, &root);
	    } else{
	      printf("This usename is exist\n");
	    }
	    break;
	  case 2:
	    __fpurge(stdin);
	    printf("Enter usename: ");
	    gets(a.name);
	    tmp=search(a, root);
	    if(tmp==NULL){
	      printf("This user is not exist\n");
	    } else{
	      __fpurge(stdin);
	      printf("Enter new password\n");
	      gets(tmp->key.password);
	    }
	    break;
	  case 3:
	    printf("List of users\n");
	    inorderprint(root);
	    break;
	  }
	}  while(x!=4);
      }
      else{
	if(strcmp(a.password, tmp->key.password)==0){
	  printf("Password is correct\n");
	  printf("Do you want to change password(y,n)\n");
	  scanf("%c",&c);
	  if(c=='y'){
	    __fpurge(stdin);
	    printf("Enter new password: ");
	    gets(tmp->key.password);
	    printf("Done\n");
	  } else break;
	}
      }
      fclose(fptr);
      break;
    case 2:
      fptr=fopen("pass.txt","r+");
      if(fptr==NULL){
	printf("Cannot open file\n");
	return 1;
      }
      printtofile(root, fptr);
      printf("Done\n");
      fclose(fptr);
      break;
    default: break;
    }
  } while(x!=3);
  return 0;
}
