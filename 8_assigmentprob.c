#include <stdio.h>
#include <limits.h>

#define N 10

const int INF = INT_MAX;

int n; // Number of workers and tasks

// Recursive function to find minimum cost using branch and bound
int solveAssignment(int costMatrix[N][N], int worker, int assigned[N], int cost, int* minCost) {
    if (worker == n) {
        *minCost = (*minCost < cost) ? *minCost : cost;
        return *minCost;
    }

    for (int task = 0; task < n; task++) {
        if (assigned[task] == -1) {
            assigned[task] = worker;
            solveAssignment(costMatrix, worker + 1, assigned, cost + costMatrix[worker][task], minCost);
            assigned[task] = -1;
        }
    }

    return *minCost;
}

int main() {
    printf("Enter the number of workers/tasks: ");
    scanf("%d", &n);

    int costMatrix[N][N];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int assigned[N];
    for (int i = 0; i < n; i++) {
        assigned[i] = -1;
    }

    int minCost = INF;
    solveAssignment(costMatrix, 0, assigned, 0, &minCost);

    printf("Minimum cost for assignment: %d\n", minCost);

    return 0;
}

