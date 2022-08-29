#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
typedef struct{
  char word[30];
  int count;
} element;

int compare(element x, element y){
  if(strcmp(x.word,y.word)<0) return -1;
  if(strcmp(x.word,y.word)==0) return 0;
  else return 1;
}
#include "GenBSTreehw2.h"
int main(int argc, char *argv[]){
  int x;
  if(argc !=2){
    printf("Error syntax\n");
    printf("True syntax: <name> <filename>\n");
    return 1;
  }
  element a;
  FILE *fptr;
  treetype root, temp;
  makenulltree(&root);
  fptr=fopen(argv[1], "r");
  if(fptr==NULL){
    printf("Cannot open file\n");
    return 1;
  }
  do{
    printf("********MENU*********\n"
	   "0.exit\n"
	   "1. Import from file\n"
	   "2. Search word and times\n"
	   "3. printf word and times in order of dictionary\n"
	   "Your choice: ");
    scanf("%d", &x);
    switch(x){
    case 1:
      while(fscanf(fptr,"%[^., \n\t]",a.word) !=EOF){
	temp=search(a, root);
	if(temp==NULL){
	  a.count=1;
	  insertnode(a, &root);
    } else{
	  temp->key.count++;
	}
	if(fseek(fptr, 1, SEEK_CUR) != 0){
	  printf("Fseek failed\n");
	  return 1;
	}
	printf("%s\n", a.word);
      }
      printf("File was read\n");
      break;
    case 2:
      __fpurge(stdin);
      printf("Enter a word: ");
      gets(a.word);
      temp=search(a, root);
      if(temp==NULL){
	printf("text has not this word\n");
      } else{
	printf("This word appears %d times\n", temp->key.count);
      }
      break;
    case 3:
      inorderprint(root);
      break;
    default: break;
    }
  } while(x!=0);
  freetree(&root);
  return 0;
}
