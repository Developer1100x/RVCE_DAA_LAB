#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int count;

void merge(int a[MAX], int low, int mid, int high) {
    int i, j, k, b[MAX];
    i = low;
    j = mid + 1;
    k = low;
    
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
        count++;
    }
    
    while (i <= mid) {
        b[k++] = a[i++];
        count++;
    }
    
    while (j <= high) {
        b[k++] = a[j++];
        count++;
    }
    
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergesort(int a[MAX], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int i, j, n, a[MAX], b[MAX], c[MAX];
    int c1, c2, c3;
    
    printf("\nMERGE SORT\n");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    count = 0;
    mergesort(a, 0, n - 1);
    printf("\nThe sorted elements of the array: ");
    
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n\nNumber of comparisons: %d\n", count);
    printf("\nSIZE\tASC\tDESC\tRAND\n");
    
    // For time complexity analysis, using 3 arrays
    for (i = 16; i <= 512; i *= 2) {
        for (j = 0; j < i; j++) {
            a[j] = j;                   // Array filled with elements in strictly ascending order
            b[j] = i - j;               // Array filled with elements in strictly descending order
            c[j] = rand() % (i * 10);   // Array filled with elements in random order
        }
        
        count = 0;
        mergesort(a, 0, i - 1); // Ascending array is sorted
        c1 = count;

        count = 0;
        mergesort(b, 0, i - 1); // Descending array is sorted
        c2 = count;

        count = 0;
        mergesort(c, 0, i - 1); // Random array is sorted
        c3 = count;

        printf("\n %d\t %d\t %d\t %d", i, c1, c2, c3);
    }

    printf("\n");
    return 0;
}

