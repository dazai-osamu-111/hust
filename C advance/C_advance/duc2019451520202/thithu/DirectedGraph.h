#include<stdio.h>
#include "jrb.h"
#include "dllist.h"
#include <string.h>
#define INFINITE 10000000
typedef struct{
  JRB edges;
  JRB vertices;
} Graph;

Graph createGraph();
void addVertex(Graph G, int id, char *name);
char *getVertex(Graph G, int id);
void addEdge(Graph G, int v1, int v2, double weight);
int hasEdge(Graph G, int v1, int v2);
int outdegree(Graph G, int v, int *output);
int indegree(Graph G, int v, int *output);
double shortestPath(Graph G, int s,int t,  int *path, int *length);
double getEdgeValue(Graph G, int v1, int v2); // Return INFINITE if no edge between v1 and v2
int DAG(Graph G);
void dropGraph(Graph G);

