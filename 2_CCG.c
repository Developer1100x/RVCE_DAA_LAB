#include <stdio.h>
#include <stdlib.h>

void dfs(int a[10][10], int n, int v[10], int source) {
    int i;
    v[source] = 1;
    printf("%d ", source);
    for (i = 0; i < n; i++) {
        if (a[source][i] == 1 && v[i] == 0) {
            dfs(a, n, v, i);
        }
    }
}

void bfs(int a[10][10], int n, int v[10], int source) {
    int q[10], front = 0, rear = -1;
    int node, i;
    v[source] = 1;
    printf("%d ", source);
    q[++rear] = source;
    while (front <= rear) {
        node = q[front++];
        for (i = 0; i < n; i++) {
            if (a[node][i] == 1 && v[i] == 0) {
                printf("%d ", i);
                v[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

int main() {
    int n, i, j;
    int a[10][10];
    int v[10];
    int count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nRead Adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDFS:\n");
    for (i = 0; i < n; i++) {
        v[i] = 0; // Mark all nodes as unvisited
    }
    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            dfs(a, n, v, i);
            count++;
        }
    }
    if (count == 1)
        printf("\nGraph is Connected\n");
    else
        printf("\nGraph is NOT Connected with %d Components\n", count);

    printf("\nBFS:\n");
    for (i = 0; i < n; i++) {
        v[i] = 0; // Mark all nodes as unvisited
    }
    count = 0;
    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            bfs(a, n, v, i);
            count++;
        }
    }
    if (count == 1)
        printf("\nGraph is Connected\n");
    else
        printf("\nGraph is NOT Connected with %d Components\n", count);

    return 0;
}

