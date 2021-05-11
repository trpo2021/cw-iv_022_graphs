#include <libgraphs/graphs.h>
#define N 4

int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    printf("Ваш полный граф выглядит так:\n");
    printf("[1] - [2]\n");
    printf(" |  X  |\n");
    printf("[4] - [3]\n");
    printf("\nРебро [1 - 2] = 17\nРебро [2 - 3] = 13\nРебро [3 - 4] = 15\n");
    printf("Ребро [4 - 1] = 25\nРебро [1 - 3] = 25\nРебро [2 - 4] = 16\n");
    printf("\nВыберите две вершины с помощью ключей '-b X' и '-e X', где X - "
           "номер вершины, b - стартовый город, e - конечный\n");
    printf("После этого выберите, что вы хотели бы узнать:\n");
    printf("'-n' - кол-во маршрутов между городами\n");
    printf("'-s' - кратчайший путь между городами\n");
    printf("'-l' - длиннейший путь между городами\n");
    printf("Пример ввода ключей: './prog_name -b 3 -e 2 -nsl'\n");
    return -1;
  }

  if (strcmp(argv[1], "-b") != 0) {
    printf("Error: сперва введите стартовый город, с помощью ключа '-b', "
           "например '-b 3'\n");
    return -1;
  }

  if (argv[2] == NULL) {
    printf("Error: вы не ввели стартовый город\n");
    return -1;
  }

  if ((argv[3] == NULL) || (strcmp(argv[3], "-e") != 0)) {
    printf("Error: введите конечный город (или значение стартового), с помощью "
           "ключа '-e', например '-e 2'\n");
    return -1;
  }

  if (argv[4] == NULL) {
    printf("Error: вы не ввели конечный город\n");
    return -1;
  }

  if (argv[5] == NULL) {
    printf("Error: выберите, что вы хотите узнать:\n");
    printf("'-n' - кол-во маршрутов между городами\n");
    printf("'-s' - кратчайший путь между городами\n");
    printf("'-l' - длиннейший путь между городами\n");
    return -1;
  }

  int opt = 0;
  int city_1;
  int city_2;

  struct graph *g = graph_create(N);

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      graph_set_edge(g, i, j, getrand(10, 30));
    }
  }

  int path[N]; //массив для востановленного пути
  int pathlen;
  int array_cities[5] = {0}; //массив городов для удобного использования функций

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
          printf("%d ", path[i]);
        }
        printf("\n");
      }
      break;

    case 'l':
      for (int i = 0; i < N; i++) {
        path[i] = 0;
      }
      pathlen = 0;

      printf("\n----------------------------------------------");
      printf("\nСамый длинный путь между городами %d -- %d: ", city_1, city_2);

      if (city_1 == city_2) {
        printf("0\n");
        printf("Сам путь:  %d\n", city_2);
      } else {
        pathlen = SearchLongPath(g, city_1, city_2 - 1, path);

        printf("Сам путь:  %d ", city_1);

        for (int i = 1; i <= pathlen; i++) {
          if (path[i] == city_2 - 1) {
            path[i] = city_2;
          }
          printf("%d ", path[i]);
        }
        printf("\n");
      }
      break;

    case 'n':
      AllPaths(array_cities); // получили номера городов

      printf("\n----------------------------------------------");
      printf("\nВы хотите узнать все возможные машруты между данными городами: "
             "%d - %d\n\n",
             array_cities[1], array_cities[2]);

      Length_and_Paths(array_cities, g);
      break;

    case '?':
      printf("Error: unknown argument!\n");
      break;
    }
  }
  graph_free(g, N);
  return 0;
}