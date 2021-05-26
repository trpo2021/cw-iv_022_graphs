#include "lib_for_cities.h"

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

void cities_numbers(int *array_cities) {
  if (array_cities[1] != array_cities[2]) {
    if ((array_cities[1] + first_city != array_cities[2]) &&
        (array_cities[1] + first_city <= fourth_city)) {
      array_cities[3] = array_cities[1] + first_city;

      if ((array_cities[2] - first_city >= first_city) &&
          (array_cities[2] - first_city != array_cities[3]) &&
          (array_cities[2] - first_city != array_cities[1])) {
        array_cities[4] = array_cities[2] - first_city;
      } else {
        if ((array_cities[2] + first_city <= fourth_city) &&
            (array_cities[2] + first_city != array_cities[1])) {
          array_cities[4] = array_cities[2] + first_city;
        } else {
          if (array_cities[2] + first_city > fourth_city) {
            array_cities[4] = array_cities[1] - first_city;
          } else {
            array_cities[4] = array_cities[2] + array_cities[3];
          }
        }
      }
    } else {
      if ((array_cities[1] - first_city != array_cities[2]) && (array_cities[1] > first_city)) {
        array_cities[3] = array_cities[1] - first_city;
      } else {
        if (array_cities[1] == first_city) {
          array_cities[3] = array_cities[1] + third_city;
        } else {
          array_cities[3] = array_cities[1] - third_city;
        }
      }
      if ((array_cities[2] - first_city >= first_city) &&
          (array_cities[2] - first_city != array_cities[3]) &&
          (array_cities[2] - first_city != array_cities[1])) {
        array_cities[4] = array_cities[2] - first_city;
      } else {
        if (array_cities[2] + first_city <= fourth_city) {
          array_cities[4] = array_cities[2] + first_city;
        } else {
          array_cities[4] = array_cities[3] - first_city;
        }
      }
    }
  } else {
    for (int i = 0; i < max_city + 1; i++) {
      array_cities[i] = 0;
    }
  }
}

int length(int *array_cities, struct graph *g, int i, int *path_long) {
  if (i == first_city) {
    path_long[2] = array_cities[2];
    return g->m[array_cities[1] - first_city][array_cities[2] - first_city];
  }
  if ((i == 2) || (i == 3)) {
    path_long[2] = array_cities[i + first_city];
    path_long[3] = array_cities[2];
    return g->m[array_cities[1] - first_city][array_cities[i + first_city] - first_city] +
           g->m[array_cities[i + first_city] - first_city][array_cities[2] - first_city];
  }
  if (i == fourth_city) {
    path_long[2] = array_cities[3];
    path_long[3] = array_cities[4];
    path_long[4] = array_cities[2];
    return g->m[array_cities[1] - first_city][array_cities[4] - first_city] +
           g->m[array_cities[4] - first_city][array_cities[3] - first_city] +
           g->m[array_cities[3] - first_city][array_cities[2] - first_city];
  }
  if (i == fourth_city + 1) {
    path_long[2] = array_cities[4];
    path_long[4] = array_cities[2];
    path_long[3] = array_cities[3];
    return g->m[array_cities[1] - first_city][array_cities[3] - first_city] +
           g->m[array_cities[3] - first_city][array_cities[4] - first_city] +
           g->m[array_cities[4] - first_city][array_cities[2] - first_city];
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

    for (int i = second_city; i <= third_city; i++) {
      printf("%d Путь. Вершины:  ", i);
      printf("%d -> %d -> %d\n", arr_cities[1], temp, arr_cities[2]);
      length_roads = length(arr_cities, g, i, path_long);
      printf("Длина:  %d\n", length_roads);
      temp = arr_cities[4];
    }

    for (int i = fourth_city; i <= fourth_city + 1; i++) {
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
    for (int i = first_city; i <= fourth_city + 1; i++) {
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
    for (int i = second_city; i <= index + 1; i++) {
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
    for (int i = first_city; i <= fourth_city + 1; i++) {
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
    for (int i = second_city; i <= fourth_city; i++) {
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

int memory_check(int *array) {
  if (array == NULL) {
    printf("Ошибка выделения памяти под массив\n");
    return -1;
  }
  return 0;
}
