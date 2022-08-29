#include<stdio.h>
#include <stdlib.h>
typedef struct{
  int *matrix;
  int sizemax;
} Graph;

Graph creatGraph(int sizemax){
  Graph G; int i;
  G.matrix = malloc( sizemax*sizemax * sizeof(int));
  G.sizemax = sizemax;
  for(i=0;i < sizemax*sizemax; i++){
    *(G.matrix+i)=0;
  }
  return G;
}

void addEdge(Graph graph, int v1, int v2){
  graph.matrix[v1*graph.sizemax + v2] = 1;
  graph.matrix[v2*graph.sizemax + v1] = 1;
}

int adjacent(Graph graph, int v1, int v2){
  return graph.matrix[v1 * graph.sizemax + v2];
}

int getAdjacentVertices(Graph graph, int v, int* output){
  int i, count=0;
  for(i=0;(v* graph.sizemax+i) < (v*graph.sizemax+graph.sizemax);i++){
    if(graph.matrix[v*graph.sizemax+i] == 1){
      output[count]=i;
      //printf("%d\n", output[i]);
      count++;
    }
  }
  return count;
}

void dropGraph(Graph g){
  free(g.matrix);
}
int main(){
  int i,n, output[10];
  Graph g = creatGraph(10);
  //Check graph
  //for(i=0;i<10;i++) printf("%d\t", g.matrix[i]);
  //printf("\n");
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 1, 3);

  // Check addEdge
  /*for(i=0;i<g.sizemax;i++){
    for(int j=0;j<g.sizemax;j++){
    printf("%2d", g.matrix[i*g.sizemax+j]);
    }
    printf("\n");
    }*/
  n = getAdjacentVertices(g, 1, output);
  if( n==0) printf("No adjacent vetices of node 1\n");
  else{
    printf("Adjacent vertices of node 1:");
    for(i=0; i< n;i++) printf("%5d", output[i]);
  }
  printf("\n");
  dropGraph(g);
  printf("Memory freed.\n");
  return 0;
}
