#include <stdio.h>
#define INF 99999
// so this is the bellman ford algo;
void bellmanFord(int cost[7][7], int V, int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (cost[u][v] != INF && dist[u] + cost[u][v] < dist[v])
                    dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (cost[u][v] != INF && dist[u] != INF && dist[u] + cost[u][v] < dist[v])
                printf("Graph me negative weight cycle hai ji..\n");
        }
    }

    printf("Vertex ka Distance, source se toh dalo ji: \n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V = 7;
    int cost[7][7] = {
        {0, 6, 5, 5, INF, INF, INF},
        {INF, 0, INF, INF, -1, INF, INF},
        {INF, -2, 0, INF, 1, INF, INF},
        {INF, INF, INF, 0, INF, -1, INF},
        {INF, INF, INF, INF, 0, INF, 3},
        {INF, INF, INF, INF, INF, 0, 3},
        {INF, INF, INF, INF, INF, INF, 0}
    };

    // Ensure cost array is properly initialized before calling bellmanFord
    bellmanFord(cost, V, 0);

    return 0;
}
