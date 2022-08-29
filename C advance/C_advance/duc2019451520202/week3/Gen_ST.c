#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITIAL_SIZE 100
#define INCREMENTAL_SIZE 10

typedef struct{
  void *key;
  void *value;
} Entry;

typedef struct{
  Entry *entries;
  int size, total;
  Entry (*makeNode)(void*, void*);
  int (*compare)(void*, void *);
} SymbolTable;

// makeNode is a function poiter to refer to a function to creat a node with a key and a value passed
// compare is a function to refer to a function compare two keys

Entry makePhone(void *name, void *phone){
  Entry res;
  
  res.key = strdup((char*) name);
  res.value = malloc(sizeof(long));
  memcpy(res.value, phone, sizeof(long));
  return res;
}

int string_compare(void *key1, void *key2){
  return strcmp((char*)key1, (char*)key2);
}

int binarySearch(Entry  *arr, int l, int r, void *x, int *found, int  (*compare)(void*, void*)){
  if(r<l){
    *found=0;
    return l;
  }
  int mid=(l+r)/2;
  int res=compare(x, arr[mid].key);
  if(res==0) {
    *found=1;
    return mid;
  }
  else if(res<0) return binarySearch(arr, l, mid-1, x, found, compare);
  else  return binarySearch(arr, mid+1, r, x, found, compare);
}

SymbolTable createSymbolTable(Entry (*makeNode)(void*, void*), int (*compare)(void*, void*));
void dropSymbolTable(SymbolTable *tab);
void addEntry(void *key, void *value, SymbolTable *book);
void *getEntry(void *key, const SymbolTable *book);
void listEntry(SymbolTable book){
  for(int i=0;i<book.total;i++){
    printf("%-20s%ln\n", (char*)book.entries[i].key, (long*)(book.entries[i].value));
  }
}
//NB Free the memory allocated for each entry when a table is dropped

int main(){
  SymbolTable phoneBook = createSymbolTable(makePhone, string_compare);
  long number = 983984775;
  char name[] = "Ta Tuan Anh";
  long number2=123456;
  addEntry(name, &number, &phoneBook);
  addEntry("Do Dung", &number2, &phoneBook);
  addEntry("Do Dung", &number2, &phoneBook);
  listEntry(phoneBook);
}
SymbolTable createSymbolTable(Entry (*makeNode)(void*, void*), int (*compare)(void*, void*)){
  SymbolTable book;
  book.entries=malloc( sizeof(Entry) * INITIAL_SIZE);
  book.size = INITIAL_SIZE;
  book.total = 0;
  book.makeNode=makeNode;
  book.compare=compare;
  return book;
}

void addEntry(void *key, void *value, SymbolTable *book){
  int pos, found;
  if((*book).total <= 0){
    found = 0;
    pos = 0;
  } else  pos=binarySearch((*book).entries, 0, (*book).total-1, key, &found,(*book).compare);
  //printf("\t%d", found);
  if(found==1){
    Entry tmp=(*book).makeNode(key, value);
    memcpy(&(*book).entries[pos], &tmp, sizeof(Entry)); 
  } else{
    if((*book).total>=(*book).size){
      (*book).size+=INCREMENTAL_SIZE;
      (*book).entries = (Entry*)realloc(book->entries, sizeof(Entry) * (*book).size);
    }
    if(pos < (*book).total){
      memcpy(&((*book).entries[pos+1]), &((*book).entries[pos]), sizeof(Entry)*((*book).total-pos));
    }
    (*book).entries[pos] = (*book).makeNode(key, value);
    (*book).total++;
  }
}
  
