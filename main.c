#include "library.h"
#define N 4
int main()
{
    ////////////////////если программа без коючей/////////////////////

    printf("Ваш граф выглядит так:\n");
    printf("[1] - [2]\n");
    printf(" |  X  |\n");
    printf("[4] - [3]\n");
    printf("\nРебро [1 - 2] = 26\nРебро [2 - 3] = 25\nРебро [3 - 4] = 13\n");
    printf("Ребро [4 - 1] = 25\nРебро [1 - 3] = 25\nРебро [2 - 4] = 28\n");
    /*ИНФОРМАЦИОННОЕ ПИСЬМО*/
    // не забудь написать,что граф полный


    //////////////////программа, если есть ключ "НАЙТИ КРАТЧАЙШИЙ ПУТЬ"////////////////////
   /* 
    struct graph* g = graph_create(N);    
    
    for(int i = 0; i < N; i++)                 
    {
        for(int j = i; j < N; j++)
        {
            graph_set_edge(g, i, j, getrand(10, 30));
        }
    }
    
    for(int i = 0; i  < N; i++)              // вывод графа, для пользователя не обязателен
    {
        for(int j=0; j  < N; j++)
        {
            printf("%d ", g->m[i][j]);
        }
        printf("\n");
    }
    
  // СЧИТЫВАЕМ НОМЕРА ГОРОДОВ (arg_1, arg_2)

    int city_1 = 2; // = arg_1
    int city_2 = 4; // = arg_2 

    int path[N] = {}; //массив для востановленного пути
    int pathlen = 0;
    printf("\nСамый короткий путь между городами %d -- %d:  ", city_1, city_2);
    if (city_1 == city_2)
    {
        printf("0\n");
        printf("Сам путь:  %d\n", city_2);
    }
    else
    {
        pathlen = SearchShortPath(g, city_1, city_2-1, path);
        printf("Сам путь:  %d ", city_1);
        for(int i = 1; i <= pathlen; i++)
        {
            if (path[i] == city_2-1)
            {
                path[i] = city_2;
            }
            printf("%d ",path[i]);
        }
    printf("\n");
    }
    
   

    graph_free(g, N); // второй аргумент для удобного использования функции
    
*/
    //////////////////программа, если есть ключ "НАЙТИ ДЛИННЕЙШИЙ ПУТЬ"////////////////////

    struct graph* g = graph_create(N);    
    
    for(int i = 0; i < N; i++)                 
    {
        for(int j = i; j < N; j++)
        {
            graph_set_edge(g, i, j, getrand(10, 30));
        }
    }
    
    for(int i = 0; i  < N; i++)              // вывод графа, для пользователя не обязателен
    {
        for(int j=0; j  < N; j++)
        {
            printf("%d ", g->m[i][j]);
        }
        printf("\n");
    }
    
  // СЧИТЫВАЕМ НОМЕРА ГОРОДОВ (arg_1, arg_2)

    int city_1 = 2; // = arg_1
    int city_2 = 4; // = arg_2 

    int path[N] = {}; //массив для востановленного пути
    int pathlen = 0;
    printf("\nСамый длинный путь между городами %d -- %d:  ", city_1, city_2);
    if (city_1 == city_2)
    {
        printf("0\n");
        printf("Сам путь:  %d\n", city_2);
    }
    else
    {
        pathlen = SearchLongPath(g, city_1, city_2-1, path);
        printf("Сам путь:  %d ", city_1);
        for(int i = 1; i <= pathlen; i++)
        {
            if (path[i] == city_2-1)
            {
                path[i] = city_2;
            }
            printf("%d ",path[i]);
        }
    printf("\n");
    }
    
    graph_free(g, N); // второй аргумент для удобного использования функции
    
    /*struct graph* g = graph_create(N);    
    
    for(int i = 0; i < N - 1; i++)                 
    {
        for(int j = i+1; j < N; j++)
        {
            graph_set_edge(g, i, j, getrand(10, 30));
        }
    }
    
    for(int i = 0; i  < N; i++)              // вывод графа, для пользователя не обязателен
    {
        for(int j=0; j  < N; j++)
        {
            printf("%d ", g->m[i][j]);
        }
        printf("\n");
    }
    
    int city_1 = 3; // = arg_1
    int city_2 = 2; // = arg_2 

    int path[N+1] = {}; //массив для востановленного пути
    int pathlen = 0;
    printf("\nСамый длинный путь между городами %d -- %d:  ", city_1, city_2);
    pathlen = SearchLongPath(g, city_1, city_2, path);
    printf("Сам путь:  %d ", city_1);
    for(int i = 1; i <= pathlen; i++)
    {
        printf("%d ",path[i]);
    }
    printf("\n");

    graph_free(g, N);*/

    //////////////////программа, если есть ключ "НАЙТИ ВСЕ МАРШРУТЫ"////////////////////


    return 0;
}
