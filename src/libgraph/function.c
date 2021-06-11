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

void print_matrix(int nvert, int matrix[][nvert]) {
    printf("\n");
    for (int i = 0; i < nvert; i++) {
        for (int j = 0; j < nvert; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}