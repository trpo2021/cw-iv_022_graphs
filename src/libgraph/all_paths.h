#pragma once
#define MAX_LENGTH_STR 200

void all_paths_print(int src, int dst);
void all_paths_free();
int all_paths_init(int *g_adj, int g_adj_size, int aflag);
void all_paths_print_recur(int node, int dst, int visited[], int path[],
                           int *path_index);
int getdigit(char *str);
