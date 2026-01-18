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
