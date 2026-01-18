#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

string read_string(string prompt);
int read_integer(string prompt);
int read_integer(string prompt, int min, int max);
double read_double(string prompt);
double read_double_range(string prompt, double min, double max);
bool read_boolean(string prompt);

// Global constant for the Strouhal number
const double STROUHAL_NUMBER = 0.3;

// Function declarations for air speed velocity calculation and custom multiplication
double air_speed(int frequency, double amplitude);
string multiply_and_format(int num1, int num2);

#endif
