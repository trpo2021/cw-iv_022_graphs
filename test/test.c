#include "ctest.h"
#include "libgraphs/library.h"

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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
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
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_1) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_2) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_3) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_4) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_5) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_6) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_7) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_8) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_9) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_10) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_11) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_12) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_13) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_14) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_15) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_16) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_17) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_18) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_19) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_20) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_21) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_22) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_23) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_24) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_25) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_26) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_27) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_28) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_29) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_30) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_31) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_32) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_33) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_34) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_35) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_36) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_37) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_38) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_39) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_40) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_41) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_42) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_43) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_44) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_45) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_46) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_47) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_48) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_49) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_50) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_51) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_52) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_53) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_54) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_55) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_56) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_57) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_58) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_59) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_60) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_61) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_62) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_63) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_64) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_65) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_66) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_67) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_68) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_69) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_70) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_71) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_72) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_73) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_74) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_75) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_76) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_77) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_78) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_79) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_80) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_81) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_82) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_83) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_84) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_85) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_86) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_87) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_88) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_89) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_90) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_91) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_92) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_93) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_94) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_95) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_96) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_97) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_98) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_99) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_100) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_101) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_102) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_103) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_104) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_105) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_106) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_107) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_108) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_109) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_110) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_111) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_112) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_113) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_114) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_115) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_116) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_117) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_118) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_119) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_120) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}

CTEST(length_of_road, set_of_combinations_121) {
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
  free(arr_cities);
  free(path_long);
  graph_free(g, max_city);
  ASSERT_EQUAL(exp, real);
}