#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if the string is a palindrome
int isPalindrome(char *start, char *end) {
    while (start < end) {
        // Skip non-alphanumeric characters
        while (start < end && !isalnum(*start)) start++;
        while (start < end && !isalnum(*end)) end--;

        // Compare characters (case insensitive)
        if (tolower(*start) != tolower(*end)) {
            return 0; // Not a palindrome
        }

        start++;
        end--;
    }
    return 1; // It's a palindrome
}

int main() {
    char buffer[1000];
    char *input;

    // Prompt the user for input
    printf("Enter a word or phrase: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--; // Adjust the length
    }

    // Dynamically allocate memory for the exact length of the input
    input = (char *)malloc((len + 1) * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Copy the input to the allocated memory
    strcpy(input, buffer);

    // Check if the input is a palindrome
    if (isPalindrome(input, input + len - 1)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }

    // Free allocated memory
    free(input);

    return 0;
}

