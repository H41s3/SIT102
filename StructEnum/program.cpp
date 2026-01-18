#include "splashkit.h"
#include <string>
using namespace std;

struct knight_data {
    string name;
    int age;
    string quest; // use enum
    string weapon; // enum
};

string read_string(string prompt) {
    write(prompt);
    return read_line();
}

int read_integer(string prompt) {
    write(prompt);
    return convert_to_integer(read_line());
}

knight_data read_knight() {
    knight_data result;

    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.quest = read_string("Enter quest: ");
    result.weapon = read_string("Enter weapon: ");

    return result;
}

void write_knight(const knight_data &knight) {
    write_line("Hello " + knight.name + ", aged " + to_string(knight.age));
    write_line("Quest: " + knight.quest);
    write_line("Weapon: " + knight.weapon);
}

enum knight_update_option {
    UPDATE_NAME = 1,   // Option for updating name
    UPDATE_AGE,       // Option for updating age
    UPDATE_QUEST,     // Option for updating quest
    UPDATE_WEAPON,    // Option for updating weapon
    FINISH_UPDATE     // Option for finishing update
};

knight_update_option read_knight_update_option() {
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update quest");
    write_line("4: Update weapon");
    write_line("5: Finish update");
    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result);
}

void update_knight(knight_data &knight) {
    knight_update_option option;

    do {
        write_line();
        write_line("== Update Knight ==");
        write_knight(knight);
        write_line();

        option = read_knight_update_option();

        switch (option) {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name: ");
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter new age: ");
                break;
            case UPDATE_QUEST:
                knight.quest = read_string("Enter new quest: ");
                break;
            case UPDATE_WEAPON:
                knight.weapon = read_string("Enter new weapon: ");
                break;
            case FINISH_UPDATE:
                break;
            default:
                write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
}

int main()
{
    knight_data my_knight;

    my_knight = read_knight();
    write_knight(my_knight);

    update_knight(my_knight);
    write_line("Updated knight!");
    write_knight(my_knight);
    
    return 0;
}
