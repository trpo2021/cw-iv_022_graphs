#include <stdio.h>
#include <stdlib.h>

int *graph_adj;
int graph_adj_size;
int graph_adj_initialized = 0;

int graph_adj_init(int size) {
  graph_adj_size = size;
  graph_adj = (int *)malloc(graph_adj_size * graph_adj_size * sizeof(int));

  if (graph_adj != NULL) {
    int r, c;
    for (r = 0; r < graph_adj_size; r++)
      for (c = 0; c < graph_adj_size; c++)
        graph_adj[r * graph_adj_size + c] = 0;
    graph_adj_initialized = 1;
    return 0;
  } else {
    return -1;
  }
}

int graph_adj_add(int row, int col) {
  if (graph_adj_initialized < 0) {
    return -1;
  }
  graph_adj[(row * graph_adj_size + col)] = 1;
  return 0;
}

int graph_adj_print() {
  if (graph_adj_initialized < 0) {
    return -1;
  }

  int r, c;
  for (r = 0; r < graph_adj_size; r++) {
    for (c = 0; c < graph_adj_size; c++) {
      if (r == c) {
        printf("x ");
      } else if (graph_adj[r * graph_adj_size + c] == 0) {
        printf("- ");
      } else {
        printf("%d ", graph_adj[r * graph_adj_size + c]);
      }
    }
    printf("\n");
  }
  return 0;
}

void graph_adj_free() { free(graph_adj); }

int *graph_adj_get() { return graph_adj; }