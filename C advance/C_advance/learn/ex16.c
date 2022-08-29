#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person{
  char * name;
  int age;
  int height;
  int weight;
};

struct Persion *Person_creat(char *name, int age, int height, int weight){
  struct Persion *who =  malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;
  return who;
}

void Person_destroy(struct Persion *who){
  assert(who!=NULL);
  free(who->name);
  free(who);
}

void Persion_print(struct Person *who){
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]){
  // make two people structures
  struct Person *joe = Person_create("Joe Alex" , 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 180);
  // printf them out and where they are in memory
  printf("Joe is ar memory location %p: \n", joe);
  Person_print(joe);

  printf("Frank is ar memory location %p: \n", frank);
  Person_print(frank);
  // make everyone age 20 years and print them again

  joe->age += 20;
  joe->height +=20;
  joe->weight +=40;
  Persion_print(joe);

  frank->age += 20;
  frank->height +=20;
  frank->weight +=40;
  Persion_print(frank);

  //destroy them both so we clean up

  Person_destroy(joe);
  Person_destroy(frank);

  return 0;

  

 
}
