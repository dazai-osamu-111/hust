#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "undirected_graph.h"

void cau2(Graph g);
void cau3(Graph g);
void cau4(Graph g);

int main()
{
  int key;
  int m, n, i, a, b;
  double weight;
  int id;
  char A[100];
  JRB node;
  FILE *ptr;
  Graph g = createGraph();
  while (1)
  {
    printf("\nMang xa hoi\n"
           "1.In danh sach dinh\n"
           "2.Tim ban than thiet nhat\n"
           "3.Kiem tra quan he bac cau\n"
           "4.In danh sach ban chung\n"
           "5.Thoat va giai phong bo nho\n"
           "Choose: ");
    scanf("%d%*c", &key);
    printf("\n");
    switch (key)
    {
    case 1:
      if ((ptr = fopen("data.txt", "r")) == NULL)
      {
        printf("Khong doc duoc file data.txt\n");
        return 0;
      }
      fscanf(ptr, "%d%d", &m, &n);
      for (i = 0; i < m; i++)
      {
        fscanf(ptr, "%d%*c%s", &id, A);
        addVertex(g, id, A);
      }
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%d%d%lf", &a, &b, &weight);
        addEdge(g, a, b, weight);
      }
      jrb_traverse(node, g.vertices)
      {
        id = jval_i(node->key);
        printf("%d %s\n", id, getVertexName(g, id));
      }
      break;
    case 2:
      cau2(g);
      break;
    case 3:
      cau3(g);
      break;
    case 4:
      cau4(g);
      break;
    case 5:
      dropGraph(g);
      return 0;
      break;

    default:
      printf("Please choose only 1-5\n");
      break;
    }
  }
}

void cau2(Graph g)
{
  int id, id2;
  double weight, max = 0;
  Dllist list, nodedll;
  printf("Nhap id muon tra cuu ban be: ");
  scanf("%d", &id);
  if (outgoingVerticesNumber(g, id) == 0)
  {
    printf("-1\n");
    return;
  }
  list = outgoingVertices(g, id);
  dll_traverse(nodedll, list)
  {
    id2 = jval_i(dll_val(nodedll));
    weight = getEdgeValue(g, id, id2);
    if (weight > max)
      max = weight;
  }
  printf("%f\n", max);
  dll_traverse(nodedll, list)
  {
    id2 = jval_i(dll_val(nodedll));
    weight = getEdgeValue(g, id, id2);
    if (weight == max)
      printf("%d %s\n", id2, getVertexName(g, id2));
  }
  free_dllist(list);
}

void cau3(Graph g)
{
  int source, dest;
  printf("Nhap lan luot id1 va id2: ");
  scanf("%d%d%*c", &source, &dest);
  if (hasEdge(g, source, dest))
  {
    printf("-1\n");
    return;
  }
  if (shortestPath(g, source, dest) == INFINITIVE_VALUE)
  {
    printf("-1\n");
    return;
  }
  else
  {
    printf("1\n");
    return;
  }
}

void cau4(Graph g)
{
  int id1, id2, num = 0;
  Dllist list1, list2, list3 = new_dllist();
  Dllist nodedll1, nodedll2;
  printf("Nhap lan luot id1 va id2: ");
  scanf("%d%d%*c", &id1, &id2);
  list1 = outgoingVertices(g, id1);
  list2 = outgoingVertices(g, id2);
  dll_traverse(nodedll1, list1)
  {
    id1 = jval_i(dll_val(nodedll1));
    dll_traverse(nodedll2, list2)
    {
      id2 = jval_i(dll_val(nodedll2));
      if (id1 == id2)
      {
        num++;
        dll_append(list3, new_jval_i(id1));
      }
    }
  }
  printf("%d\n",dll_empty(list3)?-1:num);
  dll_traverse(nodedll1, list3)
  {
    id1 = jval_i(dll_val(nodedll1));
    printf("%d %s\n", id1, getVertexName(g, id1));
  }
  free_dllist(list1);
  free_dllist(list2);
  free_dllist(list3);
}