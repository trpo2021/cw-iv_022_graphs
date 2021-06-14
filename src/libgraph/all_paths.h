#pragma once
#define MAX_LENGTH_STR 200

char *all_paths_print(int src, int dst);
void all_paths_free();
int all_paths_init(int *g_adj, int g_adj_size, int aflag, int asilent);
int getdigit(char *str);
