#include "ctest.h"
#include "libgraphs/lib_for_cities.h"

CTEST(argument_check, null_arg_1) {
  char **argv = malloc(2 * sizeof(char *));
  argv[1] = NULL;

  int real = arguments_check(argv);

  int exp = -1;

  free(argv);
  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, incorrect_arg_1) {
  char **argv = malloc(2 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-l");

  int real = arguments_check(argv);

  int exp = 1;

  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_2) {
  char **argv = malloc(3 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = NULL;

  int real = arguments_check(argv);

  int exp = 2;

  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_3) {
  char **argv = malloc(4 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = malloc(2 * sizeof(char));
  strcat(argv[2], "3");
  argv[3] = NULL;

  int real = arguments_check(argv);

  int exp = 3;

  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, incorrect_arg_3) {
  char **argv = malloc(4 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = malloc(2 * sizeof(char));
  strcat(argv[2], "3");
  argv[3] = malloc(3 * sizeof(char));
  strcat(argv[2], "e");

  int real = arguments_check(argv);

  int exp = 3;

  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_4) {
  char **argv = malloc(5 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = malloc(2 * sizeof(char));
  strcat(argv[2], "3");
  argv[3] = malloc(3 * sizeof(char));
  strcat(argv[3], "-e");
  argv[4] = NULL;

  int real = arguments_check(argv);

  int exp = 4;

  ASSERT_EQUAL(exp, real);
}

CTEST(argument_check, null_arg_5) {
  char **argv = malloc(6 * sizeof(char *));
  argv[1] = malloc(3 * sizeof(char));
  strcat(argv[1], "-b");
  argv[2] = malloc(2 * sizeof(char));
  strcat(argv[2], "3");
  argv[3] = malloc(3 * sizeof(char));
  strcat(argv[3], "-e");
  argv[4] = malloc(3 * sizeof(char));
  strcat(argv[2], "2");
  argv[5] = NULL;

  int real = arguments_check(argv);

  int exp = 5;

  ASSERT_EQUAL(exp, real);
}