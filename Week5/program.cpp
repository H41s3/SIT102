#include "splashkit.h"

string read_string(string prompt)
{
    string input;
    write(prompt);
    input = read_line();
    return input;
}

int main()
{
    string name;
    string correct_name = "Emilio";

    // Loop until the correct name is entered
    while (true)
    {
        name = read_string("What is your name: ");
        if (name == correct_name)
        {
            break;
        }
        else
        {
            write_line("Incorrect name, please try again.");
        }
    }

    write_line("Nice to meet you!");

    return 0;
}











/*
// Selection statement

#include "splashkit.h"
#include <sstream>

string read_string(string prompt)
{
    string input;
    write(prompt);
    input = read_line();
    return input;
}

int read_integer(string prompt)
{
    int input;
    write(prompt);
    input = convert_to_integer(read_line());
    return input;
}

string to_string(int number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

int main()
{
    string name = read_string("Enter your name: ");
    int age = read_integer("Enter your age: ");

    write_line("Welcome, " + name + "! You are " + to_string(age) + " years old.");

    return 0;
}

*/



















/*
#include "splashkit.h"

// Iterative loop to print numbers from 1 to 10
int main()
{
    int num = 1;

    while (num <= 10)
    {
        write_line(num);
        num += 1;
    }
    write("The final value is: ");
    write_line(num );
    return 0;
}
*/


/*
// While Loop

#include "splashkit.h"

int main()
{
    string input;
    double value;
    double average = 0;
    double sum = 0;
    int count = 1;      // we will use this variable to keep track of how many times we loop

    write_line("This program will get a set of five numbers from the user and calculate the average.");
    write_line();

    while ( count <= 5 )
    {
        write("Please enter a number: ");
        input = read_line();
        value = convert_to_double( input );

        sum = sum + value;      // add the new number to the sum
        average = sum / count;  // get the new average

        count = count + 1;      // increase count in the loop, otherwise we will be stuck!
    }

    // output the average here
    write("The average of your numbers is: ");
    write_line(average);

    return 0;
}
*/








/*
// Do while loop
#include "splashkit.h"

int main()
{
    // secret login details
    string username = "admin";
    string password = "ABC123";

    // variables to store user input
    string username_input;
    string password_input;

    // force the login prompt to run at least once
    do
    {
        // get the username and password
        write( "Please enter a username: " );
        username_input = read_line();
        write( "Please enter a password: " );
        password_input = read_line();

    } while ( username_input != username or password_input != password );   // don't forget the semi-colon here!
    
    // if we can get to this code then the loop must end - the only way for that
    // to happen is if both the username and password are correct
    write_line("You made it past the loop! Logging you in now...");
    delay(3000);
    write_line("...just kidding. There's nothing else in this program.");

    return 0;
}
*/



/*
#include "splashkit.h"

int main() {
    string name = "EJ";
    
    string user_input;

    do {
    write("Guess my name: ");
    user_input = read_line();
    } while (user_input != name);

    write_line("Congratulations! You guessed my name correctly.");

    return 0;
}
*/