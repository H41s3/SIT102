#include "splashkit.h"
using namespace std;

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

// Function to calculate total length of all names
int total_length(string names[], int size) {
    int result = 0;

    for(int v = 0; v < size; v++) { // Loop through the array and calculate total length
        string name = names[v];
        result += name.length();
    }

    return result;
}

// Function to find the shortest name
string shortest_name(string names[], int size) {
    string min = names[0];

    for(int v = 1; v < size; v++) {
        if(min.length() > names[v].length()) {
            min = names[v];
        }
    }

    return min;
}

// Function to find the index of a name
int index_of(string value, string names[], int size) {
    for(int v = 0; v < size; v++) {
        if(to_lowercase(names[v]) == to_lowercase(value)) {
            return v;
        }
    }
    return -1; // Return -1 if not found
}

// Procedure to print summary of names and their lengths
void print_summary(string names[], int size) {
    write_line("Summary of Names and Lengths:");

    for(int v = 0; v < size; v++) {
        string name = names[v];
        write_line(name + ": " + to_string(name.length()) + " characters");
    }

    int total = total_length(names, size);
    write("Total length of all names: ");
    write_line(total);

    // Print the shortest name
    string short_name = shortest_name(names, size);
    write_line("Shortest name: " + short_name);

    // Print the index of "Emilio" if present
    int index = index_of("Emilio", names, size);
    if(index == -1) {
        write_line("\"Emilio\" is found at index: " + to_string(index)); // (\\ is used when you want to use for example "Emilio" and will output "Emilio" as an output)
    } else {
        write_line("\"Emilio\" is found at index: " + to_string(index));
    }
}

int main() {
    #define SIZE 5 // Define the size of the array (changeable)
    string names[SIZE];
    int v;

    v = 0;
    while(v < SIZE) {
        names[v] = read_string("Enter a name: ");
        v++;
    }

    // Print all names and their lengths along with the summary
    print_summary(names, SIZE);

    return 0;
}
