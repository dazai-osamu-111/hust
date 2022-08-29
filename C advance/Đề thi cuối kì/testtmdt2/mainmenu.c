#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "undirected_graph.h"
void cau2(Graph g);
void cau3(Graph g);
void cau4(Graph g);
void cau5(Graph g);

    int main()
{
  char key;
  FILE *ptr;
  char A[100];
  int id;
  JRB node;
  Graph g = createGraph();
  while (1)
  {
    printf("\n\nThuong mai dien tu\n"
           "1.Doc va in danh sach san pham\n"
           "2.Doc va in sanh sach giao dich\n"
           "3.Hien thi muc do lien quan giua 2 SP\n"
           "4.In danh sach cac SP lien quan\n"
           "5.Hien thi moi lien he giua 2 san pham\n"
           "6.Thoat va giai phong bo nho\n"
           "Choose: ");
    scanf("%c%*c", &key);
    printf("\n");
    switch (key)
    {
    case '1':
      if ((ptr = fopen("products.txt", "r")) == NULL)
      {
        printf("Cannot open products.txt file!\n");
        return 1;
      }
      while (fscanf(ptr, "%d%*c%s", &id, A) == 2)
      {
        addVertex(g, id, A);
      }
      jrb_traverse(node, g.vertices)
      {
        id = jval_i(node->key);
        printf("Ma san pham: %d\nTen san pham: %s\n\n", id, getVertexName(g, id));
      }
      break;
    case '2':
      cau2(g);
      break;
    case '3':
      cau3(g);
      break;
    case '4':
      cau4(g);
      break;
    case '5':
      cau5(g);
      break;
    case '6':
      dropGraph(g);
      return 0;

    default:
      printf("Please choose only 1-6\n");
      break;
    }
  }
}

void cau2(Graph g)
{
  FILE *ptr;
  JRB node, node2;
  int array[100], count, i, check;
  char B, C;
  char A[100];
  if ((ptr = fopen("orderhistory.txt", "r")) == NULL)
  {
    printf("Cannot open orderhistory.txt file!\n");
    return;
  }
  fgets(A, 100, ptr);
  C = A[strlen(A) - 2];
  fseek(ptr, SEEK_SET, 0);
  while (!feof(ptr))
  {
    for (i = 0; i < 100; i++)
      array[i] = 0;
    count = 0;
    B = '1';
    while (B != C && !feof(ptr))
    {
      fscanf(ptr, "%s%c", A, &B);
      // printf("A: %s, B:%c\n", A, B);
      array[count] = atoi(A);
      // printf("Array[count]: %d\n",array[count]);
      count++;
      // printf("Count: %d\n",count);
      for (i = 0; i < (count - 1); i++)
      {
        check = 0;
        // if(array[i]==array[count])
        // printf("count: %d %d, i=%d %d\n", count, array[count - 1], i, array[i]);
        if ((node = jrb_find_int(g.edges, array[i])) != NULL)
        {
          if ((node2 = jrb_find_int((JRB)(jval_v(node->val)), array[count - 1])) != NULL)
          {
            check = 1;
            node2->val = new_jval_d(jval_d(node2->val) + 1);
          }
        }
        if ((node = jrb_find_int(g.edges, array[count - 1])) != NULL)
        {
          if ((node2 = jrb_find_int((JRB)(jval_v(node->val)), array[i])) != NULL)
          {
            check = 1;
            node2->val = new_jval_d(jval_d(node2->val) + 1);
          }
        }
        if (check == 0)
        {
          addEdge(g, array[count - 1], array[i], 1);
        }
        // printf("%d -> %d\n", array[count - 1], array[i]);
      }
    }
    for (i = 0; i < count; i++)
    {
      printf("%s ", getVertexName(g, array[i]));
    }
    printf("\n");
  }
  fclose(ptr);
}

void cau3(Graph g)
{
  int id1, id2;
  int weight;
  printf("Nhap vao lan luot ma so 2 san pham: ");
  scanf("%d%d%*c", &id1, &id2);
  weight = getEdgeValue(g, id1, id2);
  printf("Do lien quan giua 2 san pham: %d\n", weight == INFINITIVE_VALUE ? -1 : weight);
}

void cau4(Graph g)
{
  int id1, id2;
  double max, weight;
  Dllist list, nodedll;
  printf("Nhap vao ma san pham: ");
  scanf("%d%*c", &id1);
  printf("Cac san pham lien quan: ");
  list = outgoingVertices(g, id1);
  while (!dll_empty(list))
  {
    max = 0;
    dll_traverse(nodedll, list)
    {
      id2 = jval_i(dll_val(nodedll));
      weight = getEdgeValue(g, id1, id2);
      if (weight > max)
        max = weight;
    }
    dll_traverse(nodedll, list)
    {
      id2 = jval_i(dll_val(nodedll));
      weight = getEdgeValue(g, id1, id2);
      if (weight == max)
      {
        printf("%s ", getVertexName(g, id2));
        break;
      }
    }
    dll_delete_node(nodedll);
  }
  printf("\n");
  free_dllist(list);
}

void cau5(Graph g)
{
  int id1, id2;
  printf("Nhap vao ma so 2 san pham: ");
  scanf("%d%d%*c", &id1, &id2);
  shortestPath(g, id1, id2);
}