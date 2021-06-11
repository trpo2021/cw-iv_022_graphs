#include "ctest.h"
#include "libgraph/library.h"

CTEST(getdigit_check, correct_str) {
  char str[50] = "4 <- количество городов";

  int real = getdigit(str);

  int exp = 4;

  ASSERT_EQUAL(exp, real);
}

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
  strcat(argv[1], "m");

  int real = arguments_check(argv);

  int exp = 1;

  free(argv[1]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_2) {
  char **argv = calloc(3, sizeof(char *));
  argv[1] = calloc(3, sizeof(char));
  strcat(argv[1], "-m");
  argv[2] = NULL;

  int real = arguments_check(argv);

  int exp = 2;

  free(argv[1]);
  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_nvert_1) {
  int nvert = 12;
  int start = 1;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_nvert_2) {
  int nvert = -1;
  int start = 1;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, correct_nvert) {
  int nvert = 9;
  int start = 1;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_start_1) {
  int nvert = 7;
  int start = 9;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_start_2) {
  int nvert = 7;
  int start = 0;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, correct_start) {
  int nvert = 9;
  int start = 1;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_end_1) {
  int nvert = 7;
  int start = 6;
  int end = 10;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, incorrect_end_2) {
  int nvert = 7;
  int start = 5;
  int end = -1;

  int real = incorrect_input(nvert, start, end);

  int exp = -1;

  ASSERT_EQUAL(exp, real);
}

CTEST(input_matrix_check, correct_end) {
  int nvert = 9;
  int start = 1;
  int end = 7;

  int real = incorrect_input(nvert, start, end);

  int exp = 0;

  ASSERT_EQUAL(exp, real);
}
