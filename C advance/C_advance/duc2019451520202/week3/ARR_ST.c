#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char name[80];
  long number;
} PhoneEntry;

typedef struct{
  PhoneEntry *entries;
  int total;
  int size;
} PhoneBook;

#define INITIAL_SIZE 10
#define INCREMENTAL_SIZE 5

PhoneBook creatPhoneBook();
void dropPhoneBook(PhoneBook *book);
void addPhoneNumber(char *name, long number, PhoneBook *book);
// Note: if the entry exist, the value should be overitten
PhoneEntry *getPhoneNumber(char *name, PhoneBook book);
// Return null if the entry does not exist

int binarySearch(PhoneEntry *entries, int l, int r, char *name, int *found){
  if(r<l){
    *found = 0;
    return l;
  }
  int mid=(l+r)/2;
  int result = strcmp(name, entries[mid].name);
  if(result == 0){
    *found=1;
    return mid;
  } else if(result < 0) binarySearch(entries, l, mid -1, name, found);
  else binarySearch(entries, mid+1, r, name, found);
}

void listPhoneBook(PhoneBook book){
  if(book.total == 0){
    printf("list empty\n");
    return;
  }
  for(int i=0;i < book.total;i++){
    printf("%-20s%ld\n", book.entries[i].name, book.entries[i].number);
  }
}
int main(){
  PhoneBook book;
  int i;
  book=creatPhoneBook();
  addPhoneNumber("Do Lam", 909090 , &book);
  addPhoneNumber("Tuan Dung", 929292 , &book);
  addPhoneNumber("Anh Thang", 919191, &book);
  addPhoneNumber("Ngo Phong", 949494, &book);
  addPhoneNumber("Con ga duc", 250924, &book);
  
  // Hien thi danh sach book
  listPhoneBook(book);
  printf("\n\n");
  addPhoneNumber("Ngo Phong", 123456, &book);
  addPhoneNumber("Tuan Dung", 123452 , &book);
   listPhoneBook(book);
  // Tim kiem
  PhoneEntry *entry=getPhoneNumber("Con ga duc", book);
  if(entry == NULL) printf("Khong tim thay\n");
  else printf("%ld\n", (*entry).number);
  dropPhoneBook(&book);
  listPhoneBook(book);
}

void dropPhoneBook(PhoneBook *book){
  free(book->entries);
  book->total=0;
  book->size=0;
}

PhoneEntry *getPhoneNumber(char *name, PhoneBook book){
  int pos, found;
  pos = binarySearch(book.entries, 0, book.total-1, name, &found);
  if(found==1) return &book.entries[pos];
  else return NULL;
}

PhoneBook creatPhoneBook(){
  PhoneBook book;
  book.entries = malloc( INITIAL_SIZE * sizeof(PhoneEntry));
  book.total=0;
  book.size = INITIAL_SIZE;
  return book;
}

void addPhoneNumber(char *name, long number, PhoneBook *book){
  int pos, found;
  if((*book).total > 0){
    pos=binarySearch((*book).entries, 0, (*book).total-1, name, &found); 
  } else{
    found=0;
    pos=0;
    (*book).total=0;
  }
  if(found){
    (*book).entries[pos].number=number;
  } else{
    if((*book).total >= (*book).size){
      (*book).size+= INCREMENTAL_SIZE;
      (*book).entries = realloc((*book).entries, sizeof(PhoneEntry) * (*book).size);
    }
    memcpy(&((*book).entries[pos+1]), &((*book).entries[pos]), ((*book).total-pos) * sizeof(PhoneEntry));
    strcpy((*book).entries[pos].name, name);
    (*book).entries[pos].number=number;
    (*book).total++;
  }
}
