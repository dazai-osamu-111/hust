// use libfdr to write the phone book program( add, delete, insert, modify phone numbers).
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include "jrb.h"
#include<string.h>
typedef struct{
  char name[100];
  char number[100];
} phonebook;

/*phonebook * makephonebook(char *key, long *value){
  phonebook *tmp;
  printf("Enter name: ");
  scanf("%[^\n]", tmp->name);
  printf("Enter value: ");
  scanf("%ld", tmp->number);
  return tmp;
  }*/

void insertphonebook(JRB book,char *name, char *number){
  jrb_insert_str(book, strdup(name), new_jval_s(strdup(number)));
}
int main(){
  int x;
  FILE *fin=NULL;
  phonebook tmp;
  JRB book = make_jrb();
  JRB bn;
  char s[20],s2[20];
  while(1){
    __fpurge(stdin);
    printf("1. Import from file\n"
	   "2. Traverse book.\n"
	   "3. add a phone book\n"
	   "4. Delete a phone book\n"
	   "5. Update phone number\n"
	   "6. Exit\n");
    printf("Your choice? ");
    scanf("%d", &x);
    switch(x){
    case 1:
      fin=fopen("phonebook.txt", "r+");
      if(fin==NULL){
	printf("Cannot open file.\n");
	return 1;
      }
      while(fscanf(fin,"%[^\t]%*c%s%*c", tmp.name, tmp.number) != EOF){
	printf("%s\t%s\n", tmp.name, tmp.number);
	insertphonebook(book, tmp.name, tmp.number);
      }
      fclose(fin);
      break;
    case 2:
      jrb_traverse(bn, book){
	printf("%s\t%s\n", jval_s(bn->key), jval_s(bn->val));
      }
      break;
    case 3:
      __fpurge(stdin);
      printf("Enter name: ");
      scanf("%[^\n]", tmp.name);
      bn=jrb_find_str(book, strdup(tmp.name));
      if(bn==NULL){
	__fpurge(stdin);
	printf("Enter phone number: ");
	scanf("%[^\n]", tmp.number);
	insertphonebook(book, tmp.name, tmp.number);
      } else{
	printf("This name is existing, cannot add.\n");
      }
      break;
    case 4:
      __fpurge(stdin);
      printf("Enter name: ");
      scanf("%[^\n]", tmp.name);
      bn=jrb_find_str(book, strdup(tmp.name));
      if(bn==NULL){
	printf("Not found\n");
      } else{
	jrb_delete_node(bn);
	printf("Deleted.\n");
      }
      break;
    case 5:
      __fpurge(stdin);
      printf("Enter name: ");
      scanf("%[^\n]", tmp.name);
      bn=jrb_find_str(book, strdup(tmp.name));
      if(bn==NULL){
	printf("Not found.\n");
      } else{
	__fpurge(stdin);
	printf("Enter new number: ");
	scanf("%[^\n]", jval_s(bn->val));
	printf("Updated.\n");
      }
      break;
    case 6:
      jrb_free_tree(book);
      exit(0);
      break;
    }
  }
}
