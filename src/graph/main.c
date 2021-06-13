#include <libgraph/library.h>
int main(int argc, char **argv) {

  char *input_name_matrix = (char *)malloc((MAX_LENGTH_STR) * sizeof(char));
  int check;
  int tmp_flag = -1;
  while ((check = getopt(argc, argv, "nslm:")) != -1) {
    switch (check) {
    case 'm':
      input_name_matrix = argv[2];
      break;
    case 'n': // отобразить все пути
      tmp_flag = 0;
      break;
    case 's': // которткий путь
      tmp_flag = 1;
      break;
    case 'l': // длинный путь
      tmp_flag = 2;
      break;
    case '?':
      printf("Ошибка: неизвестный аргумент!\n");
      break;
    }
  }
  if (tmp_flag < 0) {
    printf("Наряду с матрицей укажите обязательные ключи n s l\n");
    return 0;
  }

  int point_begin, point_end;
  int graph_adj_size = 0;
  check = 0;

  char name_matrix[MAX_LENGTH_STR] = "bin/";
  char *str = (char *)malloc(MAX_LENGTH_STR * sizeof(char));

  strcat(name_matrix, input_name_matrix);

  FILE *file = fopen(name_matrix, "r");
  if (file == NULL) {
    printf("Ошибка: не удаётся открыть файл с матрицей\n");
    return 0;
  }

  fgets(str, MAX_LENGTH_STR, file);
  graph_adj_size = getdigit(str);
  fgets(str, MAX_LENGTH_STR, file);
  point_begin = getdigit(str);
  fgets(str, MAX_LENGTH_STR, file);
  point_end = getdigit(str);

  printf("начальный город: %d, конечный город: %d\n", point_begin, point_end);
  printf("количество введенных городов: %d\n", graph_adj_size);

  point_begin--;
  point_end--;

  int r = graph_adj_init(graph_adj_size);
  if (r < 0) {
    printf("Ошибка: матрица смежности не проинициализирована\n");
    return -1;
  }

  char string[5] = {0};
  int digit1, digit2;
  while (!feof(file)) { //идет считывание ребер
    fgets(str, MAX_LENGTH_STR, file);
    sscanf(str, "%d%s%d", &digit1, string, &digit2);
    graph_adj_add(digit1 - 1, digit2 - 1);
  }

  printf("Ваша матрица смежности:\n");
  graph_adj_print();
  int *lgraph_adj = graph_adj_get();

  r = all_paths_init(lgraph_adj, graph_adj_size, tmp_flag);
	if (r < 0) {
		printf("Ошибка: массивы путей и посещенных вершин не проинициализированы\n");
		return -1;
	}
	all_paths_print(point_begin, point_end);
	graph_adj_free();
	all_paths_free();

  fclose(file);
  return 0;
}