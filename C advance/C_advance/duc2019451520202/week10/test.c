#include<stdio.h>
#include "dllist.h"
void setBit(char *huffman, int nbit, int val){
  int i, byte, bit;
  byte = nbit/8;
  bit = nbit%8;
  if(val == 0){
    huffman[byte] &= ~(1 << bit);
  } else{
    huffman[byte] != (1 << bit);
  }
}
int main(){
  char huffman[20];
  int nbit;
  int val;
  Dllist queue = new_dllist();
  //setBit(huffman, nbit, val);
  dll_append(queue, new_jval_i(0));
  dll_append(queue, new_jval_i(2));
  dll_append(queue, new_jval_i(3));
  dll_append(queue, new_jval_i(4));
  dll_append(queue, new_jval_i(5));
  Dllist node;
  node = dll_first(queue);
  node = dll_next(node);
  node = dll_next(node);
  dll_insert_b(node, new_jval_i(7));
  node = dll_first(queue);
  while(node!=queue){
    printf("%d\n", jval_i(node->val));
    node =  dll_next(node);
  }
  printf("\n\n\n");
  node = dll_first(queue);
  printf("%p\t%d\n", node, jval_i(node->val));
  node = dll_last(queue);
  printf("%p\t%d\n", node, jval_i(node->val));
  printf("%p\t%d\n", queue, jval_i(queue->val));
  return 0 ;
}
