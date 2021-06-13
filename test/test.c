#include "ctest.h"
#include "libgraph/library.h"

CTEST(getdigit_check, correct_str) {
  char str[50] = "4 <- количество городов";

  int real = getdigit(str);

  int exp = 4;

  ASSERT_EQUAL(exp, real);
}
