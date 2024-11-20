#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *choices[] = {"Rock", "Paper", "Scissors"};

int main() {
    int userChoice, computerChoice;
    int userWins = 0, computerWins = 0, ties = 0;
    int rounds, currentRound;
    char *roundResult;

    // Seed the random number generator
    srand(time(NULL));

    // Ask the user how many rounds to play
    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &rounds);

    // Play the specified number of rounds
    for (currentRound = 1; currentRound <= rounds; currentRound++) {
        printf("\n--- Round %d ---\n", currentRound);

        // Display choices
        printf("Choose an option:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &userChoice);

        // Validate user input
        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice! Round forfeited.\n");
            computerWins++;
            continue;
        }

        // Generate computer's choice
        computerChoice = (rand() % 3) + 1;

        // Determine the result
        if (userChoice == computerChoice) {
            roundResult = "It's a tie!";
            ties++;
        } else if ((userChoice == 1 && computerChoice == 3) || 
                   (userChoice == 2 && computerChoice == 1) || 
                   (userChoice == 3 && computerChoice == 2)) {
            roundResult = "You win this round!";
            userWins++;
        } else {
            roundResult = "Computer wins this round!";
            computerWins++;
        }

        // Display results
        printf("You chose: %s\n", choices[userChoice - 1]);
        printf("Computer chose: %s\n", choices[computerChoice - 1]);
        printf("%s\n", roundResult);
    }

    // Display final results
    printf("\n--- Final Results ---\n");
    printf("Your Wins: %d\n", userWins);
    printf("Computer Wins: %d\n", computerWins);
    printf("Ties: %d\n", ties);

    if (userWins > computerWins) {
        printf("Congratulations! You are the overall winner!\n");
    } else if (computerWins > userWins) {
        printf("Computer is the overall winner! Better luck next time.\n");
    } else {
        printf("It's an overall tie!\n");
    }

    return 0;
}

