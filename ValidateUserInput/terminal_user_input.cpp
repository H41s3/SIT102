#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;

string read_string(string prompt) {
    write(prompt);
    return read_line();
}

int read_integer(string prompt) {
    string line;
    int result;

    line = read_string(prompt);

    while (not is_integer(line)) {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

int read_integer(string prompt, int min, int max) {
    int result;
    result = read_integer(prompt);

    while (result < min or result > max) {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max) + ": ");
        result = read_integer(prompt);
    }
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

// Create a new read_double_range function to read a number between minimum and maximum (inclusive) values. 
double read_double_range(string prompt, double min, double max) {
    double result;
    result = read_double(prompt);

    while (result < min or result > max) {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max) + ": ");
        result = read_double(prompt);
    }
    return result;
}

// Implementation for reading a boolean (yes/no)
bool read_boolean(string prompt) {
    write_line(prompt);
    string response = read_line();
    if (response == "yes" or response == "y") {
        return true;
    } else {
        return false;
    }
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
