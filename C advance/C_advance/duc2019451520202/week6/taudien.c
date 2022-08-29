#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include "Graphjrb.h"
#include <string.h>
typedef struct{
  char id[5];
  char name[20];
} taudien;

void printvertice(char *x){
  printf("%s ", x);
}

int main(){
  JRB Tree = make_jrb(), tmp2;
  int i,j=0, count, n, found = 0;
  taudien T;
  Graph tmp;
  Graph G= createGraph();
  char *output[100], c, A[101], B[100];
  FILE *fptr;
  fptr=fopen("taudien.txt", "r+");
  if(fptr == NULL) {
    printf("Cannot open file\n");
    return 1;
  }
  count = 0;
  while(1){
    fscanf(fptr, "%[^\n]%*c", A);
    if(strcmp(A, "LINE") == 0) break;
    count++;
  }
  // Count is correct (= 10)
  if(fseek(fptr, 0, SEEK_SET)!=0) {
    printf("Fseek failed.\n");
    return 1;
  }
  for(int i=0;i<count;i++){
    fscanf(fptr,"%[^=]%*c%[^\n]%*c", T.id, T.name);
    jrb_insert_str(Tree, strdup(T.id), new_jval_s(strdup(T.name)));
  }
  fgets(A, 100, fptr);
  count = 0;
  while(fgets(A, 100, fptr) != NULL) count++;
  // count is correct.
  if(fseek(fptr, 0 , SEEK_SET)!= 0){
    printf("Fseek failed\n");
    return 1;
    }
  while(1){
    fscanf(fptr, "%[^\n]%*c", A);
    if(strcmp(A, "LINE") == 0) break;
    }
  // FILE pointer's location is correct.
  for(i=0;i<count-1;i++){
    fscanf(fptr,"%[^=]%*c", A);
    fscanf(fptr, "%s%*c",A);
    while(1){
      fscanf(fptr, "%s", B);
      addEdge(G, strdup(A), strdup(B));
      strcpy(A, B);
      c=fgetc(fptr);
      if(c=='\n') break;
    }
  }

  jrb_traverse(tmp, G){
    n = getAdjacentVertices(G, jval_s(tmp->key), output);
    printf("%s: ", jval_s(tmp->key));
    for(i=0;i<n;i++){
      printf("%s ", output[i]);
    }
    printf("\n");
  }
  printf("Enter name of Station: ");
  scanf("%[^\n]", A);
  jrb_traverse(tmp, Tree){
    if(strcmp(jval_s(tmp->val), A) == 0){
      found = 1;
      strcpy(B,jval_s(tmp->key));
      }
  }
  if(!found) {
    printf("Not found\n");
    return 1;
  }
  else{
    n = getAdjacentVertices(G, B, output);
    for(i=0;i<n;i++){
      printf("%s ", jval_s(jrb_find_str(Tree, output[i])->val));
    }
    printf("\n");
    }
  /* printf("Finding the shortest line between 2 station.\n");
  __fpurge(stdin);
  BFS(G, "S1", "S3", printvertice);
  printf("\n");
  DFS(G, "S1", "S-1", printvertice);*/
  dropGraph(G);
  fclose(fptr);
  return 0;
}
