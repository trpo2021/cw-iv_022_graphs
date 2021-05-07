#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

struct graph {
int nvertices; // Число вершин
int **m; // Матрица n x n
int *visited;
};

int getrand(int min, int max);

void DijkstraShort(struct graph *g, int src, int *d, int **prev);
void DijkstraLong(struct graph *g, int src, int *d, int **prev);
int SearchShortPath(struct graph* g, int src, int dst, int* path);
int SearchLongPath(struct graph* g, int src, int dst, int* path);
void AllPaths(int *array_cities);
void Length_and_Paths(int *array_cities, struct graph *g);

void graph_clear(struct graph *g, int N);
void graph_set_edge(struct graph *g, int i, int j, int w);
int graph_get_edge(struct graph *g, int i, int j);
struct graph *graph_create(int nvertices);
void graph_free(struct graph *g, int N);

typedef struct 
{
    int key;
    int value;
} heapnode;

typedef struct 
{
    int *index;
    int maxsize;
    int nnodes;
    heapnode *nodes;
} heap;


heap *heap_create(int maxsize);
void heap_free(heap *h);
void heap_swap(heapnode *a, heapnode *b, heap *h);
int heap_insert(heap *h, int key, int value);
heapnode heap_extract_min(heap *h);
heapnode heap_extract_max(heap *h);
void heap_heapify_min(heap *h, int index);
void heap_heapify_max(heap *h, int index);
int heap_decrease_key(heap *h, int index, int key);
int heap_increase_key(heap *h, int index, int key);
