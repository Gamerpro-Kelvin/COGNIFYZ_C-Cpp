#include <stdio.h>

void generateFibonacci(int *terms, int *series) {
    int *ptr1 = &series[0];  // Pointer to the first element of the series
    int *ptr2 = &series[1];  // Pointer to the second element of the series

    // Initialize the first two terms of the Fibonacci series
    *ptr1 = 0;
    *ptr2 = 1;

    for (int i = 2; i < *terms; i++) {
        // Calculate the next term using pointers
        *(series + i) = *(ptr1) + *(ptr2);
        ptr1++;
        ptr2++;
    }
}

int main() {
    int n;

    // Prompt user for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of terms should be greater than 0.\n");
        return 1;
    }

    int series[n];  // Array to store Fibonacci series

    // Generate the Fibonacci series
    generateFibonacci(&n, series);

    // Display the Fibonacci series
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(series + i));
    }
    printf("\n");

    return 0;
}

