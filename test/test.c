#include "ctest.h"
#include "libgraph/library.h"
#include <limits.h>

CTEST(getdigit_check, correct_str) {
  char str[50] = "4 <- количество городов";

  int real = getdigit(str);

  int exp = 4;

  ASSERT_EQUAL(exp, real);
}

CTEST(graph_adj_init_check, correct_memory_size) {

  int real = graph_adj_init(4);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}

CTEST(graph_adj_add_check, correct_add_adj) {

  int real = graph_adj_add(0,2);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}

CTEST(all_paths_init_check, correct_path_init) {

  graph_adj_init(4);

  graph_adj_add(0, 1);
  graph_adj_add(0, 2);
  graph_adj_add(0, 3);
  graph_adj_add(2, 0);
  graph_adj_add(2, 1);
  graph_adj_add(1, 3);

  int *lgraph_adj = graph_adj_get();

  int real = all_paths_init(lgraph_adj, 4, 1, 1);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}

CTEST(all_paths_print_check, correct_shortest_path) {

  int *lgraph_adj = graph_adj_get();

  all_paths_init(lgraph_adj, 4, 1, 1);

  char *real = (char *)malloc(100 * sizeof(char));
  strcat(real, all_paths_print(2,3));

  char exp[100] = "3 1 4 ";

  ASSERT_STR(exp, real);
}

CTEST(all_paths_print_check, correct_longest_path) {

  int *lgraph_adj = graph_adj_get();

  all_paths_init(lgraph_adj, 4, 2, 1);

  char *real = (char *)malloc(100 * sizeof(char));
  strcat(real, all_paths_print(2,3));

  char exp[100] = "3 1 2 4 ";

  ASSERT_STR(exp, real);
}