#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "directed_graph.h"

int getID(char *A);
int hoi();
void cau5(Graph g);
void cau7(Graph g);

int main()
{
  int key;

  Graph g = createGraph();
  JRB node;
  char A[100], B, C;
  int n, dest, source, edge;
  Dllist list, nodedll;
  FILE *ptr;
  while (1)
  {
    printf("\n\nQuan ly cac mon hoc\n"
           "1.Doc du lieu\n"
           "2.Kiem tra tinh hop le do thi topo\n"
           "3.Nhap vao 1 mon hoc va in ra thong bao\n"
           "4.Hoi yeu cau co thuc hien viec 3 hay khong\n"
           "5.In danh sach cac mon hoc theo nguyen tac\n"
           "6.In 1 thu tu sap xep cac mon hoc theo trinh tu truoc-sau\n"
           "7.In trinh tu hoc tap hop le\n"
           "8.Thoat va giai phong bo nho\n"
           "Choose: ");
    scanf("%d%*c", &key);
    printf("\n");
    switch (key)
    {
    case 1:
      printf("Nhap ten file input: ");
      scanf("%s%*c", A);
      if ((ptr = fopen(A, "r")) == NULL)
      {
        printf("Khong ton tai file %s\n", A);
        return 0;
      }
      edge = 0;
      n = 0;
      fgets(A, 100, ptr);
      C = A[strlen(A) - 1];
      fseek(ptr, SEEK_SET, 0);
      while (!feof(ptr))
      {
        fscanf(ptr, "%s%*c%*c%c", A, &B);
        dest = getID(A);
        //printf("Dest: %d\n",dest);
        addVertex(g, dest, A);
        while (B != C && !feof(ptr))
        {
          fscanf(ptr, "%s%c", A, &B);
          source = getID(A);
          // printf("Source: %d\n",source);
          addVertex(g, source, A);
          addEdge(g, source, dest, 1);
          edge++;
        }
      }
      jrb_traverse(node, g.vertices)
      {
        n++;
      }
      printf("So nut: %d\nSo cung: %d\n", n, edge);
      fclose(ptr);
      break;
    case 2:
      n = isDAG(g);
      if (n == 1)
      {
        printf("Do thi khong co chu trinh!\n");
      }
      else
      {
        printf("Do thi co chu trinh!\n");
        dropGraph(g);
        return 1;
      }
      break;
    case 3:
      do
      {
        printf("Nhap ma mon hoc: ");
        scanf("%s%*c", A);
        source = getVertexId(g, A);
        if (source == -1)
        {
          printf("Ma mon hoc khong co trong chuong trinh!\n");
        }
        else
        {
          printf("So mon phai hoc truoc la: %d mon\n", incomingVerticesNumber(g, source));
        }
      } while (hoi());
    case 5:
      cau5(g);
      break;
    case 6:
      list = topologicalSort(g);
      dll_traverse(nodedll, list)
      {
        n = jval_i(dll_val(nodedll));
        printf("%s ", getVertexName(g, n));
      }
      free_dllist(list);
      break;
    case 7:
      printf("Lich hoc tap: \n\n");
      cau7(g);
      break;
    case 8:
      dropGraph(g);
      return 0;
      break;

    default:
      printf("Please choose only 1-\n");
      break;
    }
  }
}

int getID(char *A)
{
  for (int i = 0; i < strlen(A); i++)
    if (isdigit(A[i]))
      return atoi(&A[i]);
}

int hoi()
{
  char key;
  printf("Co muon thuc hien cong viec 3 nua khong? (y/n)\n");
  scanf("%c%*c", &key);
  if (key == 'y')
    return 1;
  else
    return 0;
}
void cau5(Graph g)
{
  JRB node;
  int max = 0, i, id, num;
  jrb_traverse(node, g.vertices)
  {
    id = jval_i(node->key);
    num = incomingVerticesNumber(g, id);
    if (i > max)
      max = num;
  }
  for (i = 0; i <= max; i++)
  {
    jrb_traverse(node, g.vertices)
    {
      id = jval_i(node->key);
      num = incomingVerticesNumber(g, id);
      if (num == i)
      {
        printf("%s ", jval_s(node->val));
      }
    }
    printf("\n");
  }
}
void cau7(Graph g)
{
  Dllist list = topologicalSort(g), nodedll;
  int i = 0, count;
  while (!dll_empty(list))
  {
    count = 0;
    i++;
    printf("Hoc ki %d: ",i);
    while (count < 4 && !dll_empty(list))
    {
      nodedll=dll_first(list);
      printf("%s ", getVertexName(g, jval_i(dll_val(nodedll))));
      dll_delete_node(nodedll);
      count++;
    }
    printf("\n");
  }
  free_dllist(list);
}