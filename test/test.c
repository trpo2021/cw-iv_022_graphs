#include "ctest.h"
#include "libgraphs/lib_for_cities.h"

CTEST(argument_check, null_arg_1) {
  char **argv = calloc(2, sizeof(char *));
  argv[1] = NULL;

  int real = arguments_check(argv);

  int exp = -1;

  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, incorrect_arg_1) {
  char **argv = calloc(2, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-l");

  int real = arguments_check(argv);

  int exp = 1;

  free(argv[1]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_2) {
  char **argv = calloc(3, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = NULL;

  int real = arguments_check(argv);

  int exp = 2;

  free(argv[1]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_3) {
  char **argv = calloc(4, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = calloc(2, sizeof(char));
  strcat(argv[2], "3");
  argv[3] = NULL;

  int real = arguments_check(argv);

  int exp = 3;

  free(argv[2]);
  free(argv[1]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, incorrect_arg_3) {
  char **argv = calloc(4, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = calloc(2, sizeof(char));
  strcat(argv[2], "3");
  argv[3] = calloc(3, sizeof(char));
  strcat(argv[2], "e");

  int real = arguments_check(argv);

  int exp = 3;

  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_4) {
  char **argv = calloc(5, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = calloc(2, sizeof(char));
  strcat(argv[2], "3");
  argv[3] = calloc(3, sizeof(char));
  strcat(argv[3], "-e");
  argv[4] = NULL;

  int real = arguments_check(argv);

  int exp = 4;

  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_5) {
  char **argv = calloc(6, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = calloc(2, sizeof(char));
  strcat(argv[2], "3");
  argv[3] = calloc(3, sizeof(char));
  strcat(argv[3], "-e");
  argv[4] = calloc(3, sizeof(char));
  strcat(argv[2], "2");
  argv[5] = NULL;

  int real = arguments_check(argv);

  int exp = 5;

  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv[4]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_1) {
  int i = 1;
  int j = 1;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i, j);
  int exp = 0;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_2) {
  int i = 2;
  int j = 2;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i, j);
  int exp = 0;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_3) {
  int i = 3;
  int j = 3;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i, j);
  int exp = 0;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_4) {
  int i = 4;
  int j = 4;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j);
  int exp = 0;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_12) {
  int i = 1;
  int j = 2;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 17;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_13) {
  int i = 1;
  int j = 3;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_14) {
  int i = 1;
  int j = 4;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_23) {
  int i = 2;
  int j = 3;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 13;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_24) {
  int i = 2;
  int j = 4;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 16;
  ASSERT_EQUAL(exp, real);
}

CTEST(get_edge, edge_between_34) {
  int i = 3;
  int j = 4;
  int max_city = 4;

  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int real = graph_get_edge(g, i - 1, j - 1);
  int exp = 15;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_1) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 17;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_2) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 38;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_3) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 41;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_4) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 53;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_5) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 56;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_6) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 6;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 0;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_7) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 17;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_8) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 41;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_9) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 38;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_10) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 56;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_11) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 53;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_12) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_13) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_14) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 30;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_15) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 48;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_16) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_17) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_18) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 30;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_19) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_20) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_21) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 48;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_22) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_23) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 33;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_24) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_25) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_26) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 45;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_27) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_28) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_29) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 33;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_30) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 45;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_31) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 1;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_32) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 17;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_33) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 38;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_34) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 41;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_35) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 56;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_36) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 53;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_37) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 17;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_38) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 41;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_39) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 38;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_40) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 53;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_41) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 56;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_42) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 13;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_43) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_44) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 31;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_45) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 66;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_46) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_47) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 13;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_48) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 31;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_49) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_50) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_51) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 3;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 66;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_52) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 16;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_53) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_54) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 28;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_55) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 63;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_56) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_57) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 16;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_58) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 28;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_59) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_60) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_61) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 2;
  arr_cities[2] = 4;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 63;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_62) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_63) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 30;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_64) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_65) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 48;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_66) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_67) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_68) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_69) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 30;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_70) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_71) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 1;
  arr_cities[3] = 4;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 48;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_72) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 13;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_73) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_74) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 31;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_75) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_76) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 4;
  int real = length(arr_cities, g, i, path_long);
  int exp = 66;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_77) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 13;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_78) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 31;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_79) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_80) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 66;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_81) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 2;
  arr_cities[3] = 4;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_82) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 15;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_83) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 50;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_84) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 29;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_85) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 55;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_86) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 58;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_87) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 15;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_88) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 29;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_89) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 50;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_90) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 58;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_91) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 3;
  arr_cities[2] = 4;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 55;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_92) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_93) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 33;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_94) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_95) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 45;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_96) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 2;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_97) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 25;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_98) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 40;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_99) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 33;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_100) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 54;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_101) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 1;
  arr_cities[3] = 3;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 45;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_102) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 16;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_103) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_104) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 28;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_105) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_106) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 1;
  arr_cities[4] = 3;
  int real = length(arr_cities, g, i, path_long);
  int exp = 63;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_107) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 16;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_108) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 28;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_109) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 42;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_110) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 63;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_111) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 2;
  arr_cities[3] = 3;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 57;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_112) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 15;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_113) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 29;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_114) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 50;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_115) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 55;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_116) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 2;
  arr_cities[4] = 1;
  int real = length(arr_cities, g, i, path_long);
  int exp = 58;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_117) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 1;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 15;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_118) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 2;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 50;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_119) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 3;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 29;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_120) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 4;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 58;
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, numa_numa_121) {
  struct graph *g = graph_create(max_city);
  graph_initialization(g, max_city);

  int *arr_cities = calloc(max_city + 1, sizeof(int));
  int i = 5;
  int *path_long = calloc(max_city + 1, sizeof(int));

  arr_cities[0] = 0;
  arr_cities[1] = 4;
  arr_cities[2] = 3;
  arr_cities[3] = 1;
  arr_cities[4] = 2;
  int real = length(arr_cities, g, i, path_long);
  int exp = 55;
  ASSERT_EQUAL(exp, real);
}