#include <stdio.h>

void performOperation(int *a, int *b, char op, int *result, int *isValid) {
    *isValid = 1;  // Assume operation is valid by default

    switch (op) {
        case '+':
            *result = *a + *b;
            break;
        case '-':
            *result = *a - *b;
            break;
        case '*':
            *result = *a * *b;
            break;
        case '/':
            if (*b != 0) {
                *result = *a / *b;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                *isValid = 0;
            }
            break;
        case '%':
            if (*b != 0) {
                *result = *a % *b;
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
                *isValid = 0;
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            *isValid = 0;
    }
}

int main() {
    int num1, num2, result, isValid;
    char operator;

    // Input numbers and operator
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter an operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform the operation using pointers
    performOperation(&num1, &num2, operator, &result, &isValid);

    // Display result if valid
    if (isValid) {
        printf("Result: %d %c %d = %d\n", num1, operator, num2, result);
    }

    return 0;
}

