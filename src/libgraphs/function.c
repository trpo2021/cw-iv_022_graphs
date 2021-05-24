#include "graphs.h"

int get_rand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int arguments_check(char **argv) {
  if (strcmp(argv[1], "-b") != 0) {
    printf("Ошибка: введите стартовый город, с помощью ключа '-b'\n");
    printf("Например '-b 3'\n");
    return -1;
  }

  if (argv[2] == NULL) {
    printf("Ошибка: вы не ввели значение стартового города\n");
    return -1;
  }

  if ((argv[3] == NULL) || (strcmp(argv[3], "-e") != 0)) {
    printf("Ошибка: введите конечный город (или значение стартового)\n");
    printf("С помощью ключа '-e', например '-e 2'\n");
    return -1;
  }

  if (argv[4] == NULL) {
    printf("Ошибка: вы не ввели значение конечного города\n");
    return -1;
  }

  if (argv[5] == NULL) {
    printf("Ошибка: выберите, что вы хотите узнать:\n");
    printf("'-n' - кол-во маршрутов между городами\n");
    printf("'-s' - кратчайший путь между городами\n");
    printf("'-l' - длиннейший путь между городами\n");
    return -1;
  }
  return 0;
}

void graph_initialization(struct graph *g, int max_city) {
  for (int i = 0; i < max_city; i++) {
    for (int j = i; j < max_city; j++) {
      graph_set_edge(g, i, j, get_rand(10, 30));
    }
  }
}

void cities_numbers(int *array_cities) {
  if (array_cities[1] != array_cities[2]) {
    if ((array_cities[1] + 1 != array_cities[2]) &&
        (array_cities[1] + 1 <= 4)) {
      array_cities[3] = array_cities[1] + 1;

      if ((array_cities[2] - 1 >= 1) &&
          (array_cities[2] - 1 != array_cities[3]) &&
          (array_cities[2] - 1 != array_cities[1])) {
        array_cities[4] = array_cities[2] - 1;
      } else {
        if ((array_cities[2] + 1 <= 4) &&
            (array_cities[2] + 1 != array_cities[1])) {
          array_cities[4] = array_cities[2] + 1;
        } else {
          if (array_cities[2] + 1 > 4) {
            array_cities[4] = array_cities[1] - 1;
          } else {
            array_cities[4] = array_cities[2] + array_cities[3];
          }
        }
      }
    } else {
      if ((array_cities[1] - 1 != array_cities[2]) && (array_cities[1] > 1)) {
        array_cities[3] = array_cities[1] - 1;
      } else {
        if (array_cities[1] == 1) {
          array_cities[3] = array_cities[1] + 3;
        } else {
          array_cities[3] = array_cities[1] - 3;
        }
      }
      if ((array_cities[2] - 1 >= 1) &&
          (array_cities[2] - 1 != array_cities[3]) &&
          (array_cities[2] - 1 != array_cities[1])) {
        array_cities[4] = array_cities[2] - 1;
      } else {
        if (array_cities[2] + 1 <= 4) {
          array_cities[4] = array_cities[2] + 1;
        } else {
          array_cities[4] = array_cities[3] - 1;
        }
      }
    }
  } else {
    for (int i = 0; i < 5; i++) {
      array_cities[i] = 0;
    }
  }
}

int length(int *array_cities, struct graph *g, int i, int *path_long) {
  if (i == 1) {
    path_long[2] = array_cities[2];
    return g->m[array_cities[1] - 1][array_cities[2] - 1];
  }
  if ((i == 2) || (i == 3)) {
    path_long[2] = array_cities[i + 1];
    path_long[3] = array_cities[2];
    return g->m[array_cities[1] - 1][array_cities[i + 1] - 1] +
           g->m[array_cities[i + 1] - 1][array_cities[2] - 1];
  }
  if (i == 4) {
    path_long[2] = array_cities[3];
    path_long[3] = array_cities[4];
    path_long[4] = array_cities[2];
    return g->m[array_cities[1] - 1][array_cities[4] - 1] +
           g->m[array_cities[4] - 1][array_cities[3] - 1] +
           g->m[array_cities[3] - 1][array_cities[2] - 1];
  }
  if (i == 5) {
    path_long[2] = array_cities[4];
    path_long[4] = array_cities[2];
    path_long[3] = array_cities[3];
    return g->m[array_cities[1] - 1][array_cities[3] - 1] +
           g->m[array_cities[3] - 1][array_cities[4] - 1] +
           g->m[array_cities[4] - 1][array_cities[2] - 1];
  }
  return 0;
}

void all_paths(int *arr_cities, struct graph *g, int *path_long, int start_city,
               int final_city) {
  printf("\n----------------------------------------------");
  printf("\nВсе маршруты между городами: %d - %d\n", start_city, final_city);

  if (arr_cities[1] != arr_cities[2]) {
    int length_roads = 0;

    printf("1 Путь. Вершины:  %d -> %d\n", arr_cities[1], arr_cities[2]);
    length_roads = length(arr_cities, g, 1, path_long);
    printf("Длина:  %d\n", length_roads);

    int temp = arr_cities[3];
    int temp_2 = arr_cities[3];

    for (int i = 2; i <= 3; i++) {
      printf("%d Путь. Вершины:  ", i);
      printf("%d -> %d -> %d\n", arr_cities[1], temp, arr_cities[2]);
      length_roads = length(arr_cities, g, i, path_long);
      printf("Длина:  %d\n", length_roads);
      temp = arr_cities[4];
    }

    for (int i = 4; i <= 5; i++) {
      printf("%d Путь. Вершины:  ", i);
      printf("%d -> %d -> %d -> %d\n", arr_cities[1], temp_2, temp,
             arr_cities[2]);
      length_roads = length(arr_cities, g, i, path_long);
      printf("Длина:  %d\n", length_roads);
      temp_2 = temp;
      temp = arr_cities[3];
    }
  } else {
    printf("Путей:  0\n");
  }
}

void shortest_path(int *arr_cities, int *arr_length, int *path_long,
                   struct graph *g, int index, int start_city, int final_city) {
  printf("\n----------------------------------------------");
  int min = 999;

  if (arr_cities[1] != arr_cities[2]) {
    for (int i = 1; i <= 5; i++) {
      arr_length[i] = length(arr_cities, g, i, path_long);
      if (arr_length[i] < min) {
        min = arr_length[i];
        index = i;
      }
    }
  } else {
    min = 0;
  }

  printf("\nСамый короткий путь между городами %d -- %d: %d", start_city,
         final_city, min);
  printf("\nСам путь:  %d ", start_city);

  if (min != 0) {
    length(arr_cities, g, index, path_long);
    for (int i = 2; i <= index + 1; i++) {
      printf("-> %d ", path_long[i]);
    }
  }
  printf("\n");
}

void longest_path(int *arr_cities, int *arr_length, int *path_long,
                  struct graph *g, int index, int start_city, int final_city) {
  printf("\n----------------------------------------------");
  int max = -1;

  if (arr_cities[1] != arr_cities[2]) {
    for (int i = 1; i <= 5; i++) {
      arr_length[i] = length(arr_cities, g, i, path_long);
      if (arr_length[i] > max) {
        max = arr_length[i];
        index = i;
      }
    }
  } else {
    max = 0;
  }

  printf("\nСамый длинный путь между городами %d -- %d: %d\n", start_city,
         final_city, max);
  printf("Сам путь:  %d ", start_city);

  if (max != 0) {
    length(arr_cities, g, index, path_long);
    for (int i = 2; i <= 4; i++) {
      printf("-> %d ", path_long[i]);
    }
  }
  printf("\n");
}

void free_arrays(int *path_long, int *arr_length, int *arr_cities, int *path) {
  free(path);
  free(arr_cities);
  free(arr_length);
  free(path_long);
}

void graph_clear(struct graph *g, int N) {
  for (int i = 1; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      g->m[i][j] = 0;
    }
  }
}

void graph_set_edge(struct graph *g, int i, int j, int w) {
  if (i == j) {
    g->m[i][j] = 0;
  } else {
    g->m[i][j] = w;
    g->m[j][i] = w;
  }
}

int graph_get_edge(struct graph *g, int i, int j) { return g->m[i][j]; }

int memory_check(int *array) {
  if (array == NULL) {
    printf("Ошибка выделения памяти под массив\n");
    return -1;
  }
  return 0;
}

struct graph *graph_create(int nvertices) {
  struct graph *g;
  g = malloc(sizeof(*g));

  if (g == NULL) {
    printf("Ошибка выделения памяти под граф\n");
    return NULL;
  }

  g->nvertices = nvertices;
  g->m = malloc(sizeof(int *) * nvertices);

  if (g->m == NULL) {
    printf("Ошибка выделения памяти в графе\n");
    free(g);
    return NULL;
  }

  for (int i = 0; i < nvertices; i++) {
    g->m[i] = malloc(sizeof(int) * nvertices);

    if (g->m[i] == NULL) {
      printf("Ошибка выделения памяти в графе\n");
      free(g->m);
      free(g);
      return NULL;
    }
  }

  g->visited = malloc(sizeof(int) * nvertices);

  if (g->visited == NULL) {
    printf("Ошибка выделения памяти под посещаемые вершины\n");
    for (int i = 0; i < max_city; i++) {
      free(g->m[i]);
    }
    free(g->m);
    free(g);
    return NULL;
  }

  graph_clear(g, nvertices);
  return g;
}

void graph_free(struct graph *g, int max_city) {
  free(g->visited);

  for (int i = 0; i < max_city; i++) {
    free(g->m[i]);
  }

  free(g->m);
  free(g);
}
