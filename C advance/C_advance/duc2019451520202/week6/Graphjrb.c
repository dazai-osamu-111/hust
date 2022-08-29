#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Graphjrb.h"
#include "dllist.h"
Graph createGraph(){
  return make_jrb();
}

int adjacent(Graph G, char *v1, char *v2){
  JRB tmp;
  tmp = jrb_find_str(G, v1);
  if(!tmp)
    return 0;
  tmp = (JRB)jval_v(tmp->val);
  if(jrb_find_str(tmp, v2))
    return 1;
  else
    return 0;
}

void addEdge(Graph g, char *v1, char *v2){
  JRB node, tree;
  if(!adjacent(g, v1, v2)){
    node = jrb_find_str(g, v1);
    if(!node){
      tree = make_jrb();
      jrb_insert_str(g, v1, new_jval_v(tree));
      jrb_insert_str(tree, v2, new_jval_i(1));
    } else{
      tree = (JRB)jval_v(node->val);
      jrb_insert_str(tree, v2, new_jval_i(1));
    }
  }
  if(!adjacent(g, v2, v1)){
    node = jrb_find_str(g, v2);
    if(!node){
      tree = make_jrb();
      jrb_insert_str(g, v2, new_jval_v(tree));
      jrb_insert_str(tree, v1, new_jval_i(1));
    } else{
      tree = (JRB)jval_v(node->val);
      jrb_insert_str(tree, v1, new_jval_i(1)); 
    }
  }
}


int getAdjacentVertices(Graph G, char *v, char **output){
  JRB tmp, ga;
  int total = 0;
  tmp = jrb_find_str(G, v);
  if(!tmp)
    return 0;
  tmp = (JRB)jval_v(tmp->val);
  jrb_traverse(ga, tmp){
    output[total++] = jval_s(ga->key);
  }
  return total;
}

void dropGraph(Graph G){
  if(G==NULL){
    printf("Graph is empty\n");
    return;
  }
  JRB tmp;
  jrb_traverse(tmp, G)
    jrb_free_tree((JRB)jval_v(tmp->val));
  jrb_free_tree(G);
}

void BFS(Graph G, char *start, char *stop, void (*func)(char *)){
  JRB visited = make_jrb();
  JRB bn;
  int n, i;
  char *u, *v, *output[100];
  Dllist queue, node;
  jrb_traverse(bn, G){
    jrb_insert_str(visited, jval_s(bn->key), new_jval_i(0));
  }

  queue = new_dllist();
  // Them gia tri start vao queue
  dll_append(queue, new_jval_s(start));
  while(!dll_empty(queue)){
    //dequeue
    node = dll_first(queue);
    u = jval_s(node->val);
    dll_delete_node(node);
    // xem xet
    if(!jval_i(jrb_find_str(visited, u)->val)){
      func(u);
      jrb_find_str(visited, u)->val = new_jval_i(1);
      if(strcmp(u, stop) == 0) break;
      // Neu dinh ke chua visited thi them vao queue
      n = getAdjacentVertices(G, u, output);
      for(i=0;i<n;i++){
	if(!jval_i(jrb_find_str(visited, output[i])->val))
	  dll_append(queue, new_jval_s(output[i]));
      }
    }
  }
  free_dllist(queue);
  jrb_free_tree(visited);
  
}

void DFS(Graph G, char *start, char *stop, void (*func)(char*)){
  JRB visited, bn;
  Dllist stack, node;
  char *u, *output[100];
  int n, i;
  visited = make_jrb();
  jrb_traverse(bn, G){
    jrb_insert_str(visited, jval_s(bn->key), new_jval_i(0));
  }
  stack = new_dllist();
  // Them start vao stack
  dll_prepend(stack, new_jval_s(start));
  while(!dll_empty(stack)){
    // Pop
    node = dll_first(stack);
    u = jval_s(node->val);
    dll_delete_node(node);
    // xem xet
    if(!jval_i(jrb_find_str(visited, u)->val)){
      func(u);
      jrb_find_str(visited, u)->val = new_jval_i(1);
      
      if(strcmp(u, stop) == 0) break;
      // Neu dinh ke chua visit thi them vao stack
      n = getAdjacentVertices(G, u, output);
      for(i=0;i<n;i++){
	if(!jval_i(jrb_find_str(visited, output[i])->val)){
	  dll_prepend(stack, new_jval_s(output[i]));
	  
	}
      }
    }
  }
  free_dllist(stack);
  jrb_free_tree(visited);
}
