#include <stdio.h>
#include<string.h>

void reverseString(char *str) {
    char *start = str;                // Pointer to the beginning of the string
    char *end = str;                  // Pointer to the end of the string

    // Move the `end` pointer to the last character of the string
    while (*end != '\0') {
        end++;
    }
    end--;  // Move back to the last character (excluding '\0')

    // Swap characters using pointers
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;  // Move the start pointer forward
        end--;    // Move the end pointer backward
    }
}

int main() {
    char input[100];  // Array to store the input string (max 99 characters)
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);  // Get the input string
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character if present

    reverseString(input);  // Reverse the string using pointers
    printf("Reversed string: %s\n", input);  // Print the reversed string

    return 0;
}

