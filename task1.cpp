#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Define the range for the random number
    const int lowerBound = 1;
    const int upperBound = 100;
    int secretNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;

    int guess;
    int attempts = 0;
    bool hasGuessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have chosen a number between " << lowerBound << " and " << upperBound << ".\n";
    std::cout << "Can you guess what it is?\n";

    while (!hasGuessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            hasGuessedCorrectly = true;
            std::cout << "Congratulations! You've guessed the number " << secretNumber << " correctly!\n";
            std::cout << "It took you " << attempts << " attempts.\n";
        }
    }

    return 0;
}