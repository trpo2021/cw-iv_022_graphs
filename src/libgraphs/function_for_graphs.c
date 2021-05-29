#include "library.h"

void graph_initialization(struct graph *g, int max_city) {
  for (int i = 0; i < max_city; i++) {
    for (int j = i; j < max_city; j++) {
      graph_set_edge(g, i, j, get_length(i, j));
    }
  }
}

int get_length(int i, int j) {
  if (i == j) {
    return 0;
  }

  if ((i == 0) && (j == 1)) {
    return 17;
  }

  if ((i == 0) && (j == 2)) {
    return 25;
  }

  if ((i == 0) && (j == 3)) {
    return 25;
  }

  if ((i == 1) && (j == 2)) {
    return 13;
  }

  if ((i == 1) && (j == 3)) {
    return 16;
  }

  if ((i == 2) && (j == 3)) {
    return 15;
  }
  return 0;
}

void graph_clear(struct graph *g, int N) {
  for (int i = 1; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      g->m[i][j] = 0;
    }
  }
}

void graph_set_edge(struct graph *g, int i, int j, int w) {
  if (i == j) {
    g->m[i][j] = 0;
  } else {
    g->m[i][j] = w;
    g->m[j][i] = w;
  }
}

int graph_get_edge(struct graph *g, int i, int j) { return g->m[i][j]; }

struct graph *graph_create(int nvertices) {
  struct graph *g;
  g = malloc(sizeof(*g));

  if (g == NULL) {
    printf("Ошибка выделения памяти под граф\n");
    return NULL;
  }

  g->nvertices = nvertices;
  g->m = malloc(sizeof(int *) * nvertices);

  if (g->m == NULL) {
    printf("Ошибка выделения памяти в графе\n");
    free(g);
    return NULL;
  }

  for (int i = 0; i < nvertices; i++) {
    g->m[i] = malloc(sizeof(int) * nvertices);

    if (g->m[i] == NULL) {
      printf("Ошибка выделения памяти в графе\n");
      free(g->m);
      free(g);
      return NULL;
    }
  }

  graph_clear(g, nvertices);
  return g;
}

void graph_free(struct graph *g, int max_city) {

  for (int i = 0; i < max_city; i++) {
    free(g->m[i]);
  }

  free(g->m);
  free(g);
}