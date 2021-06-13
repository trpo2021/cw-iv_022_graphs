#pragma once
extern int graph_adj_init(int size);
extern int graph_adj_add(int row, int col);
extern int graph_adj_print();
extern int graph_adj_free();
extern int *graph_adj_get();