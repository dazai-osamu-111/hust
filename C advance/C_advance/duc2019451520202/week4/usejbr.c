// Su dung thu vien jrb
#include<stdio.h>
#include "jrb.h"

int main(){
  int i,n;
  int x;
  JRB tree=make_jrb();
  JRB bn;
  /* insert an integer number*/
  printf("Enter n: ");
  scanf("%d", &n);
  for(i=0;i<n;i++){
    printf("Enter number %d: ", i+1);
    scanf("%d", &x);
    jrb_insert_int(tree, x, new_jval_i(x));
  }
  /* display*/
  jrb_traverse(bn, tree){
    printf("%d\n", jval_i(bn->val));
  }
  printf("Enter value you wanto find: ");
  scanf("%d", &x);
  bn=jrb_find_int(tree, x);
  if(bn==NULL){
    printf("Not found\n");
    return 0;
  } else{
    printf("%d\n", jval_i(bn->val));
  }
   // free memory
  jrb_free_tree(tree);
  printf("free memory\n");
  return 0;
}
