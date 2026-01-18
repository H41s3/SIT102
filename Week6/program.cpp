#include "splashkit.h"

struct Student {
    string name;
    int age;
};

enum Directions {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

int main()
{
    Student student;
    student.name = "Vincy";
    student.age = 20;

    write("Student Name: " + student.name + "\n");

    Directions direction;
    direction = NORTH;
    string direction_string;

    write("Direction - ");
    write_line(direction);

    switch(direction) {
        case NORTH:
            write("You are facing North.\n");
            break;
        case SOUTH:
            write("You are facing South.\n");
            break;
        case EAST:
            write("You are facing East.\n");
            break;
        case WEST:
            write("You are facing West.\n");
            break;
        default:
            write("Invalid direction.\n");
    }
    
    return 0;
}