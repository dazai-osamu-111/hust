#include<stdio.h>
#include<string.h>
#include<time.h>
typedef struct{
  char name[50];
} vdv;
typedef vdv element;
#include "GenBTree.h"
#include "queuelist.h"
#define MAX 100
int random1(int min, int max){
  return min+rand()%(max+1-min);
}

void postorderprint(treetype tree){
  if(tree!=NULL){
    postorderprint(tree->left);
    postorderprint(tree->right);
    printf("%20s\n", tree->element.name);
  }
}

int main(){
  treetype T=NULL,temp1=NULL,temp2=NULL,temp=NULL;
  queue *front=NULL, *rear= NULL;
  FILE *fptr;
  int i, count=0;
  char a1[50];
  vdv *a,a2;
  fptr=fopen("AUOpen.txt", "r");
  if(fptr==NULL){
    printf("Cannot open file.\n");
    return 1;
  }
  while(fgets(a1, MAX, fptr) !=NULL){
    count ++;
  }
  a=(vdv*)malloc(count * sizeof(vdv));
  if(fseek(fptr, 0, SEEK_SET) != 0){
  printf("fseek failed\n");
  return 1;
}
  for(i=0;i<count;i++){
    fscanf(fptr,"%s",a1);
    strcpy(a[i].name,a1);
  }
  for(i=0;i<count;i++){
    printf("%s\n",a[i].name);
  }
  for(i=0;i<count;i++){
    temp=creatnode(a[i]);
    enQ(&front, &rear, temp); 
  }
  printf("\n\n");
  while(count>1){
    temp1=deQ(&front, &rear);
    count--;
    temp2=deQ(&front, &rear);
    count --;
    if(random1(0,1)){
      enQ(&front, &rear,  creatfrom2(temp1->element, temp1, temp2));
      count++;
    }else{
      enQ(&front, &rear,creatfrom2(temp2->element,temp1 , temp2));
      count++;
    }
  }
  T=deQ(&front, &rear);
  postorderprint(T);
  freetree(&T);
  return 0;
}
