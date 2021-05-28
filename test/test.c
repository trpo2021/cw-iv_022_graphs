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