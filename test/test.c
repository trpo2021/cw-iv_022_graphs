#include "ctest.h"
#include "libgraph/library.h"
#include <limits.h>

CTEST(getdigit_check, correct_str) {
  char str[50] = "4 <- количество городов";

  int real = getdigit(str);

  int exp = 4;

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