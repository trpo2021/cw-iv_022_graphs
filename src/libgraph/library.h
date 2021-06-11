#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LENGTH_STR 200
#define MAX_LENGTH_PATH 10000

int getdigit(char *str);
int incorrect_input(int nvert, int start, int end);
void print_matrix(int nvert, int matrix[][nvert]);
void dijkstra(int start, int end, int nvert, int matrix[][nvert]);
void get_min_minindex(int nvert, int *visit, int *d, int *min, int *minindex);
int get_short_path(int nvert, int start, int end, int matrix[][nvert], int *d,
                   int *ver, int preg, int weight);