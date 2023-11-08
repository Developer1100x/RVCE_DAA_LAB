#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int a[10][10];
    int i, j, k, node;
    int in[10] = {0};
    int v[10] = {0};

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    printf("Enter adj matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                in[j]++;
            }
        }
    }

    printf("Topological order:\n");
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            if (in[i] == 0 && v[i] == 0) {
                node = i;
                printf("%5d", node);
                v[node] = 1;
                break;
            }
        }

        for (i = 1; i <= n; i++) {
            if (a[node][i] == 1) {
                in[i]--;
            }
        }
    }

    printf("\n");

    return 0;
}

