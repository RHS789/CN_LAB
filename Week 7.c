#include <stdio.h>
#define MAX 20
#define INF 99999

int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index = -1;
    int v;
    for (v = 1; v <= V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int src, int V) {
    int i;
    printf("\nVertex \t Distance from Source (%d)\n", src);
    for (i = 1; i <= V; i++) {
        if (dist[i] == INF)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];
    int visited[MAX];
    int i, count, v;
    for (i = 1; i <= V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 1; count <= V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 1; v <= V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, src, V);
}

int main() {
    int V, i, j, source;
    int graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("\nEnter the adjacency matrix (0 if no edge):\n");
    for (i = 1; i <= V; i++) {
        for (j = 1; j <= V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nEnter the source vertex (1 to %d): ", V);
    scanf("%d", &source);
    dijkstra(graph, source, V);
    return 0;
}