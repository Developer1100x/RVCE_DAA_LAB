#include <stdio.h>
#include <stdlib.h>

int count;

int partition(int a[], int left, int right) {
    int i, j, pivot, temp;
    pivot = a[left];
    i = left + 1;
    j = right;
    while (1) {
        while (pivot >= a[i] && i <= right) {
            i++;
            count++;
        }
        while (pivot < a[j] && j > left) {
            j--;
            count++;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            a[left] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}

void QuickSort(int a[], int left, int right) {
    int s;

    if (left < right) {
        s = partition(a, left, right);
        QuickSort(a, left, s - 1);
        QuickSort(a, s + 1, right);
    }
}

int main() {
    int a[100], x[1000], y[1000], z[1000];
    int i, j, n, ele, c1, c2, c3;
    printf("\nQUICK SORT\n");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ele);
        a[i] = ele;
    }

    count = 0;
    QuickSort(a, 0, n - 1);
    printf("\nThe sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\nNumber of comparisons: %d\n", count);

    printf("\nSIZE\tASC\tDESC\tRAND\n");
    // For time complexity analysis, using 3 arrays
    for (i = 16; i <= 512; i *= 2) {
        for (j = 0; j < i; j++) {
            x[j] = j;               // Array filled with elements in ascending order
            y[j] = i - j;           // Array filled with elements in descending order
            z[j] = rand() % (i * 10); // Array filled with elements in random order
        }
        
        count = 0;
        QuickSort(x, 0, i - 1); // Ascending array is sorted
        c1 = count;

        count = 0;
        QuickSort(y, 0, i - 1); // Descending array is sorted
        c2 = count;

        count = 0;
        QuickSort(z, 0, i - 1); // Random array is sorted
        c3 = count;

        printf("\n%d\t%d\t%d\t%d", i, c1, c2, c3);
    }

    printf("\n");
    return 0;
}

