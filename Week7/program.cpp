/*
#include "splashkit.h"

int main()
{
    // data type identifiers
    int num1, num2, num3, num4, num5;
    num1 = 10;
    num2 = 20;
    num3, num4 = 30, 40;
    //array
    //data type identifier[SIZE OF ARRAY]

    //2 ways to assign values to an array
    //method 1
    int numbers[5] = {10, 20, 30, 40, 50};

    // method 2
    int numbers[5];
    numbers[0] = 1;
    numbers[3] = 3;
    numbers[5] = 5; // index out of bounds error

    // Task 1
    string friends[3] = {"Midoriya", "Sanemi", "Giyu", "Satoru", "Rin"};
    friends[3] = "Satoru";
    return 0;
}
*/


/*

//Task 1
// Create an array called friends and store the names of five friends in the array. Print the 4th element
#include "splashkit.h"
using namespace std;

struct Students {
    string name;
    int age;
};

int main() {
    // data type identifiers
    string friends[5] = {"Midoriya", "Sanemi", "Giyu", "Satoru", "Rin"};
    write_line(friends[3]);

    //Task2
    // Create an array called math_nums and store 3 values. Print all of the values
    float math_nums[3] = {3.14, 9.81, 2};
    for (int i = 0; i < 3; i++) {
        write_line(to_string(math_nums[i]));
    }

    //Task 3
    // Create a structure called Students and store 2 student values
    Students student;
    student.name = "Vincy";
    student.age = 20;
    write_line("Student Name: " + student.name);

    Students group[10];
    for (int i = 0; i < 10; i++) {
        string name = read_line("Enter student name: ");
        int age = read_integer("Enter student age: ");
        Students new_student;
        new_student.name = name;
        new_student.age = age;
        group[i] = new_student;
    }
    return 0;
}


*/

/*
// Vectors and arrays
#include "splashkit.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    int marks[5] = {25, 50, 55, 80, 100};  // Declare and initialize the array correctly
    write_line(to_string(marks[4]));  // Print the 5th mark (index 4)

    for (int i = 0; i < 5; i++) {
        write_line("Mark " + to_string(i + 1) + ": " + to_string(marks[i]));  // Print each mark with index
    }

    // Example of further continuation
    // Assuming you want to collect student names and their IDs
    
    vector<string> student_names(5);
    vector<int> student_ids(5);

    for (int i = 0; i < 5; i++) {
        write("Enter student name: ");
        student_names[i] = read_line();  // Get the student's name

        write("Enter student ID: ");
        student_ids[i] = convert_to_integer(read_line());  // Get the student's ID
    }

    // Print the collected data
    for (int i = 0; i < 5; i++) {
        write_line("Student " + to_string(i + 1) + ": " + student_names[i] + " with ID: " + to_string(student_ids[i]));
    }

    return 0;
}

*/

// Create a vector called names and ask the user to enter the names and store itin the vector. Do it until the user enters "X".
#include "splashkit.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> names;
    string user_input;

    while (user_input != "X") {
        write("Enter a name (or X to exit): ");
        user_input = read_line(); // read_line() used to read a line of input from the user. The input is then stored in the user_input variable.
        if (user_input != "X") {
            names.push_back(user_input);  // Add the name to the vector
        }
    }

    // Print all the names entered by the user
    write_line("Names entered:");
    for (string name : names) {
        write_line(name);
    }

    // extend, delete all of those elements using a for loop
    do {
        names.pop_back();  // Remove the last element from the vector
    }
    


    return 0;
}