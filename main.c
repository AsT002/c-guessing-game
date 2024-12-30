#include <time.h>   // Needed for time() function
#include <stdio.h>  // Needed for printf() and fscanf()
#include <stdlib.h> // Needed for srand(), rand(), and atol()

/**
 * game_loop
 * ---------
 * This function handles the main guessing logic of the game.
 *
 * Parameters:
 *  - range (long*): A pointer to a long value that specifies
 *                   the upper bound (exclusive) for the random number.
 *
 * Returns:
 *  - int: A return value of 0 indicates the game ended normally.
 */
int game_loop(long *range)
{
    long random_number = rand() % *range; // Generate a random number between 0 and (*range - 1)

    long guess = -1; // Variable to store the user's guess; initialized to -1

    // The loop will keep running until the guess matches the random number
    while (guess != random_number)
    {
        // Prompt user to guess a number
        printf("Guess a random number between 0 and %ld: ", *range - 1);
        fscanf(stdin, "%ld", &guess); // Read user's guess from standard input

        // Check if the guess is correct
        if (guess != random_number)
        {
            // If not correct, provide a hint: higher or lower
            if (guess > random_number)
            {
                printf("Oops! That number is a higher than my number.\n");
            }
            else
            {
                printf("Nope! That number is lower than my number.\n");
            }
        }
        else
        {
            // Correct guess
            printf("You got it! (%ld) is my number.\n", random_number);
            break; // Break out of the loop upon correct guess
        }
    }

    return 0; // Return 0 to indicate successful completion
}

/**
 * main
 * ----
 * The entry point of the program. It sets up the game range and
 * starts the game loop. After each round, it asks if the user
 * wants to continue playing.
 *
 * Parameters:
 *  - argc (int): Number of command-line arguments
 *  - argv (char**): Array of command-line argument strings
 *
 * Returns:
 *  - int: Program exit status (0 for normal termination)
 */
int main(int argc, char **argv)
{
    srand(time(NULL)); // Seed the random number generator with the current time
    long range = 101;  // The default range for the random number (0 to 100)

    // If the user provided a command-line argument, use it to set the range
    if (argc > 1)
    {
        range = atol(argv[1]); // Convert the first command line argument to a long
    }

    // Use an infinite loop to allow multiple rounds of the game
    while (1)
    {
        // Call game_loop and check if it returns 0 (successful run)
        if (game_loop(&range) == 0)
        {
            // Ask the user if they'd like to play again
            printf("Would you like to play again? (Y/N): ");
            char answer = '\0';
            fscanf(stdin, " %c", &answer); // Read the user's response

            // If user chooses 'Y' or 'y', start a new round
            if (answer == 'Y' || answer == 'y')
            {
                printf("Let's begin another round!\n");
            }
            else
            {
                // If user chooses anything else, break out of loop and end the game
                break;
            }
        }
    }

    // Final message displayed upon exiting the loop
    printf("Thanks for playing the game!\n");

    return 0; // Return 0 to indicate successful program termination
}