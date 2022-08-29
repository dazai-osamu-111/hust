#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "undirected_graph.h"

Graph readfile(char *filename);
int check(int id, int *array, int n);
int checkback(int id, int *array, int point);
int compare(const void *x, const void *y);

int main(int argc, char *argv[])
{

    Graph g;
    int id;
    int *array, n, i, count;
    JRB node;
    Dllist list, nodedll;
    if (strcmp(argv[1], "-s") == 0)
    {
        g = readfile(argv[2]);
        n = argc - 3;
        array = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            array[i] = atoi(argv[i + 3]);
        }

        qsort(array, n, sizeof(int), compare);

        printf("%d\n", n);

        for (i = 0; i < n; i++)
            printf("%d %s\n", array[i], getVertexName(g, array[i]));

        count = 0;

        for (i = 0; i < n; i++)
        {
            list = outgoingVertices(g, array[i]);
            dll_traverse(nodedll, list)
            {
                if (check(jval_i(dll_val(nodedll)), array, n) && checkback(jval_i(dll_val(nodedll)), array, i))
                    count++;
            }
            free_dllist(list);
        }

        printf("%d\n", count);

        for (i = 0; i < n; i++)
        {
            list = outgoingVertices(g, array[i]);
            dll_traverse(nodedll, list)
            {
                if (check(jval_i(dll_val(nodedll)), array, n) && checkback(jval_i(dll_val(nodedll)), array, i))
                    printf("%d %d %d\n", array[i], jval_i(dll_val(nodedll)), (int)getEdgeValue(g, array[i], jval_i(dll_val(nodedll))));
            }
            free_dllist(list);
        }

        free(array);
        dropGraph(g);
        return 0;
    }
    switch (argc)
    {
    case 2:
        printf("C-Advanced, HK20152\n");
        return 0;
    case 3:
        g = readfile(argv[2]);
        jrb_traverse(node, g.vertices)
        {
            id = jval_i(node->key);
            printf("%d %s\n", id, getVertexName(g, id));
        }
        dropGraph(g);
        return 0;
    case 5:
        if (strcmp(argv[1], "-w") == 0)
        {
            g = readfile(argv[2]);
            id = (int)getEdgeValue(g, atoi(argv[3]), atoi(argv[4]));
            printf("%d\n", id == INFINITIVE_VALUE ? -1 : id);
            dropGraph(g);
            return 0;
        }
        else if (strcmp(argv[1], "-p") == 0)
        {
            g = readfile(argv[2]);
            shortestPath(g, atoi(argv[3]), atoi(argv[4]));
            dropGraph(g);
            return 0;
        }
    case 4:
        g = readfile(argv[2]);
        printf("%d\n", outgoingVerticesNumber(g, atoi(argv[3])));
        list = outgoingVertices(g, atoi(argv[3]));
        dll_traverse(nodedll, list)
        {
            id = jval_i(dll_val(nodedll));
            printf("%d %s %d\n", id, getVertexName(g, id), (int)getEdgeValue(g, atoi(argv[3]), id));
        }
        free_dllist(list);
        dropGraph(g);
        return 0;
    }
}

Graph readfile(char *filename)
{
    Graph g = createGraph();
    int n, i;
    int id, id2, kc;
    char A[100];
    FILE *ptr;
    if ((ptr = fopen(filename, "r")) == NULL)
    {
        printf("Cannot find input file!\n");
        return g;
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(ptr, "%d%s%*c", &id, A);
        addVertex(g, id, A);
    }
    fscanf(ptr, "%d%*c", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(ptr, "%d%d%d%*c", &id, &id2, &kc);
        addEdge(g, id, id2, kc);
    }
    fclose(ptr);
    return g;
}

int check(int id, int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (id == array[i])
            return 1;
    }
    return 0;
}
int checkback(int id, int *array, int point)
{
    for (int i = 0; i < point; i++)
    {
        if (id == array[i])
            return 0;
    }
    return 1;
}
int compare(const void *x, const void *y)
{
    int m = *(int *)x;
    int n = *(int *)y;
    if (m == n)
        return 0;
    return m > n ? 1 : -1;
}