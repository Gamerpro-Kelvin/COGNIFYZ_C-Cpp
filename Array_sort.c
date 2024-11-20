#include <stdio.h>
#include <stdlib.h>

int compareAscending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compareDescending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, order;
    int *array;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    // Choose sorting order
    printf("Choose sorting order (1 for Ascending, 2 for Descending): ");
    scanf("%d", &order);

    // Sort using qsort
    if (order == 1) {
        qsort(array, n, sizeof(int), compareAscending);
    } else {
        qsort(array, n, sizeof(int), compareDescending);
    }

    // Display sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    // Free allocated memory
    free(array);

    return 0;
}
