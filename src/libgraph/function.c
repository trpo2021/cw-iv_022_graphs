#include <libgraph/library.h>

int getdigit(char *str) {
    int i = 0, digit = 0;
    while (str[i] != ' ')
    {
        digit += str[i] - '0';
        digit *= 10;
        i++;
    }
    digit /= 10;
    return digit;
}