#include <libgraphs/graphs.h>

int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    FILE *file = fopen("src/graphs/instruction.txt", "rt");
    if (file == NULL) {
      printf("Ошибка: не удаётся открыть инструкцию\n");
      return -1;
    }

    setlocale(LC_ALL, "Russian");
    char *arr = malloc(sizeof(char) * 75);
    while (fgets(arr, 75, file) != NULL)
      printf("%s", arr);
    printf("\n");

    free(arr);
    fclose(file);
    return -1;
  }

  int s = arguments_check(argv);
  if (s == -1) {
    return -1;
  }

  struct graph *g = graph_create(max_city);
  if (g == NULL) {
    return -1;
  }

  graph_initialization(g, max_city);

  int start_city, final_city, path_length, opt;
  int *path = malloc(sizeof(int) * max_city); //массив для востановленного пути
  int *array_cities = calloc(max_city + 1, sizeof(int));
  int *arr_length = calloc(max_city + 1, sizeof(int));

  while ((opt = getopt(argc, argv, "nslb:e:")) != -1) {
    switch (opt) {
    case 'b':
      start_city = atoi(optarg);

      if ((start_city < min_city) || (start_city > max_city)) {
        printf("Error: введите корректное значение стартового города\n");
        graph_free(g, max_city);
        return -1;
      }

      array_cities[1] = start_city;

      break;

    case 'e':
      final_city = atoi(optarg);

      if ((final_city < min_city) || (final_city > max_city)) {
        printf("Error: введите корректное значение конечного города\n");
        graph_free(g, max_city);
        return -1;
      }

      array_cities[2] = final_city;
      all_paths(array_cities);
      break;

    case 's':
      for (int i = 0; i < max_city; i++) {
        path[i] = 0;
      }
      path_length = 0;

      printf("\n----------------------------------------------");
      printf("\nСамый короткий путь между городами %d -- %d: ", start_city,
             final_city);

      if (start_city == final_city) {
        printf("0\n");
        printf("Сам путь:  %d\n", final_city);
      } else {
        path_length = SearchShortPath(g, start_city, final_city - 1, path);
        printf("Сам путь:  %d ", start_city);
        for (int i = 1; i <= path_length; i++) {
          if (path[i] == final_city - 1) {
            path[i] = final_city;
          }
          printf("-> %d ", path[i]);
        }
        printf("\n");
      }
      break;

    case 'n':

      printf("\n----------------------------------------------");
      printf("\nВсе возможные машруты между данными городами: %d - %d\n",
             array_cities[1], array_cities[2]);

      // получили номера городов
      int path_long[5] = {0};
      if (array_cities[1] != array_cities[2]) {
        int length = 0;
        printf("1 Путь. Вершины:  %d -> %d\n", array_cities[1],
               array_cities[2]);
        length = Length(array_cities, g, 1, path_long);
        printf("Длина:  %d\n", length);
        int temp = array_cities[3];
        for (int i = 2; i <= 3; i++) {
          printf("%d Путь. Вершины:  ", i);
          printf("%d -> %d -> %d\n", array_cities[1], temp, array_cities[2]);
          length = Length(array_cities, g, i, path_long);
          printf("Длина:  %d\n", length);
          temp = array_cities[4];
        }
        int temp_2 = array_cities[3];
        for (int i = 4; i <= 5; i++) {
          printf("%d Путь. Вершины:  ", i);
          printf("%d -> %d -> %d -> %d\n", array_cities[1], temp_2, temp,
                 array_cities[2]);
          length = Length(array_cities, g, i, path_long);
          printf("Длина:  %d\n", length);
          temp_2 = temp;
          temp = array_cities[3];
        }
      } else {
        printf("Путей:  0\n");
      }
      break;

    case 'l':
      printf("\n----------------------------------------------");
      int index;
      int max = -1;

      if (array_cities[1] != array_cities[2]) {
        for (int i = 1; i <= 5; i++) {
          arr_length[i] = Length(array_cities, g, i, path_long);
          if (arr_length[i] > max) {
            max = arr_length[i];
            index = i;
          }
        }
      } else {
        max = 0;
      }
      printf("\nСамый длинный путь между городами %d -- %d: ", start_city,
             final_city);
      printf("%d\n", max);
      printf("Сам путь:  %d ", start_city);
      if (max != 0) {
        Length(array_cities, g, index, path_long);
        for (int i = 2; i <= 4; i++) {
          printf("-> %d ", path_long[i]);
        }
      }
      printf("\n");
      break;

    case '?':
      printf("Error: unknown argument!\n");
      break;
    }
  }
  free(path);
  free(array_cities);
  free(arr_length);
  graph_free(g, max_city);
  return 0;
}