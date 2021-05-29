#include <libgraphs/library.h>

int main(int argc, char **argv) {

  int s = arguments_check(argv);
  if (s != 0) {
    arguments_error(s);
    return -1;
  }

  struct graph *g = graph_create(max_city);
  if (g == NULL) {
    return -1;
  }

  graph_initialization(g, max_city);

  int start_city, final_city, check;

  int *list_of_cities = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(list_of_cities)) == -1) {
    return -1;
  }

  int *arr_length = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(arr_length)) == -1) {
    free(list_of_cities);
    return -1;
  }

  int *path_long = calloc(max_city + 1, sizeof(int));

  if ((check = memory_check(path_long)) == -1) {
    free(list_of_cities);
    free(arr_length);
    return -1;
  }

  while ((check = getopt(argc, argv, "nslb:e:")) != -1) {
    switch (check) {
    case 'b':
      start_city = atoi(optarg);

      if ((start_city < min_city) || (start_city > max_city)) {
        printf("Ошибка: введите корректное значение стартового города\n");
        free_arrays(path_long, arr_length, list_of_cities);
        graph_free(g, max_city);
        return -1;
      }

      list_of_cities[1] = start_city;
      break;

    case 'e':
      final_city = atoi(optarg);

      if ((final_city < min_city) || (final_city > max_city)) {
        printf("Ошибка: введите корректное значение конечного города\n");
        free_arrays(path_long, arr_length, list_of_cities);
        graph_free(g, max_city);
        return -1;
      }

      if (final_city == start_city) {
        printf(
            "Ошибка: приложение не обрабатывает маршруты для одного города\n");
        free_arrays(path_long, arr_length, list_of_cities);
        graph_free(g, max_city);
        return -1;
      }

      list_of_cities[2] = final_city;
      cities_numbers(list_of_cities);
      break;

    case 's':
      shortest_path(list_of_cities, arr_length, path_long, g, start_city,
                    final_city);
      break;

    case 'n':
      all_paths(list_of_cities, g, path_long, start_city, final_city);
      break;

    case 'l':
      longest_path(list_of_cities, arr_length, path_long, g, start_city,
                   final_city);
      break;

    case '?':
      printf("Ошибка: неизвестный аргумент!\n");
      break;
    }
  }

  free_arrays(path_long, arr_length, list_of_cities);
  graph_free(g, max_city);
  return 0;
}
