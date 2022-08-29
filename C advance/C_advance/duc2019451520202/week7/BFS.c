#include<stdio.h>
#include<stdlib.h>
#include "jrb.h"
#include "dllist.h"
typedef JRB Graph;

Graph creatGraph();
void addEdge(Graph graph, int v1, int v2);
int getAdjacentVertices(Graph graph, int v, int *output);
void dropGraph(Graph graph);
int adjacent(Graph G, int v1, int v2);
void BFS(Graph graph, int start, int stop, void (*func)(int));
void DFS(Graph graph, int start, int stop, void (*func)(int));
void printVertex(int v){
  printf("%4d", v);
}
int main(){
  Graph tmp;
  Graph G= creatGraph();
  int output[100], n;
  addEdge(G, 3, 5);
  addEdge(G, 3, 8);
  addEdge(G, 5, 8);
  addEdge(G, 7, 1);
  addEdge(G, 6, 4);
  addEdge(G, 1, 3);
  addEdge(G, 3, 2);
  addEdge(G, 3, 2);
  printf("Print Graph\n");
  jrb_traverse(tmp, G){
    n = getAdjacentVertices(G, jval_i(tmp->key), output);
    printf("%d: ", jval_i(tmp->key));
    for(int i=0; i< n;i++){
      printf("%d ", output[i]);
    }
    printf("\n");
  }
  printf("BFS: ");
  BFS(G, 1, 5, printVertex);
  printf("\n");
  printf("DFS: ");
  DFS(G, 1, -1, printVertex);
  printf("\n");
  dropGraph(G);
  return 0;
}


Graph creatGraph(){
  return make_jrb();
}

void addEdge(Graph g, int v1, int v2){
  JRB node, tree;
  if(!adjacent(g, v1, v2)){
    node = jrb_find_int(g, v1);
    if(!node){
      tree = make_jrb();
      jrb_insert_int(g, v1, new_jval_v(tree));
      jrb_insert_int(tree, v2, new_jval_i(1));
    } else{
      tree = (JRB)jval_v(node->val);
      jrb_insert_int(tree, v2, new_jval_i(1));
    }
  }
  if(!adjacent(g, v2, v1)){
    node = jrb_find_int(g, v2);
    if(!node){
      tree = make_jrb();
      jrb_insert_int(g, v2, new_jval_v(tree));
      jrb_insert_int(tree, v1, new_jval_i(1));
    } else{
      tree = (JRB)jval_v(node->val);
      jrb_insert_int(tree, v1, new_jval_i(1)); 
    }
  }
}

int adjacent(Graph G, int v1, int v2){
  JRB tmp;
  tmp = jrb_find_int(G, v1);
  if(!tmp)
    return 0;
  tmp = (JRB)jval_v(tmp->val);
  if(jrb_find_int(tmp, v2))
    return 1;
  else
    return 0;
}

int getAdjacentVertices(Graph G, int v, int *output){
  JRB tmp, ga;
  int total = 0;
  tmp = jrb_find_int(G, v);
  if(!tmp)
    return 0;
  tmp = (JRB)jval_v(tmp->val);
  jrb_traverse(ga, tmp){
    output[total++] = jval_i(ga->key);
  }
  return total;
}

void dropGraph(Graph G){
  JRB tmp;
  jrb_traverse(tmp, G)
    jrb_free_tree((JRB)jval_v(tmp->val));
  jrb_free_tree(G);
}

void BFS(Graph graph, int start, int stop, void (*func)(int)){
  Dllist queue, node;
  int u, output[100], i, v, n;
  int visited[1000] = {};
  // tao 1 queue
  queue = new_dllist();
  // them phan tu dau tien vao hang doi
  dll_append(queue, new_jval_i(start));
  // Lay ra dinh dau tien trong han doi va quan sat no
  while(!dll_empty(queue)){
    node = dll_first(queue);
    u = jval_i(node->val);
    dll_delete_node(node);
    if(!visited[u]){
      func(u);
      visited[u] = 1;
      if( u == stop) return;
      n = getAdjacentVertices(graph, u, output);
      for(i=0;i<n;i++){
	v = output[i];
	if(!visited[v])
	  dll_append(queue, new_jval_i(v));
      }
    }
  } 
}

void DFS(Graph graph, int start, int stop, void (*func)(int)){
  int visited[1000] = {};
  int u, n, v, i, output[100];
  Dllist stack, node;
  // tao 1 stack
  stack = new_dllist();
  // them start vao stack
  dll_prepend(stack, new_jval_i(start));
  // Lay ra dinh va quan sat
  while( !dll_empty(stack)){
    // pop
    node = dll_first(stack);
    u = jval_i(node->val);
    dll_delete_node(node);
    // Neu chua tham thi xet cac dinh ke
    if(!visited[u]){
      func(u);
      visited[u] = 1;
      if( u== stop) return;
      n = getAdjacentVertices(graph, u, output);
      for(i=0;i<n;i++){
	v = output[i];
	if(!visited[v]){
	  dll_prepend(stack, new_jval_i(v));
	}
      }
    }
  }
}
