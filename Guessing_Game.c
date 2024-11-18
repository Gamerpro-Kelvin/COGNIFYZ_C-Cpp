#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int *targetNumber) {
    int guess;
    int *userGuess = &guess;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", userGuess);

        if (*userGuess > *targetNumber) {
            printf("Lower!\n");
        } else if (*userGuess < *targetNumber) {
            printf("Higher!\n");
        } else {
            printf("Congratulations! You've guessed the correct number: %d\n", *targetNumber);
            break;
        }
    }
}

int main() {
    int targetNumber;
    int *target = &targetNumber;

    // Initialize random number generator
    srand(time(0));
    *target = (rand() % 100) + 1;  // Generates a number between 1 and 100

    // Start the guessing game
    playGame(target);

    return 0;
}

