#pragma once
#define MAX_LENGTH_STR 200

extern int all_paths_print(int src, int dst);
extern int all_paths_free();
extern int all_paths_init(int *g_adj, int g_adj_size, int aflag);

int getdigit(char *str);
