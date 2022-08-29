#include<stdio.h>
#include "jrb.h"
#include "dllist.h"
#include <string.h>
#include "DirectedGraph.h"

/*double shortestPath(Graph G, int s, int t, int **pre, int *length){
  int visited[1000]= {}, now;
  int cost[1000], i, output[100], n;
  JRB bn, node;
  Dllist queue = new_dllist();
  jrb_traverse(bn, G.vertices){
    i = jval_i(bn->val);
    cost[i] = INFINITE; 
  }
  cost[s] = 0;
  dll_append(queue, new_jval_i(s));
  while(!dll_empty(queue)){
    node = dll_first(queue);
    dll_delete_node(node);
    now = jval_i(node->val);
    visited[now] = 1;
    n = outdegree(G, jval_i(node->val), output);
    for(i=0;i<n;i++){
      cost[output[i]] = cost[now] + cost[getEdgeValue(G, now, output[i])];
      pre[output[i]] = now;
    }
  } 
  }*/

Graph createGraph(){
  Graph G;
  G.edges = make_jrb();
  G.vertices = make_jrb();
  return G;
}

void addVertex(Graph G, int id, char *name){
  JRB node = jrb_find_int(G.vertices, id);
  if(!node){
    jrb_insert_int(G.vertices, id, new_jval_s(strdup(name)));
  }
}

// Them dinh danh ID cho dinh
char *getVertex(Graph G, int id){
  JRB isExist = jrb_find_int(G.vertices, id);
  if(!isExist)
    return NULL;
  return jval_s(isExist->val);
}

// Kiem tra ton tai lien ket v1->v2

int hasEdge(Graph G, int v1, int v2){
  JRB isExist = jrb_find_int(G.edges, v1);
  if(!isExist)
    return 0;
  if(jrb_find_int((JRB)jval_v(isExist->val), v2))
    return 1;
  else
    return 0;
}

// Them lien ket v1->v2

void addEdge(Graph G, int v1, int v2, double weight){
  JRB node, tree;
  if(!hasEdge(G, v1, v2)){ // Neu khong co lien ket v1->v2
    node = jrb_find_int(G.edges, v1);
    if(!node){// Neu v1 chua ton tai trong G.edges
      tree = make_jrb();
      // them v1 vao G.edges
      jrb_insert_int(G.edges,  v1, new_jval_v(tree));
    }
    else
      tree = (JRB)jval_v(node->val);
    jrb_insert_int(tree, v2, new_jval_d(weight)); // Them lien ket tu v1->v2
    //node = jrb_find_int(tree, v2);
    //node->val.d = weight;
  }
}

// Liên kết từ v đến cách đỉnh => Mang va so phan tu
int outdegree(Graph G, int v, int *output){
  JRB tree, node = jrb_find_int(G.edges, v);
  if(!node)
    return 0;

  int total = 0;
  tree = (JRB)jval_v(node->val);
  jrb_traverse(node, tree){
    output[total] = jval_i(node->key);
    total++;
  }
  return total;
}

// Lien ket tu cac dinh khac den v =>mang va so phan tu
int indegree(Graph G, int v, int *output){
  JRB node, tree, bn;
  int total = 0;
  // duyet tat ca cac dinh: Tim lien ket tu dinh den v
  jrb_traverse(bn, G.vertices){
    node = jrb_find_int(G.edges, jval_i(bn->key));
    if(node){ // Neu dinh co lien ket voi cac dinh khac
      tree = (JRB)jval_v(node->val);
      if(jrb_find_int(tree, v)){ // Neu dinh co lien ket den v
	output[total] = jval_i(node->key);
	total++;
      }
    }
  }
  return total;
}

double getEdgeValue(Graph G, int v1, int v2){
  JRB tree, node;
  if(!hasEdge) return INFINITE;
  else{
    tree= jrb_find_int(G.edges, v1);
    node = jrb_find_int((JRB)jval_v(tree->val), v2);
    return jval_d(node->val);
  }
}
// Kiem tra DAG
int DAG(Graph G){
  JRB bn;
  int n, output[100], visited[1000]={};
  Dllist stack = new_dllist(), node;
  int vertice, start;

  // Duyet theo chieu sau bat dau tu tung dinh
  jrb_traverse(bn, G.vertices){
    memset(visited, 0, sizeof(visited));
    start = jval_i(bn->key);
    dll_prepend(stack, new_jval_i(start));
    //printf("Vertice: %d\n", start);
    while(!dll_empty(stack)){
      node = dll_first(stack);
      vertice = jval_i(node->val);
      // printf("%d\t", vertice);
      dll_delete_node(node);
      
      n = outdegree(G, vertice, output);
      for(int i=0;i<n;i++){
	if(output[i] == start){
	  free_dllist(stack);
	  return 0;
	}
	if(!visited[output[i]]){
	  visited[output[i]]=1;
	  dll_prepend(stack, new_jval_i(output[i]));
	}
      }
    }
  }
  free_dllist(stack);
  return 1;
}

void dropGraph(Graph G){
  JRB node;
  jrb_free_tree(G.vertices);
  if(G.edges != NULL){
    jrb_traverse(node, G.vertices){
      jrb_free_tree((JRB)jval_v(node->val));
    }
    jrb_free_tree(G.edges);
  }
}
