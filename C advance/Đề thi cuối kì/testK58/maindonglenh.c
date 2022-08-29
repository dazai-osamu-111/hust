#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directed_graph.h"

Graph readfile(char *filename);
int check1(Dllist list, Dllist node);
void cau4(Graph g, int i, int j);
void cau5(Graph g, int i, int j);
void cau6(Graph g, int k);
void check2(Graph g, JRB visited, int id);
void cau7(Graph g, int id);

int main(int argc, char *argv[])
{

    Graph g;

    switch (argc)
    {
    case 2:
        if (strcmp(argv[1], "help") == 0)
        {
            printf("Supported command: help, about, i2n, n2i, cc, cr, odg, rel.\n");
        }
        else if (strcmp(argv[1], "about") == 0)
        {
            printf("C advanced 20142 final exam.\n");
        }
        else
        {
            printf("Syntax ERROR!\n");
        }
        return 0;
    case 4:
        if (strcmp(argv[1], "i2n") == 0)
        {
            g = readfile(argv[2]);
            printf("%s\n", getVertexName(g, atoi(argv[3])));
            dropGraph(g);
            return 0;
        }
        else if (strcmp(argv[1], "n2i") == 0)
        {
            g = readfile(argv[2]);
            printf("%d\n", getVertexId(g, argv[3]));
            dropGraph(g);
            return 0;
        }
        else if (strcmp(argv[1], "odg") == 0)
        {
            g = readfile(argv[2]);
            cau6(g, atoi(argv[3]));
            dropGraph(g);
            return 0;
        }
        else if (strcmp(argv[1], "rel") == 0)
        {
            g = readfile(argv[2]);
            cau7(g, atoi(argv[3]));
            dropGraph(g);
            return 0;
        }
        return 0;
    case 5:
        if (strcmp(argv[1], "cc") == 0)
        {
            g = readfile(argv[2]);
            cau4(g, atoi(argv[3]), atoi(argv[4]));
            dropGraph(g);
            return 0;
        }
        else if (strcmp(argv[1], "cr") == 0)
        {
            g = readfile(argv[2]);
            cau5(g, atoi(argv[3]), atoi(argv[4]));
            dropGraph(g);
            return 0;
        }
    }
}
Graph readfile(char *filename)
{
    Graph g;
    int n, id, N, M, i;
    char A[100];
    FILE *ptr;
    if ((ptr = fopen(filename, "r")) == NULL)
    {
        printf("Cannot find input file!\n");
        return g;
    }
    g = createGraph();
    fscanf(ptr, "%d%d%*c", &N, &M);
    for (i = 0; i < N; i++)
    {
        fscanf(ptr, "%s%d%*c", A, &id);
        addVertex(g, id, A);
    }
    for (i = 0; i < M; i++)
    {
        fscanf(ptr, "%d%d", &id, &n);
        addEdge(g, id, n, 1);
    }
    fclose(ptr);
    return g;
}
int check1(Dllist list, Dllist node)
{
    Dllist nodedll;
    dll_traverse(nodedll, list)
    {
        if (jval_i(dll_val(node)) == jval_i(dll_val(nodedll)))
            return 1;
    }
    return 0;
}
void cau4(Graph g, int i, int j)
{
    Dllist list1, list2, nodedll;
    list1 = outgoingVertices(g, i);
    list2 = outgoingVertices(g, j);
    dll_traverse(nodedll, list1)
    {
        if (check1(list2, nodedll))
        {
            printf("%s\n", getVertexName(g, jval_i(dll_val(nodedll))));
        }
    }
    free_dllist(list1);
    free_dllist(list2);
}

void cau5(Graph g, int i, int j)
{
    Dllist list1, list2, nodedll;
    list1 = incomingVertices(g, i);
    list2 = incomingVertices(g, j);
    dll_traverse(nodedll, list1)
    {
        if (check1(list2, nodedll))
        {
            printf("%s\n", getVertexName(g, jval_i(dll_val(nodedll))));
        }
    }
    free_dllist(list1);
    free_dllist(list2);
}

void cau6(Graph g, int k)
{
    JRB node;
    int id;
    jrb_traverse(node, g.vertices)
    {
        id = jval_i(node->key);
        if (outgoingVerticesNumber(g, id) > k)
        {
            printf("%s\n", getVertexName(g, id));
        }
    }
}

void check2(Graph g, JRB visited, int id)
{
    if (jrb_find_int(visited, id) == NULL)
    {
        jrb_insert_int(visited, id, new_jval_i(1));
        printf("%s\n", getVertexName(g, id));
    }
}

void cau7(Graph g, int key)
{
    Dllist list, list2, nodedll, nodedll2;
    int id;
    JRB visited = make_jrb();
    list = outgoingVertices(g, key);
    dll_traverse(nodedll, list)
    {
        id = jval_i(dll_val(nodedll));
        check2(g, visited, id);
        list2 = outgoingVertices(g, id);
        dll_traverse(nodedll2, list2)
        {
            check2(g, visited, jval_i(dll_val(nodedll2)));
        }
        free_dllist(list2);
    }
    jrb_free_tree(visited);
    free_dllist(list);
}