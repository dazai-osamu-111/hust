#include<stdio.h>
#include "Graphjrb.h"
int main(){
  Graph tmp;
  Graph G= createGraph();
  char *output[50];
  int n;
  addEdge(G, "s1", "s2");
  addEdge(G, "s1", "s3");
  addEdge(G, "s1", "s4");
  addEdge(G, "s1", "s5");
  addEdge(G, "s2", "s4");
  addEdge(G, "s2", "s3");
  addEdge(G, "s2", "s5");
  addEdge(G, "s3", "s2");
  addEdge(G, "s3", "s7");
  addEdge(G, "s3", "s6");
  addEdge(G, "s1", "s7");
  jrb_traverse(tmp, G){
    n = getAdjacentVertices(G, jval_s(tmp->key), output);
    printf("%s: ", jval_s(tmp->key));
    for(int i=0; i< n;i++){
      printf("%s ", output[i]);
    }
    printf("\n");
  }
  dropGraph(G);
  return 0;
}
