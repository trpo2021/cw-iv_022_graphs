#include <stdio.h>
#include <stdlib.h>

int *visited;
int *graph_adj;
int graph_adj_size;
int *path;
int path_index;

int flag; // 0 - все пути, 1 - короткий, 2 - длинный
int *shortest_path;
int shortest_path_len;
int *longest_path;
int longest_path_len;

int all_paths_init(int *g_adj, int g_adj_size, int aflag) {
  graph_adj = g_adj;
  graph_adj_size = g_adj_size;
  flag = aflag;

  visited = (int *)malloc(graph_adj_size * sizeof(int));
  path = (int *)malloc(graph_adj_size * sizeof(int));
  shortest_path = (int *)malloc(graph_adj_size * sizeof(int));
  shortest_path_len = graph_adj_size + 1;
  longest_path = (int *)malloc(graph_adj_size * sizeof(int));
  longest_path_len = 0;

  path_index = 0;
  if ((visited != NULL) && (path != NULL)) {
    for (int i = 0; i < graph_adj_size; i++) {
      visited[i] = 0;
      path[i] = 0;
    }
    return 0;
  } else {
    return -1;
  }
}

int all_paths_print_recur(int node, int dst, int visited[], int path[],
                          int *path_index) {
  visited[node] = 1;
  path[*path_index] = node;
  (*path_index)++;

  if (node == dst) {
    if ((*path_index) < shortest_path_len) {
      shortest_path_len = *path_index;
      for (int i = 0; i < (*path_index); i++)
        shortest_path[i] = path[i];
    }
    if ((*path_index) > longest_path_len) {
      longest_path_len = *path_index;
      for (int i = 0; i < (*path_index); i++)
        longest_path[i] = path[i];
    }
    if (flag == 0) {
      printf("один из путей: ");
      for (int i = 0; i < (*path_index); i++)
        printf("%d ", path[i] + 1);
      printf("\n");
    }
  } else {
    int c;
    for (c = 0; c < graph_adj_size; c++) { // column
      if (graph_adj[node * graph_adj_size + c] == 0)
        continue;
      if (!visited[c]) {
        all_paths_print_recur(c, dst, visited, path, path_index);
      }
    }
  }

  (*path_index)--;
  visited[node] = 0;
  return 0;
}

int all_paths_print(int src, int dst) {
  // 0 - все пути, 1 - короткий, 2 - длинный

  all_paths_print_recur(src, dst, visited, path, &path_index);

  if (flag == 1) {
    printf("кратчайший путь:\n");
    for (int i = 0; i < shortest_path_len; i++)
      printf("%d ", shortest_path[i] + 1);
    printf("\n");
  } else if (flag == 2) {
    printf("длиннейший путь:\n");
    for (int i = 0; i < longest_path_len; i++)
      printf("%d ", longest_path[i] + 1);
    printf("\n");
  }
  return 0;
}

int all_paths_free() {
  free(visited);
  free(path);
  free(shortest_path);
  free(longest_path);
  return 0;
}

int getdigit(char *str) {
  int i = 0, digit = 0;
  while (str[i] != ' ') {
    digit += str[i] - '0';
    digit *= 10;
    i++;
  }
  digit /= 10;
  return digit;
}