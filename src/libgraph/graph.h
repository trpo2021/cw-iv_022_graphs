#pragma once
int graph_adj_init(int size);
int graph_adj_add(int row, int col);
int graph_adj_print();
void graph_adj_free();
int *graph_adj_get();