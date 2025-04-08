#include <stdio.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t%d ", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V], parent[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, parent[i] = -1;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V], source;
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter source vertex (0-%d): ", V - 1);
    scanf("%d", &source);
    dijkstra(graph, source);
    return 0;
}
/*
Enter adjacency matrix:
0 1 6 5 0 2
1 0 7 1 0 0
6 7 0 0 0 3
5 1 0 0 4 0
0 0 0 4 0 8
2 0 3 0 8 0
Enter source vertex (0-5): 0
Vertex  Distance        Path
0       0               0
1       1               0 1
2       5               0 5 2
3       2               0 1 3
4       6               0 1 3 4
5       2               0 5
*/
