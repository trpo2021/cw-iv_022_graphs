#include "graphs.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void DijkstraShort(struct graph *g, int src, int *d, int **prev)
{
    heap *h;
    heapnode node;
    h = heap_create(g->nvertices);                // куча создана
    
    for (int i = 1; i <= g->nvertices; i++)       //заполняем кучу вершинами с приоритетом
    {
        if(i == src)
        {
            d[i] = 0;
        } else {
            d[i] = INT_MAX;
        }
        
        (*prev)[i] = -1;
        heap_insert(h, d[i], i);
    }

    for (int i = 1; i <= g->nvertices; i++) 
    {
        node = heap_extract_min(h);                                              // Извлекаем узел

        g->visited[node.value - 1] = 1;                                          // Отмечаем node как посещенную

        for(int j = 1; j <= g->nvertices; j++)                                  // Цикл по смежным вершинам node
        {
            if(graph_get_edge(g, node.value - 1, j) && !g->visited[j - 1]) 
            {
                if(d[node.value] + graph_get_edge(g, node.value - 1, j) < d[j]) // проверка суммы ребер
                {
                    d[j] = d[node.value] + graph_get_edge(g, node.value - 1, j);
                    heap_decrease_key(h, j, d[j]);
                    (*prev)[j] = node.value;
                }
            }
        }
    }
    heap_free(h);
}

void DijkstraLong(struct graph *g, int src, int *d, int **prev)
{
    heap *h;
    heapnode node;
    h = heap_create(g->nvertices);                // куча создана
    
    for(int i = 1; i <= g->nvertices; i++)       //заполняем кучу вершинами с приоритетом
    {
        if(i == src)
        {
            d[i] = 0;
        } else {
            d[i] = -1;
        }

        (*prev)[i] = -1;
        heap_insert(h, d[i], i);
    //    printf("\n%d  %d\n",i,  d[i]);
    }

    for(int i = 1; i <= g->nvertices; i++) 
    {
        node = heap_extract_max(h);                                             // Извлекаем узел

        g->visited[node.value - 1] = 1;  


        for(int j = 1; j <= g->nvertices; j++)                                  // Цикл по смежным вершинам node
        {
            if(graph_get_edge(g, node.value - 1, j) && !g->visited[j - 1]) 
            {
                if(d[node.value] + graph_get_edge(g, node.value - 1, j) > d[j]) // проверка суммы ребер
                {
                    d[j] = d[node.value] + graph_get_edge(g, node.value - 1, j);
                    heap_increase_key(h, j, d[j]);
                    (*prev)[j] = node.value;
                }
            }
        }
    }
    heap_free(h);
}

int SearchShortPath(struct graph* g, int src, int dst, int* path)
{
    int* array = calloc(g->nvertices, sizeof(int));
    int** prev = calloc(g->nvertices, sizeof(int));
    *prev = calloc(g->nvertices, sizeof(int));

    DijkstraShort(g, src, array, prev); // возвращает указатель на массивы путей и длин этих путей

    int i = dst;
    int pathlen = 0;
    int j = 0;

    while(i != src && i < g->nvertices)
    {
        pathlen = pathlen + 1;
        i = (*prev)[i];
        
    }

    i = dst;
    path[pathlen] = dst;

    while(i != src)
    {
        i = (*prev)[i];
        path[pathlen - j - 1] = i;
        j++;
    }
    
    printf("%d\n", array[dst]);
    return pathlen;
}


int SearchLongPath(struct graph* g, int src, int dst, int* path)
{
    int* array = calloc(g->nvertices, sizeof(int));
    int** prev = calloc(g->nvertices, sizeof(int));
    *prev = calloc(g->nvertices, sizeof(int));

    DijkstraLong(g, src, array, prev); // возвращает указатель на массивы путей и длин этих путей

    int i = dst;
    int pathlen = 0;
    int j = 0;

    while(i != src && i < g->nvertices)
    {
        pathlen = pathlen + 1;
        i = (*prev)[i];
        
    }

    i = dst;
    path[pathlen] = dst;

    while(i != src)
    {
        i = (*prev)[i];
        path[pathlen - j - 1] = i;
        j++;
    }
    
    printf("%d\n", array[dst]);
    return pathlen;
}

void AllPaths(int *array_cities)
{
    if((array_cities[1]+1 != array_cities[2]) && (array_cities[1]+1 <= 4))
    {
        array_cities[3] = array_cities[1]+1;

        if((array_cities[2]-1 >= 1) && (array_cities[2]-1 != array_cities[3]) && (array_cities[2]-1 != array_cities[1]))
        {
            array_cities[4] = array_cities[2]-1;
        } else {
            array_cities[4] = array_cities[2]+1;
        }
            
    } else {
        if((array_cities[1]-1 != array_cities[2]) && (array_cities[1] > 1))
        {
                array_cities[3] = array_cities[1]-1;
        } else {
            if(array_cities[1] == 1)
            {
                array_cities[3] = array_cities[1] + 3;
            } else {
                array_cities[3] = array_cities[1] - 3;
            }
        }

        if((array_cities[2]-1 >= 1) && (array_cities[2]-1 != array_cities[3]) && (array_cities[2]-1 != array_cities[1]))
        {
            array_cities[4] = array_cities[2]-1;
        } else {
            array_cities[4] = array_cities[2]+1;
        } 
    }
}

void Length_and_Paths(int *array_cities, struct graph *g)
{
    printf("1 Путь. Вершины:  %d -> %d\n", array_cities[1], array_cities[2]);
    printf("Длина: %d\n", g->m[array_cities[1]-1][array_cities[2]-1]);

    int t = array_cities[3];

    for(int i = 2; i <= 3; i++)
    { 
        printf("%d Путь. Вершины:  ", i);
        printf("%d -> %d -> %d\n", array_cities[1], t, array_cities[2]);
        // вынести в функцию "Длина"
        int dlina = 0;
        dlina = g->m[array_cities[1]-1][t-1] + g->m[t-1][array_cities[2]-1];

        printf("Длина:  %d\n", dlina);
        t = array_cities[4];
    }

    int b = array_cities[3];

    for(int i = 4; i <= 5; i++)
    {
        printf("%d Путь. Вершины:  ", i);
        printf("%d -> %d -> %d -> %d\n", array_cities[1], b, t, array_cities[2]);
        int dlina = 0;
        dlina = g->m[array_cities[1]-1][b-1] + g->m[b-1][t-1] + g->m[t-1][array_cities[2]-1];
        printf("Длина:  %d\n", dlina);
        b = t;
        t = array_cities[3];
    }
}

void graph_clear(struct graph *g, int N)
{
    for(int i = 1; i < N - 1; i++)                 
    {
        for(int j = 0; j < N; j++)
        {
            g->m[i][j] = 0;
        }

    }
}

void graph_set_edge(struct graph *g, int i, int j, int w)
{
    if(i == j)
    {
        g->m[i][j] = 0;
    } else {
        g->m[i][j] = w;
        g->m[j][i] = w;
    }
}

int graph_get_edge(struct graph *g, int i, int j)
{
    return g->m[i][j];
}

struct graph *graph_create(int nvertices)
{
    struct graph *g;
    g = malloc(sizeof(*g));
    g->nvertices = nvertices;
    g->m = malloc(sizeof(int*) * nvertices);

    for(int i = 0; i < nvertices; i++)
    {
        g->m[i] = malloc(sizeof(int) * nvertices);
    }

    g->visited = malloc(sizeof(int) * nvertices);

    graph_clear(g, nvertices);
    return g;
}

void graph_free(struct graph *g, int N)
{
    free(g->visited);

    for(int i = 0; i < N; i++)
    {
        free(g->m[i]);
    }

    free(g->m);
    free(g);
}

heap *heap_create(int maxsize) 
{
    heap *h;
    h = malloc(sizeof(*h));

    if(h != NULL) 
    {
        h->maxsize = maxsize;
        h->nnodes = 0;
        h->index = (int *) malloc(sizeof(int) * (maxsize + 1));
        h->nodes = (heapnode *) malloc(sizeof(*h->nodes) * (maxsize + 1));

        if(h->nodes == NULL) 
        {
            free(h);
            return NULL;
        }
    }
    return h;
}

void heap_free(heap *h) 
{
    free(h->index);
    free(h->nodes);
    free(h);
}

void heap_swap(heapnode *a, heapnode *b, heap *h) 
{
    heapnode temp = *a;
    *a = *b;
    *b = temp;

    int tmp = h->index[a->value];
    h->index[a->value] = h->index[b->value];
    h->index[b->value] = tmp;
}

int heap_insert(heap *h, int key, int value) 
{
    if(h->nnodes >= h->maxsize) 
    {
        return -1;
    }

    h->nnodes++;
    h->nodes[h->nnodes].key = key;
    h->nodes[h->nnodes].value = value;
    h->index[value] = h->nnodes;

    for(int i = h->nnodes; i > 1 && h->nodes[i].key < h->nodes[i / 2].key; i = i / 2) 
    {
        heap_swap(&h->nodes[i], &h->nodes[i / 2], h);
    }
    return 0;
}

heapnode heap_extract_min(heap *h) 
{
    if(h->nnodes == 0) 
    {
        return (heapnode) {0, 0};
    }

    heapnode node = h->nodes[1];
    h->nodes[1] = h->nodes[h->nnodes];
    h->index[h->nodes[h->nnodes].value] = 1;
    h->nnodes--;

    heap_heapify_min(h, 1);

    return node;
}

heapnode heap_extract_max(heap *h) 
{
    if(h->nnodes == 0) 
    {
        return (heapnode) {0, 0};
    }

    heapnode node = h->nodes[1];
    h->nodes[1] = h->nodes[h->nnodes];
    h->index[h->nodes[h->nnodes].value] = 1;
    h->nnodes--;

    heap_heapify_max(h, 1);

    return node;
}

void heap_heapify_min(heap *h, int index) 
{
    while (1)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int node = index;

        if(left <= h->nnodes && h->nodes[left].key < h->nodes[index].key) 
        {
            node = left;
        }

        if(right <= h->nnodes && h->nodes[right].key < h->nodes[node].key) 
        {
            node = right;
        }

        if(node == index) 
        {
            break;
        }

        heap_swap(&h->nodes[index], &h->nodes[node], h);
        index = node;
    }
}

void heap_heapify_max(heap *h, int index) 
{
    while (1)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int node = index;

        if(left <= h->nnodes && h->nodes[left].key > h->nodes[index].key) 
        {
            node = left;
        }

        if(right <= h->nnodes && h->nodes[right].key > h->nodes[node].key) 
        {
            node = right;
        }

        if(node == index) 
        {
            break;
        }

        heap_swap(&h->nodes[index], &h->nodes[node], h);
        index = node;
    }
}

int heap_decrease_key(heap *h, int index, int newkey) 
{
    index = h->index[index];

    if(h->nodes[index].key < newkey) 
    {
        return -1;
    }

    h->nodes[index].key = newkey;

    for(; index > 1 && h->nodes[index].key < h->nodes[index / 2].key; index = index / 2) 
    {
        heap_swap(&h->nodes[index], &h->nodes[index / 2], h);
    }

    return index;
}

int heap_increase_key(heap *h, int index, int newkey) 
{
    index = h->index[index];

    if(h->nodes[index].key >= newkey) 
    {
        return -1;
    }

    h->nodes[index].key = newkey;

    for(; index > 1 && h->nodes[index].key > h->nodes[index / 2].key; index = index / 2) 
    {
        heap_swap(&h->nodes[index], &h->nodes[index / 2], h);
    }

    return index;
}