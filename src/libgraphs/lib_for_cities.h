#pragma once
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum cities {
  max_city = 4,
  min_city = 1,
  first_city = 1,
  second_city = 2,
  third_city = 3,
  fourth_city = 4
};

struct graph {
  int nvertices; // Число вершин
  int **m;       // Матрица n x n
};

void cities_numbers(int *array_cities);
int length(int *array_cities, struct graph *g, int i, int *path_long);
int get_rand(int min, int max);
int arguments_check(char **argv);
void arguments_error(int s);
int memory_check(int *array);
void all_paths(int *arr_cities, struct graph *g, int *path_long, int start_city,
               int final_city);
void free_arrays(int *path_long, int *arr_length, int *arr_cities, int *path);
void longest_path(int *arr_cities, int *arr_length, int *path_long,
                  struct graph *g, int index, int start_city, int final_city);
void shortest_path(int *arr_cities, int *arr_length, int *path_long,
                   struct graph *g, int index, int start_city, int final_city);

void graph_initialization(struct graph *g, int max_city);
void graph_clear(struct graph *g, int N);
void graph_set_edge(struct graph *g, int i, int j, int w);
int graph_get_edge(struct graph *g, int i, int j);
struct graph *graph_create(int nvertices);
void graph_free(struct graph *g, int max_city);
int get_length(int i, int j);