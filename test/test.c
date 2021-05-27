#include "ctest.h"
#include "libgraphs/lib_for_cities.h"

CTEST(argument_check, invalid_argument_1) {
    char **argv = malloc(2 * sizeof(char*));
    argv[0] = malloc(10 * sizeof(char));
    argv[1] = malloc(4 * sizeof(char));
    strcat(argv[0], "./graph");
    strcat(argv[1], "-l");

    int real = arguments_check(argv);

    int exp = -1;

    ASSERT_EQUAL(exp, real);
}