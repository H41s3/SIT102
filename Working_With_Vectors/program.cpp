#include "splashkit.h"
#include <vector>
using std::vector;
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
int total_length(const vector<string>& names) {
    int result = 0;

    for (int v = 0; v < names.size(); v++) { // Loop through the vector and calculate total length
        string name = names[v];
        result += name.length();
    }

    return result;
}

// Function to find the shortest name
string shortest_name(const vector<string>& names) {
    string min = names[0]; // Initialize min with the first name in the vector

    for (int v = 1; v < names.size(); v++) {
        if (min.length() > names[v].length()) {
            min = names[v];
        }
    }

    return min;
}

// Function to find the index of a name
int index_of(const string& value, const vector<string>& names) {
    for (int v = 0; v < names.size(); v++) {
        if (to_lowercase(names[v]) == to_lowercase(value)) {
            return v;
        }
    }
    return -1; // Return -1 if not found
}

// Procedure to print summary of names and their lengths
void print_summary(const vector<string>& names) {
    write_line("Summary of Names and Lengths:");

    for (int v = 0; v < names.size(); v++) {
        string name = names[v];
        write_line(name + ": " + to_string(name.length()) + " characters");
    }

    int total = total_length(names);
    write("Total length of all names: ");
    write_line(total);

    // Print the shortest name
    string short_name = shortest_name(names);
    write_line("Shortest name: " + short_name);

    // Print the index of "Emilio" if present
    int index = index_of("Emilio", names);
    if (index == -1) {
        write_line("\"Emilio\" is found at index: " + to_string(index));
    } else {
        write_line("\"Emilio\" is found at index: " + to_string(index));
    }
}

int main() {
    vector<string> names;

    names.push_back(read_string("Enter a name: "));
    names.push_back(read_string("Enter a name: "));
    names.push_back(read_string("Enter a name: "));

    for (int v = 0; v < names.size(); v++) {
        write_line(names[v]);
    }

    // Print all names and their lengths along with the summary
    print_summary(names);

    return 0;
}
