#include "library.h"

void arguments_error(int s) {
  if (s == -1) {
    FILE *file = fopen("src/graphs/instruction.txt", "rt");
    if (file == NULL) {
      printf("Ошибка: не удаётся открыть инструкцию\n");
      return;
    }

    setlocale(LC_ALL, "Russian");

    char *arr = malloc(sizeof(char) * 75);
    while (fgets(arr, 75, file) != NULL)
      printf("%s", arr);
    printf("\n");

    free(arr);
    fclose(file);

  } else if (s == 1) {
    printf("Ошибка: введите стартовый город, с помощью ключа '-b'\n");
    printf("Например '-b 3'\n");

  } else if (s == 2) {
    printf("Ошибка: вы не ввели значение стартового города\n");

  } else if (s == 3) {
    printf("Ошибка: введите конечный город (или значение стартового)\n");
    printf("С помощью ключа '-e', например '-e 2'\n");

  } else if (s == 4) {
    printf("Ошибка: вы не ввели значение конечного города\n");

  } else if (s == 5) {
    printf("Ошибка: выберите, что вы хотите узнать:\n");
    printf("'-n' - кол-во маршрутов между городами\n");
    printf("'-s' - кратчайший путь между городами\n");
    printf("'-l' - длиннейший путь между городами\n");
  }
}

int arguments_check(char **argv) {
  if (argv[1] == NULL) {
    return -1;
  }

  if (strcmp(argv[1], "-b") != 0) {
    return 1;
  }

  if (argv[2] == NULL) {
    return 2;
  }

  if ((argv[3] == NULL) || (strcmp(argv[3], "-e") != 0)) {
    return 3;
  }

  if (argv[4] == NULL) {
    return 4;
  }

  if (argv[5] == NULL) {
    return 5;
  }
  return 0;
}

void cities_numbers(int *list_of_cities) {
  if ((list_of_cities[1] + first_city != list_of_cities[2]) &&
      (list_of_cities[1] + first_city <= fourth_city)) {
    list_of_cities[3] = list_of_cities[1] + first_city;

    if ((list_of_cities[2] - first_city >= first_city) &&
        (list_of_cities[2] - first_city != list_of_cities[3]) &&
        (list_of_cities[2] - first_city != list_of_cities[1])) {
      list_of_cities[4] = list_of_cities[2] - first_city;
    } else {
      if ((list_of_cities[2] + first_city <= fourth_city) &&
          (list_of_cities[2] + first_city != list_of_cities[1])) {
        list_of_cities[4] = list_of_cities[2] + first_city;
      } else {
        if (list_of_cities[2] + first_city > fourth_city) {
          list_of_cities[4] = list_of_cities[1] - first_city;
        } else {
          list_of_cities[4] = list_of_cities[2] + list_of_cities[3];
        }
      }
    }
  } else {
    if ((list_of_cities[1] - first_city != list_of_cities[2]) &&
        (list_of_cities[1] > first_city)) {
      list_of_cities[3] = list_of_cities[1] - first_city;
    } else {
      if (list_of_cities[1] == first_city) {
        list_of_cities[3] = list_of_cities[1] + third_city;
      } else {
        list_of_cities[3] = list_of_cities[1] - third_city;
      }
    }
    if ((list_of_cities[2] - first_city >= first_city) &&
        (list_of_cities[2] - first_city != list_of_cities[3]) &&
        (list_of_cities[2] - first_city != list_of_cities[1])) {
      list_of_cities[4] = list_of_cities[2] - first_city;
    } else {
      if (list_of_cities[2] + first_city <= fourth_city) {
        list_of_cities[4] = list_of_cities[2] + first_city;
      } else {
        list_of_cities[4] = list_of_cities[3] - first_city;
      }
    }
  }
}

int length(int *list_of_cities, struct graph *g, int i, int *path_long) {
  if (i == first_city) {
    path_long[2] = list_of_cities[2];
    return g->m[list_of_cities[1] - first_city][list_of_cities[2] - first_city];
  }
  if ((i == 2) || (i == 3)) {
    path_long[2] = list_of_cities[i + first_city];
    path_long[3] = list_of_cities[2];
    return g->m[list_of_cities[1] - first_city]
               [list_of_cities[i + first_city] - first_city] +
           g->m[list_of_cities[i + first_city] - first_city]
               [list_of_cities[2] - first_city];
  }
  if (i == fourth_city) {
    path_long[2] = list_of_cities[3];
    path_long[3] = list_of_cities[4];
    path_long[4] = list_of_cities[2];
    return g->m[list_of_cities[1] - first_city]
               [list_of_cities[4] - first_city] +
           g->m[list_of_cities[4] - first_city]
               [list_of_cities[3] - first_city] +
           g->m[list_of_cities[3] - first_city][list_of_cities[2] - first_city];
  }
  if (i == fourth_city + 1) {
    path_long[2] = list_of_cities[4];
    path_long[4] = list_of_cities[2];
    path_long[3] = list_of_cities[3];
    return g->m[list_of_cities[1] - first_city]
               [list_of_cities[3] - first_city] +
           g->m[list_of_cities[3] - first_city]
               [list_of_cities[4] - first_city] +
           g->m[list_of_cities[4] - first_city][list_of_cities[2] - first_city];
  }
  return 0;
}

void all_paths(int *list_of_cities, struct graph *g, int *path_long,
               int start_city, int final_city) {
  printf("\n----------------------------------------------");
  printf("\nВсе маршруты между городами: %d - %d\n", start_city, final_city);

  int length_roads = 0;

  printf("1 Путь. Вершины:  %d -> %d\n", list_of_cities[1], list_of_cities[2]);
  length_roads = length(list_of_cities, g, 1, path_long);
  printf("Длина:  %d\n", length_roads);

  int temp = list_of_cities[3];
  int temp_2 = list_of_cities[3];

  for (int i = second_city; i <= third_city; i++) {
    printf("%d Путь. Вершины:  ", i);
    printf("%d -> %d -> %d\n", list_of_cities[1], temp, list_of_cities[2]);
    length_roads = length(list_of_cities, g, i, path_long);
    printf("Длина:  %d\n", length_roads);
    temp = list_of_cities[4];
  }

  for (int i = fourth_city; i <= fourth_city + 1; i++) {
    printf("%d Путь. Вершины:  ", i);
    printf("%d -> %d -> %d -> %d\n", list_of_cities[1], temp_2, temp,
           list_of_cities[2]);
    length_roads = length(list_of_cities, g, i, path_long);
    printf("Длина:  %d\n", length_roads);
    temp_2 = temp;
    temp = list_of_cities[3];
  }
}

void shortest_path(int *list_of_cities, int *arr_length, int *path_long,
                   struct graph *g, int start_city, int final_city) {
  printf("\n----------------------------------------------");

  int index = 0;
  int min = 999;

  for (int i = first_city; i <= fourth_city + 1; i++) {
    arr_length[i] = length(list_of_cities, g, i, path_long);
    if (arr_length[i] < min) {
      min = arr_length[i];
      index = i;
    }
  }

  printf("\nСамый короткий путь между городами %d -- %d: %d", start_city,
         final_city, min);
  printf("\nСам путь:  %d ", start_city);

  length(list_of_cities, g, index, path_long);
  for (int i = second_city; i <= index + 1; i++) {
    printf("-> %d ", path_long[i]);
  }
  printf("\n");
}

void longest_path(int *list_of_cities, int *arr_length, int *path_long,
                  struct graph *g, int start_city, int final_city) {
  printf("\n----------------------------------------------");

  int max = -1, index = 0;

  for (int i = first_city; i <= fourth_city + 1; i++) {
    arr_length[i] = length(list_of_cities, g, i, path_long);
    if (arr_length[i] > max) {
      max = arr_length[i];
      index = i;
    }
  }

  printf("\nСамый длинный путь между городами %d -- %d: %d\n", start_city,
         final_city, max);
  printf("Сам путь:  %d ", start_city);

  length(list_of_cities, g, index, path_long);
  for (int i = second_city; i <= fourth_city; i++) {
    printf("-> %d ", path_long[i]);
  }
  printf("\n");
}

void free_arrays(int *path_long, int *arr_length, int *list_of_cities) {
  free(list_of_cities);
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
