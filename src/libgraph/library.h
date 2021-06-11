#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH_STR 200
#define MAX_LENGTH_PATH 10000

int getdigit(char *str);
int incorrect_input(int nvert, int start, int end);
void print_matrix(int nvert, int matrix[][nvert]);
void dijkstra(int start, int end, int nvert, int matrix[][nvert]);
