#include <libgraphs/lib_for_cities.h>

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

  int start_city, final_city, opt, index = 0, check;

  int *path = malloc(sizeof(int) * max_city); //массив для востановленного пути

  if ((check = memory_check(path)) == -1) {
    return -1;
  }

  int *arr_cities = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(arr_cities)) == -1) {
    free(path);
    return -1;
  }

  int *arr_length = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(arr_length)) == -1) {
    free(path);
    free(arr_cities);
    return -1;
  }

  int *path_long = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(path_long)) == -1) {
    free(path);
    free(arr_cities);
    free(arr_length);
    return -1;
  }

  while ((opt = getopt(argc, argv, "nslb:e:")) != -1) {
    switch (opt) {
    case 'b':
      start_city = atoi(optarg);

      if ((start_city < min_city) || (start_city > max_city)) {
        printf("Ошибка: введите корректное значение стартового города\n");
        graph_free(g, max_city);
        return -1;
      }

      arr_cities[1] = start_city;
      break;

    case 'e':
      final_city = atoi(optarg);

      if ((final_city < min_city) || (final_city > max_city)) {
        printf("Ошибка: введите корректное значение конечного города\n");
        graph_free(g, max_city);
        return -1;
      }

      if (final_city == start_city) {
        printf(
            "Ошибка: приложение не обрабатывает маршруты для одного города\n");
        return -1;
      }

      arr_cities[2] = final_city;
      cities_numbers(arr_cities);
      break;

    case 's':
      shortest_path(arr_cities, arr_length, path_long, g, index, start_city,
                    final_city);
      break;

    case 'n':
      all_paths(arr_cities, g, path_long, start_city, final_city);
      break;

    case 'l':
      longest_path(arr_cities, arr_length, path_long, g, index, start_city,
                   final_city);
      break;

    case '?':
      printf("Ошибка: неизвестный аргумент!\n");
      break;
    }
  }

  free_arrays(path_long, arr_length, arr_cities, path);
  graph_free(g, max_city);
  return 0;
}