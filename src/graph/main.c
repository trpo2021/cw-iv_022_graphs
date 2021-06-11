#include <libgraph/library.h>
int main() {
    int start, end;
    int nvert = 0, check = 0;
    char *str = (char *)malloc(MAX_LENGTH_STR * sizeof(char));

    FILE *file = fopen("bin/matrix4.txt", "r");
    if (file == NULL) {
      printf("Ошибка: не удаётся открыть матрицу\n");
      return 0;
    }
    
    for (int i = 0; i < 2; i++) {
    fgets(str, MAX_LENGTH_STR, file);
    }
    nvert = getdigit(str);
    fgets(str, MAX_LENGTH_STR, file);
    start = getdigit(str);
    fgets(str, MAX_LENGTH_STR, file);
    end = getdigit(str);
    

    check = incorrect_input(nvert, start, end);
    if (check == -1) {
        printf("Некорректные данные графа\n");
        return 0;
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
    print_matrix(nvert, matrix);
    
    fclose(file);
    return 0;
}