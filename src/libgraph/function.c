#include <libgraph/library.h>

int getdigit(char *str) {
    int i = 0, digit = 0;
    while (str[i] != ' ')
    {
        digit += str[i] - '0';
        digit *= 10;
        i++;
    }
    digit /= 10;
    return digit;
}

int incorrect_input(int nvert, int start, int end) {
    if (nvert > 10 || nvert <= 0) {
        return -1;
    }
    if (start > nvert || start <= 0) {
        return -1;
    }
    if (end > nvert || end <= 0) {
        return -1;
    } 
    return 0;
}

void print_matrix(int nvert, int matrix[][nvert]) {
    printf("\n");
    for (int i = 0; i < nvert; i++) {
        for (int j = 0; j < nvert; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dijkstra(int start, int end, int nvert, int matrix[][nvert]) {
    int d[nvert];        
    // минимальное расстояние
    int visit[nvert];        
    // посещенные вершины
    int minindex, min, temp;

    //Инициализация вершин и расстояний
    for (int i = 0; i < nvert; i++) {
        d[i] = MAX_LENGTH_PATH;
        visit[i] = 1;
    }
    d[start] = 0;
    // Шаг алгоритма
    do
    {
        minindex = MAX_LENGTH_PATH;
        min = MAX_LENGTH_PATH;

        for (int i = 0; i < nvert; i++) { 
            if ((visit[i] == 1) && (d[i] < min)) { 
                min = d[i];
                minindex = i;
            }
        }

        if (minindex != MAX_LENGTH_PATH) {
            for (int i = 0; i < nvert; i++) {
                if (matrix[minindex][i] > 0) {
                    temp = min + matrix[minindex][i];
                    if (temp < d[i]) {
                        d[i] = temp;
                    }
                }
            }
            visit[minindex] = 0;
        }
    } while (minindex < MAX_LENGTH_PATH);

    // Восстановление пути
    int ver[nvert];      
    // массив посещенных вершин
    ver[0] = end + 1;    
    int preg = 1;        
    // индекс предыдущей вершины
    int weight = d[end]; 
    // вес конечной вершины

    while (end != start) { 
        // пока не дошли до начальной вершины
        for (int i = 0; i < nvert; i++) { 
            // просматриваем все вершины
            if (matrix[i][end] != 0) {  
                // если связь есть
                int temp = weight - matrix[i][end]; 
                // определяем вес пути из предыдущей вершины
                if (temp == d[i]) {                   
                    // если вес совпал с рассчитанным, значит из этой вершины и был переход
                    weight = temp;  
                    // сохраняем новый вес
                    end = i;       
                    // сохраняем предыдущую вершину
                    ver[preg] = i + 1; 
                    // и записываем ее в массив
                    preg++;
                }
            }
        }
    }

    //Вывод пути (начальная вершина оказалась в конце массива из k элементов)
    printf("\nВывод кратчайшего пути\n");
    for (int i = preg - 1; i >= 0; i--) { 
        printf("%3d ", ver[i]);
    }
    printf("\n");
}