#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
  void *key;
  void *value;
} Entry;

Entry makePhone(void *name, void *phone){
  Entry res;
  
  res.key = strdup((char*) name);
  res.value = malloc(sizeof(int));
  memcpy(res.value, phone, sizeof(int));
  return res;
}
int main(){
  Entry uyen, hau;
  int number= 020401;
  uyen = makePhone("khong dang yeu", &number);
  number = 250901;
  hau = makePhone("Vo cung xinh gai", &number);
  printf("%-20s%d\n", (char*)uyen.key, *((int*)uyen.value));
  return 0;
}
