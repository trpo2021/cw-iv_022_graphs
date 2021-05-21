#include <libgraphs/graphs.h>
#define N 4

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

  graph_initialization(g, N);

  int max = -1;
  int city_1, city_2;
  int path[N]; //массив для востановленного пути
  int pathlen, opt;
  int array_cities[5] = {0};
  int arr_dlina[5] = {0};

  while ((opt = getopt(argc, argv, "nslb:e:")) != -1) {
    switch (opt) {
    case 'b':
      city_1 = atoi(optarg);

      if ((city_1 <= 0) || (city_1 >= 5)) {
        printf("Error: введите корректное значение стартового города\n");
        graph_free(g, N);
        return -1;
      }

      array_cities[1] = city_1;

      break;

    case 'e':
      city_2 = atoi(optarg);

      if ((city_2 <= 0) || (city_2 >= 5)) {
        printf("Error: введите корректное значение конечного города\n");
        graph_free(g, N);
        return -1;
      }

      array_cities[2] = city_2;

      break;

    case 's':
      for (int i = 0; i < N; i++) {
        path[i] = 0;
      }
      pathlen = 0;

      printf("\n----------------------------------------------");
      printf("\nСамый короткий путь между городами %d -- %d: ", city_1, city_2);

      if (city_1 == city_2) {
        printf("0\n");
        printf("Сам путь:  %d\n", city_2);
      } else {
        pathlen = SearchShortPath(g, city_1, city_2 - 1, path);
        printf("Сам путь:  %d ", city_1);
        for (int i = 1; i <= pathlen; i++) {
          if (path[i] == city_2 - 1) {
            path[i] = city_2;
          }
          printf("-> %d ", path[i]);
        }
        printf("\n");
      }
      break;

    case 'n':

      printf("\n----------------------------------------------");
      printf("\nВы хотите узнать все возможные машруты между данными городами: "
             "%d - %d\n",
             array_cities[1], array_cities[2]);

      AllPaths(array_cities);
      // получили номера городов
      int path_long[5] = {0};
      if (array_cities[1] != array_cities[2]) {
        int dlina = 0;
        printf("1 Путь. Вершины:  %d -> %d\n", array_cities[1],
               array_cities[2]);
        dlina = Length(array_cities, g, 1, path_long);
        printf("Длина:  %d\n", dlina);
        int temp = array_cities[3];
        for (int i = 2; i <= 3; i++) {
          printf("%d Путь. Вершины:  ", i);
          printf("%d -> %d -> %d\n", array_cities[1], temp, array_cities[2]);
          dlina = Length(array_cities, g, i, path_long);
          printf("Длина:  %d\n", dlina);
          temp = array_cities[4];
        }
        int temp_2 = array_cities[3];
        for (int i = 4; i <= 5; i++) {
          printf("%d Путь. Вершины:  ", i);
          printf("%d -> %d -> %d -> %d\n", array_cities[1], temp_2, temp,
                 array_cities[2]);
          dlina = Length(array_cities, g, i, path_long);
          printf("Длина:  %d\n", dlina);
          temp_2 = temp;
          temp = array_cities[3];
        }
      } else {
        printf("Путей:  0\n");
      }
      break;

    case 'l':

      //получили номера городов
      AllPaths(array_cities);
      printf("\n----------------------------------------------");
      int index;
      if (array_cities[1] != array_cities[2]) {
        for (int i = 1; i <= 5; i++) {
          arr_dlina[i] = Length(array_cities, g, i, path_long);
          if (arr_dlina[i] > max) {
            max = arr_dlina[i];
            index = i;
          }
        }
      } else {
        max = 0;
      }
      printf("\nСамый длинный путь между городами %d -- %d: ", city_1, city_2);
      printf("%d\n", max);
      printf("Сам путь:  %d ", city_1);
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
  graph_free(g, N);
  return 0;
}