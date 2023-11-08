#include <stdio.h>
#include <stdlib.h>

int w[10]; // Denotes set s
int x[10]; // Boolean array which tells if an element is part of the subset or not
int d;     // Max value received when an element is added to the subset

void sumSubset(int s, int k, int r) {
    int i;
    static int b = 1; // Number of subsets
    x[k] = 1;
    if (s + w[k] == d) {
        printf("\nSubset %d) ", b++);
        for (i = 1; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d\t", w[i]);
            }
        }
    } else if (s + w[k] + w[k + 1] <= d) {
        sumSubset(s + w[k], k + 1, r - w[k]);
    }
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d)) {
        x[k] = 0;
        sumSubset(s, k + 1, r - w[k]);
    }
}

int main() {
    int n, i, sum = 0;
    printf("\nSUBSET PROBLEM\n");
    printf("\nEnter the number of elements - ");
    scanf("%d", &n);
    printf("\nEnter the elements (in increasing order) - ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("\nEnter the subset max value required - ");
    scanf("%d", &d);
    if (sum < d || w[1] > d) {
        printf("\nNo subsets possible!!\n");
        exit(0);
    }

    sumSubset(0, 1, sum); // 0-s 1-k sum-r
    return 0;
}

