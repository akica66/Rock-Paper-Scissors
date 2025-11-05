
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>  

//choiceToString transforms the integers into choices Rock, Paper or Scissors 
std::string choiceToString(int choice) {
    switch (choice) {
    case 1: return "Rock";
    case 2: return "Paper";
    case 3: return "Scissors";
    default: return "INVALID CHOICE";
    }
}

int main() {
    // Seed the random number generator using the current time
    // This ensures the computer's choice is different each time the program runs.
    std::srand(std::time(0));

    // START OF LOOP: 
    // Variable to control the game loop
    char play_again = 'y';

    // Main game loop: continues as long as the user enters 'y' or 'Y'
    while (play_again == 'y' || play_again == 'Y') {

        int user_choice;
        int computer_choice;

        std::cout << "\n--------------------------------\n";
        std::cout << "       ROCK, PAPER, SCISSORS      \n";
        std::cout << "--------------------------------\n";
        std::cout << "Enter your choice:\n";
        std::cout << "1 for Rock\n";
        std::cout << "2 for Paper\n";
        std::cout << "3 for Scissors\n";
        std::cout << "Selection: ";

        if (!(std::cin >> user_choice)) {
            // Handle case where input is not a number (e.g., user types 'a')
            std::cout << "Invalid input type. Please enter a number.\n"; //Informs the user of the bad answer
            std::cin.clear(); //Clears the error flag
            std::cin.ignore(10000, '\n'); //Discards the Bad Data
            continue; // Go back to the start of the while loop
        }

        
        if (user_choice < 1 || user_choice > 3) {
            std::cout << "Invalid selection (" << user_choice << "). Please choose 1, 2, or 3.\n";
            continue; // Go back to the start of the while loop
        }

        computer_choice = (std::rand() % 3) + 1;
        std::cout << "\n--- Moves Played ---\n";
        std::cout << "Your choice: " << choiceToString(user_choice) << "\n";
        std::cout << "Computer's choice: " << choiceToString(computer_choice) << "\n";
        std::cout << "--------------------\n\n";


        if (user_choice == computer_choice) {
            std::cout << "TIE!\n";
        }
        else if (
            (user_choice == 1 && computer_choice == 3) || // Rock beats Scissors
            (user_choice == 2 && computer_choice == 1) || // Paper beats Rock
            (user_choice == 3 && computer_choice == 2)    // Scissors beats Paper
            ) {
            std::cout << "You WIN this round!\n";
        }
        else {
            std::cout << "Computer WINS this round!\n";
        }



        std::cout << "\n================================\n"; 
        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;
        std::cout << "================================\n\n";

        // Crucial line: clears the input buffer before the next loop run
        std::cin.ignore(10000, '\n');
    }
    // END OF LOOP CHANGES

    std::cout << "Thanks for playing! Goodbye.\n";
    return 0; // Exits the program successfully
}
