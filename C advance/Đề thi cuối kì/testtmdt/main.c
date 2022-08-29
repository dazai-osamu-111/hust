#include <stdio.h>
#include "undirected_graph.h"
#include <string.h>
#include <stdlib.h>
#define vantoc 30
void time(int a)
{
  int quangduong, gio, phut;
  quangduong = a + vantoc / 2;
  gio = quangduong / vantoc;
  phut = ((quangduong - gio * vantoc) * 60) / vantoc + 0.5;
  printf("%d gio %d phut\n", gio, phut);
}

Dllist outgoingVertices2(Graph g, int v);
double shortestPath2(Graph g, int source, int dest);

int main(int argc, char *argv[])
{
  int m, n;
  int i, j, a, b, c, d;
  FILE *ptr;
  char A[100];
  Graph g;
  JRB node1, node2;
  Dllist dllnode, list;
  switch (argc)
  {
  case 2:
    printf("C-Advanced, HK20182\n");
    return 0;

  case 3:
    if ((ptr = fopen(argv[2], "r")) == NULL)
    {
      printf("File %s is not exist!\n", argv[2]);
      return 1;
    }
    fscanf(ptr, "%d%*c%*c", &m);
    for (i = 0; i < m; i++)
    {
      fscanf(ptr, "%[^\n]%*c", A);
      puts(A);
    }
    fclose(ptr);
    return 0;

  case 6:
    if (strcmp(argv[1], "-w") == 0)
    {
      g = createGraph();

      if ((ptr = fopen(argv[3], "r")) == NULL)
      {
        printf("File %s is not exist!\n", argv[3]);
        return 1;
      }
      fscanf(ptr, "%d%*c%*c", &m);
      for (i = 0; i < m; i++)
      {
        fscanf(ptr, "%s%d%*c", A, &a);
        addVertex(g, 0 - a, A);
      }
      fclose(ptr);
      if ((ptr = fopen(argv[2], "r")) == NULL)
      {
        printf("File %s is not exist!\n", argv[2]);
        return 1;
      }
      fscanf(ptr, "%d%*c", &n);
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%s%d%*c", A, &a);
        addVertex(g, a, A);
        for (j = 0; j < m; j++)
        {
          fscanf(ptr, "%d%d%*c", &b, &c);
          addEdge(g, a, 0 - b, c);
        }
      }
      fscanf(ptr, "%d%*c", &n);
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%d%d%d%*c", &a, &b, &c);
        addEdge(g, a, b, c);
      }
      fclose(ptr);
      a = getEdgeValue(g, atoi(argv[4]), atoi(argv[5]));
      printf("%d km\n", a == INFINITIVE_VALUE ? -1 : a);
      dropGraph(g);
      return 0;
    }
    else if (strcmp(argv[1], "-h") == 0)
    {
      g = createGraph();

      if ((ptr = fopen(argv[3], "r")) == NULL)
      {
        printf("File %s is not exist!\n", argv[3]);
        return 1;
      }
      fscanf(ptr, "%d%*c%*c", &m);
      for (i = 0; i < m; i++)
      {
        fscanf(ptr, "%s%d%*c", A, &a);
        addVertex(g, 0 - a, A);
      }
      fclose(ptr);
      if ((ptr = fopen(argv[2], "r")) == NULL)
      {
        printf("File %s is not exist!\n", argv[2]);
        return 1;
      }
      fscanf(ptr, "%d%*c", &n);
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%s%d%*c", A, &a);
        addVertex(g, a, A);
        for (j = 0; j < m; j++)
        {
          fscanf(ptr, "%d%d%*c", &b, &c);
          addEdge(g, a, 0 - b, c);
        }
      }
      fscanf(ptr, "%d%*c", &n);
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%d%d%d%*c", &a, &b, &c);
        addEdge(g, a, b, c);
      }
      fclose(ptr);

      a = atoi(argv[5]);
      b = 0 - atoi(argv[4]);

      node1 = jrb_find_int(g.vertices, a);

      if (node1 == NULL)
      {
        printf("Khong ton tai kho hang %d\n", a);
        dropGraph(g);
        return 1;
      }

      printf("%s:\n", getVertexName(g, a));
      printf("%-10s: %d\n\n", getVertexName(g, b), (int)getEdgeValue(g, a, b));
      printf("--- Cac kho ke la: \n");
      list = outgoingVertices(g, a);
      dll_traverse(dllnode, list)
      {
        if (jval_i(dll_val(dllnode)) > 0)
        {
          printf("%s:\n", getVertexName(g, jval_i(dll_val(dllnode))));
          printf("%-10s: %d\n\n", getVertexName(g, b), (int)getEdgeValue(g, jval_i(dll_val(dllnode)), b));
        }
      }

      dropGraph(g);
      return 0;
    }
  case 4:
    g = createGraph();

    if ((ptr = fopen(argv[3], "r")) == NULL)
    {
      printf("File %s is not exist!\n", argv[3]);
      return 1;
    }
    fscanf(ptr, "%d%*c%*c", &m);
    for (i = 0; i < m; i++)
    {
      fscanf(ptr, "%s%d%*c", A, &a);
      addVertex(g, 0 - a, A);
    }
    fclose(ptr);
    if ((ptr = fopen(argv[2], "r")) == NULL)
    {
      printf("File %s is not exist!\n", argv[2]);
      return 1;
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
      fscanf(ptr, "%s%d%*c", A, &a);
      addVertex(g, a, A);
      for (j = 0; j < m; j++)
      {
        fscanf(ptr, "%d%d%*c", &b, &c);
        addEdge(g, a, 0 - b, c);
      }
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
      fscanf(ptr, "%d%d%d%*c", &a, &b, &c);
      addEdge(g, a, b, c);
    }
    fclose(ptr);
    jrb_traverse(node1, g.vertices)
    {
      if (jval_i(node1->key) > 0)
      {
        printf("%s:\n", getVertexName(g, jval_i(node1->key)));
        list = outgoingVertices(g, jval_i(node1->key));
        dll_rtraverse(dllnode, list)
        {
          if (jval_i(dll_val(dllnode)) < 0)
          {
            printf("%-10s: %d\n", getVertexName(g, jval_i(dll_val(dllnode))), (int)getEdgeValue(g, jval_i(node1->key), jval_i(dll_val(dllnode))));
          }
        }
        free_dllist(list);
        printf("\n-------\n");
      }
    }
    dropGraph(g);
    return 0;

  case 8:
    g = createGraph();

    if ((ptr = fopen(argv[3], "r")) == NULL)
    {
      printf("File %s is not exist!\n", argv[3]);
      return 1;
    }
    fscanf(ptr, "%d%*c%*c", &m);
    for (i = 0; i < m; i++)
    {
      fscanf(ptr, "%s%d%*c", A, &a);
      addVertex(g, 0 - a, A);
    }
    fclose(ptr);
    if ((ptr = fopen(argv[2], "r")) == NULL)
    {
      printf("File %s is not exist!\n", argv[2]);
      return 1;
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
      fscanf(ptr, "%s%d%*c", A, &a);
      addVertex(g, a, A);
      for (j = 0; j < m; j++)
      {
        fscanf(ptr, "%d%d%*c", &b, &c);
        addEdge(g, a, 0 - b, c);
      }
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
      fscanf(ptr, "%d%d%d%*c", &a, &b, &c);
      addEdge(g, a, b, c);
    }
    fclose(ptr);
    a = 0 - atoi(argv[4]);
    b = atoi(argv[5]);
    c = atoi(argv[6]);
    d = atoi(argv[7]);
    if (((int)getEdgeValue(g, c, a) + (int)getEdgeValue(g, d, a)) >= b)
    {
      i = (int)shortestPath2(g, d, c);

      printf("Dat hang thanh cong!\nThoi gian giao hang la: ");
      time(i);
    }
    else
    {
      printf("Dat hang khong thanh cong!\n");
    }
    dropGraph(g);
    return 0;

  case 0:
    return 0;
  }
}

Dllist outgoingVertices2(Graph g, int v)
{
  JRB node, l, i;
  Dllist output = new_dllist();

  if ((node = jrb_find_int(g.edges, v)) == NULL)
    return output;

  l = (JRB)jval_v(node->val);
  jrb_traverse(i, l)
  {
    if (jval_i(i->key) > 0)
      dll_append(output, i->key);
  }
  return output;
}
double shortestPath2(Graph g, int source, int dest)
{
  JRB visited = make_jrb();
  JRB cost = make_jrb();
  JRB parent = make_jrb();
  JRB node;
  Dllist q = new_dllist();
  Dllist path;
  Dllist n;
  Dllist adjs;
  int u;
  double k, i, j;
  dll_append(q, new_jval_i(source));
  jrb_traverse(node, g.vertices)
  {
    jrb_insert_int(cost, jval_i(node->key), new_jval_d(INFINITIVE_VALUE));
  }
  jrb_find_int(cost, source)->val = new_jval_d(0);
  while (1)
  {
    n = dll_min(q, cost, visited);
    if (n == NULL)
    {
      printf("No road from %d to %d\n", source, dest);
      jrb_free_tree(visited);
      jrb_free_tree(cost);
      jrb_free_tree(parent);
      free_dllist(q);
      return u;
    }
    u = jval_i(dll_val(n));
    dll_delete_node(n);
    if (u == dest)
      break;
    k = jval_d(jrb_find_int(cost, u)->val); //gia tri cua cost u
    jrb_insert_int(visited, u, new_jval_i(1));
    adjs = outgoingVertices2(g, u);
    dll_traverse(n, adjs)
    {
      if (jrb_find_int(visited, jval_i(dll_val(n))) == NULL)
      {
        node = jrb_find_int(cost, jval_i(dll_val(n))); //gia tri cua cost node
        i = getEdgeValue(g, u, jval_i(dll_val(n)));
        if (jval_d(node->val) > i + k)
        {
          node->val = new_jval_d(i + k);

          node = jrb_find_int(parent, jval_i(dll_val(n)));
          if (node == NULL)
          {
            jrb_insert_int(parent, jval_i(dll_val(n)), new_jval_i(u));
            node = jrb_find_int(parent, jval_i(dll_val(n)));
          }
          else
            node->val = new_jval_i(u);
        }
        dll_append(q, dll_val(n));
      }
    }

    free_dllist(adjs);
  }
  j = jval_d(jrb_find_int(cost, dest)->val);

  jrb_free_tree(visited);
  jrb_free_tree(cost);
  jrb_free_tree(parent);
  free_dllist(q);

  return j;
}