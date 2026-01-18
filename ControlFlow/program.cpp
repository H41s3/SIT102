#include "splashkit.h"
using namespace std;

// Global constant for the Strouhal number
const double STROUHAL_NUMBER = 0.3;

string read_string(string prompt) {
    write(prompt);
    return read_line();
}

int read_integer(string prompt) {
    string line;
    int result;

    line = read_string(prompt);
    result = convert_to_integer(line);

    return result;
}

// Implementation for reading a double
double read_double(string prompt) {
    string line;
    double result;

    line = read_string(prompt);
    result = convert_to_double(line);

    return result;
}

// Implementation for calculating air speed velocity
double air_speed(int frequency, double amplitude) {
    return frequency * amplitude * STROUHAL_NUMBER;
}

// Implementation for custom multiplication and formatting
string multiply_and_format(int num1, int num2) {
    int result = num1 * num2;
    return "The multiplication of " + to_string(num1) + " and " + to_string(num2) + " is " + to_string(result);
}

// Function (enter a name and get custom messages based upon the name entered.)
void display_custom_messages(string name) {
    if (name == "Rhei") {
        write_line("Hello Rhei");
    } else if (name == "Edrick") {
        write_line("Hey Edrick, Thanks for telling me about python 3 years ago.");
    } else if (name == "Suman") {
        write_line("Hello Mr. Suman, you're a fantastic teacher.");
    } else {
        write_line("Hello, " + name + ". Please don't die.");
    }
}

// Function that allows the user to play a guess that number game, guessing a value between 1 and 100.
void guess_number_game() {
    int answer_number = 11;
    int player_guess;

    write_line("Guess a number between 1 and 100:");

    while (true) {
        player_guess = read_integer("Your guess: ");

        if (player_guess < answer_number) {
            write_line("Wrong! Your guess is too low.");
        } else if (player_guess > answer_number) {
            write_line("Wrong! Your guess is too high.");
            } else {
                write_line("Well Done! You guessed the correct number.");
                break;
        }
    }
}

int main() {
    int select_option;
    
    do {
        write_line("Menu");
        write_line("1. Enter name and get custom message");
        write_line("2. Calculate airspeed velocity");
        write_line("3. Multiply two numbers");
        write_line("4. Guess a number between 1 and 100 game");
        write_line("5. Exit");
        select_option = read_integer("Select an option: ");

        switch (select_option) {
            case 1: {
                string name = read_string("Enter name: ");
                display_custom_messages(name);
                break;
            }
            case 2: {
                int age = read_integer("Enter your age: ");
                write_line("Welcome! You are " + to_string(age) + " years old.");

                // To calculate the air speed velocity for African Swallow
                double african_swallow_frequency = air_speed(15, 21.0);
                write_line("African Swallow airspeed velocity: " + to_string(african_swallow_frequency) + " m/s");

                // // To calculate the air speed velocity for European Swallow
                double european_swallow_speed = air_speed(14, 22.0);
                write_line("European Swallow air speed velocity: " + to_string(european_swallow_speed) + " m/s");

                // Example of custom bird
                double custom_bird_speed = air_speed(12, 25.0);
                write_line("Custom Bird air speed velocity: " + to_string(custom_bird_speed) + " m/s");
                break;
            }
            case 3: {
                // Use the custom multiplication function
                int num1 = read_integer("Enter the first number: ");
                int num2 = read_integer("Enter the second number: ");
                string multiplication_result = multiply_and_format(num1, num2);
                write_line(multiplication_result);
                break;
            }
            case 4: 
                guess_number_game();
                break;
            case 5:
                write_line("Exiting the program. Sayōnara!");
                break;
            default:
                write_line("Invalid option. Please select a valid option.");
                break;
        }
    } while (select_option != 5);

    return 0;
}



/*
Emilio Joseph Calma (5021259)
Based on ontrack requirements:
Has a menu to allow users to select and run multiple different actions.
Allow the user to enter a name and get custom messages based upon the name entered. (I reused the code from my HelloUser 2.2)
Use the names of your friends and teacher and write a custom message for each.
Allow the user to play a guess that number game, guessing a value between 1 and 100.
*/