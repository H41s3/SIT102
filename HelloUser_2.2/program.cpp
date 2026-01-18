#include "splashkit.h"
using namespace std;

// Global constant for the Strouhal number
const double STROUHAL_NUMBER = 0.3;

// method to read a string from the user
string read_string(string prompt) {
    write(prompt);
    return read_line();
}

// method to read an integer from the user
int read_integer(string prompt) {
    write(prompt);
    return convert_to_integer(read_line());
}

// method to read a double from the user
double read_double(string prompt) {
    write(prompt);
    return convert_to_double(read_line());
}

// method to calculate air speed velocity
double air_speed(int frequency, double amplitude) {
    return frequency * amplitude * STROUHAL_NUMBER;
}

// custom method to multiply two numbers and return a formatted string
string multiply_and_format(int num1, int num2) {
    int result = num1 * num2;
    return "The multiplication of " + to_string(num1) + " and " + to_string(num2) + " is " + to_string(result);
}

int main() {
    string name = read_string("Enter your name: ");
    int age = read_integer("Enter your age: ");

    write_line("Welcome, " + name + "! You are " + to_string(age) + " years old.");

    // To calculate the air speed velocity for African Swallow
    double african_swallow_speed = air_speed(15, 21.0);
    write_line("African Swallow air speed velocity: " + to_string(african_swallow_speed) + " m/s");

    // To calculate the air speed velocity for European Swallow
    double european_swallow_speed = air_speed(14, 22.0);
    write_line("European Swallow air speed velocity: " + to_string(european_swallow_speed) + " m/s");

    // Example of custom bird
    double custom_bird_speed = air_speed(12, 25.0);
    write_line("Custom Bird air speed velocity: " + to_string(custom_bird_speed) + " m/s");

    // Use the custom multiplication function
    string multiplication_result = multiply_and_format(7, 8);
    write_line(multiplication_result);

    return 0;
}
