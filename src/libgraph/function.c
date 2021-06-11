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

int incorrect_input(int nvert, int start, int end) {
    if (nvert > 10 || nvert <= 0) {
        return -1;
    }
    if (start > nvert || start <= 0) {
        return -1;
    }
    if (end > nvert || end <= 0) {
        return -1;
    } 
    return 0;
}