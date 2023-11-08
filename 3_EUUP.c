#include <stdio.h>
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;int n1 = middle - left + 1;int n2 = right - middle;
    int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
int isUnique(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 0; 
            }
        }
    }
    return 1; 
}
int exists(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0;
}
int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, size - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nUnique Elements: ");
    printf("%d ", arr[0]); // Print the first element as it's always unique
    for (int i = 1; i < size; i++) {
        if (!exists(arr, i, arr[i])) {
            printf("%d ", arr[i]); // Print unique elements
        }
    }
    if (isUnique(arr, size)) {
        printf("\nThe array is unique.\n");
    } else {
        printf("\nThe array is not unique.\n");
    }
    printf("\n");
    return 0;
}