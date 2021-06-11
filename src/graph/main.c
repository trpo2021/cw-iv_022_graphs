#include <libgraph/library.h>
int main() {
    int start, end;
    int nvert = 0;
    char *str = (char *)malloc(MAX_LENGTH_STR * sizeof(char));

    FILE *file = fopen("bin/matrix4.txt", "r");
    if (file == NULL) {
      printf("Ошибка: не удаётся открыть матрицу\n");
      return 0;
    }
    
    for (int i = 0; i < 2; i++) {
    fgets(str, MAX_LENGTH_STR, file);
    }
    int i = 0;
    while (str[i] != ' ')
    {
        nvert += str[i] - '0';
        nvert *= 10;
        i++;
    }
    nvert /= 10;
    fgets(str, MAX_LENGTH_STR, file);
    i = 0, start = 0;
    while (str[i] != ' ')
    {
        start += str[i] - '0';
        start *= 10;
        i++;
    }
    start /= 10;
    fgets(str, MAX_LENGTH_STR, file);
    i = 0, end = 0;
    while (str[i] != ' ')
    {
        end += str[i] - '0';
        end *= 10;
        i++;
    }
    end /= 10;

    if (nvert > 10 || nvert <= 0) {
        printf("Некорректные данные графа\n");
        return -1;
    }
    if (start > nvert || start <= 0) {
        printf("Некорректные данные графа\n");
        return -1;
    }
    if (end > nvert || end <= 0) {
        printf("Некорректные данные графа\n");
        return -1;
    } 

    printf("Начальный город: %d, конечный город: %d", start, end);

    start--;
    end--;

    int matrix[nvert][nvert];
    // матрица смежности
    int temp;

    // Инициализация двоичной матрицы смежности
    for (int i = 0; i < nvert; i++) {
    matrix[i][i] = 0;
    for (int j = 0; j < nvert; j++) {
      //считывать строку и получать из нее вес ребра, записывать в матрицу
      fgets(str, MAX_LENGTH_STR, file);
      temp = 0;
      temp += str[18] - '0';
      matrix[i][j] = temp;
    }
    }
    // Вывод матрицы смежности
    printf("\n");
    for (int i = 0; i < nvert; i++) {
        for (int j = 0; j < nvert; j++) {
        printf("%5d ", matrix[i][j]);
    }
    printf("\n");
    }
    printf("\n");

    fclose(file);
    return 0;
}