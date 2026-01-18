#include "splashkit.h"

/*
    FUNCTION: read_string
    INPUTS: message prompt to display to screen (as string)
    OUTPUT: user input from keyboard (as string)
*/
string read_string(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}


/*
    FUNCTION: read_integer
    INPUTS: message prompt to display to screen (as string)
    OUTPUT: user input from keyboard (as integer)
    NOTE: this function calls the read_string function to get user input, which is then converted to an integer
*/
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}


/*
    FUNCTION: main
    OUTPUT: error code for operating system (0 = program execution successful)
    NOTE: program begins in this function. As program executes, main calls the above procedures and functions
*/
int main()
{
    // declare our variables
    string name;
    int age;

    // assign values to our variables
    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    // use our variables
    write_line(name);
    write("Age: ");
    write_line(age);

    return 0;
}