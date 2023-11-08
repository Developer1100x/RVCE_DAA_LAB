#include <stdio.h>
#include <stdbool.h>

#define N 10  // Maximum number of cities

void tsp(int graph[N][N], int n, bool visited[N], int currPos, int count, int cost, int* ans) {
    if (count == n && graph[currPos][0]) {
        *ans = (*ans < cost + graph[currPos][0]) ? *ans : cost + graph[currPos][0];
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tsp(graph, n, visited, i, count + 1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[N][N];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool visited[N];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    int ans = 1 << 30;  // Initialize ans with a large value

    tsp(graph, n, visited, 0, 1, 0, &ans);

    printf("Minimum cost for TSP: %d\n", ans);

    return 0;
}

