#include <libgraph/library.h>
int main(int argc, char **argv) {
  int check;
  //массив для имени файла
  char *input_name_matrix = (char *)malloc((MAX_LENGTH_STR) * sizeof(char));

  if (argv[1] == NULL) {
    printf("файл с инструкцией\n");
    return 0;
  }
  if (strcmp(argv[1], "-m") != 0) {
    printf("Ошибка: неизвестный аргумент!\n");
    return 0;
  }
  if (strcmp(argv[1], "-m") == 0 && argv[2] == NULL) {
    printf("Ведите название файла\n");
    return 0;
  }

  while ((check = getopt(argc, argv, "m:")) != -1) {
    switch (check) {
    case 'm':
      input_name_matrix = argv[2];
      break;
    case '?':
      printf("Ошибка: неизвестный аргумент!\n");
      break;
    }
  }
  int start, end;
  int nvert = 0;
  check = 0;

  char name_matrix[MAX_LENGTH_STR] = "bin/";
  char *str = (char *)malloc(MAX_LENGTH_STR * sizeof(char));

  strcat(name_matrix, input_name_matrix);

  FILE *file = fopen(name_matrix, "r");
  if (file == NULL) {
    printf("Ошибка: не удаётся открыть файл с матрицей\n");
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

  printf("Начальный город: %d, конечный город: %d\n", start, end);

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

  dijkstra(start, end, nvert, matrix);

  fclose(file);
  return 0;
}