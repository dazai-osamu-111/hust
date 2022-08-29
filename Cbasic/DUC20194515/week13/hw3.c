#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
  char model[40];
  char space[10];
  char ssize[15];
  char price[20];
} phonedb;
typedef phonedb element;
#include "GenSBTree.h"
int main(){
  FILE *f1, *f2;
  if((f1=fopen("PhoneDB.txt", "r"))== NULL){
    printf("cannot open file PhoneDB.txt\n");
    return 1;
  }
  if((f2=fopen("PhoneDB.dat", "r"))== NULL){
    printf("cannot open file PhoneDB.dat\n");
    return 1;
  }
  treetype T;
  phonedb a;
  char s[MAX];
  int count=0;
  int x;
  while((fgets(s, MAX, f1)) != NULL){
    count ++;
  }
  do{
    printf("1. Import data from text file\n"
	   "2. Import data from dat file\n"
	   "3. Add phone model\n"
	   "4. Delete\n"
	   "5. Update\n"
	   "6. Searching\n"
	   "7. Displaying and Save data to File PhoneDB.dat\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      makenulltree(&T);
      if(fseek(f1, 0, SEEK_SET) != 0){
	printf("fseek failed\n");
	return 1;
      }
      while(fscanf(f1,"%s%s%s%s",a.model,a.space,a.ssize,a.price) != EOF){
	insertnode(a, &T);
      }
      printf("Done!\n");
      break;
    case 2:
      makenulltree(&T);
      if(fseek(f2, 0, SEEK_SET) != 0){
	printf("fseek failed\n");
	return 1;
      }
      while(fread(&a, sizeof(phonedb), 1, f2)>0){
	insertnode(a, &T);
      }
      printf("Done!\n");
      break;
    case 3:
      printf(" Start adding a new phone\n");
      printf("Enter model:");
      scanf("%s",a.model);
      printf("Enter memory: ");
      scanf("%s", a.space);
      printf("Enter screen size: ");
      scanf("%s", a.ssize);
      printf("Enter price: ");
      scanf("%s", a.price);
      insertnode(a, &T);
      printf("Done!\n");
      break;
    case 4:
      
    case 7:
      inorderprint(T);
      printf("Done!\n");
      break;
    default: break;
    }
  } while(x!=8);
  return 0;
}
