#include "splashkit.h"
#include <string>
#include <vector>
using std::vector;
using namespace std;

struct knight_data {
    string name;
    int age;
    string quest;
    vector<string> weapons;
};

struct kingdom_data {
    string name;
    vector<knight_data> knights;
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
    
    string weapon = read_string("Enter initial weapon: ");
    result.weapons.push_back(weapon);  // Add the first weapon

    return result;
}

void write_knight(const knight_data &knight) {
    write_line(knight.name + ", aged " + to_string(knight.age));
    write_line("Quest: " + knight.quest);
    write_line("Weapons: ");
    for (string weapon : knight.weapons) {
        write_line("- " + weapon);
    }
}

enum knight_update_option {
    UPDATE_NAME = 1,   // Option for updating name
    UPDATE_AGE,       // Option for updating age
    UPDATE_QUEST,     // Option for updating quest
    ADD_WEAPON,       // Option for adding a weapon
    FINISH_UPDATE     // Option for finishing update
};

knight_update_option read_knight_update_option() {
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update quest");
    write_line("4: Add weapon");
    write_line("5: Finish update");
    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result);
}

// Function to add new weapon to knight
void add_weapon(knight_data &knight) {
    string weapon = read_string("Enter new weapon to add: ");
    knight.weapons.push_back(weapon);
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
            case ADD_WEAPON:
                add_weapon(knight);  // Add a new weapon to the knight
                break;
            case FINISH_UPDATE:
                break;
            default:
                write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
}

void add_knight(kingdom_data &kingdom) {
    knight_data new_knight;
    new_knight = read_knight();

    kingdom.knights.push_back(new_knight);
}

void write_kingdom(const kingdom_data &kingdom) {
    write_line("==================");
    write_line(kingdom.name);
    write_line("==== Knights ====");
    for (int i = 0; i < kingdom.knights.size(); i++) {
        write_knight(kingdom.knights[i]);
    }
    write_line("==================");
}

void delete_knight(kingdom_data &kingdom, int index) {
    if (index >= 0 and index < kingdom.knights.size()) {
        int last_index;
        last_index = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_index];
        kingdom.knights.pop_back();
    }
}

kingdom_data read_kingdom() {
    kingdom_data result;
    result.name = read_string("Enter kingdom name: ");
    return result;
}

// Function to select a knight by index
int select_knight(const kingdom_data &kingdom) {
    int index;

    // Loop until the user selects a valid knight index
    do {
        write_line("Select a knight:");

        // Display the list of knights
        for (int i = 0; i < kingdom.knights.size(); i++) {
            write_line(to_string(i) + ": " + kingdom.knights[i].name);
        }

        index = read_integer("Enter the index of the knight: ");

        if (index < 0 || index >= kingdom.knights.size()) {
            write_line("Invalid index. Please try again.");
        }

    } while (index < 0 || index >= kingdom.knights.size());

    return index;
}

// Main update kingdom function
void update_kingdom(kingdom_data &kingdom) {
    int option;

    do {
        write_line("==== Kingdom Management Menu ====");
        write_line("1: Add knight");
        write_line("2: Delete knight");
        write_line("3: Update knight");
        write_line("4: Display knights");
        write_line("5: Exit");
        option = read_integer("Select an option: ");

        switch (option) {
            case 1:
                add_knight(kingdom);
                break;
            case 2:
                // Select knight to delete
                if (kingdom.knights.size() > 0) {
                    int knight_index = select_knight(kingdom);
                    delete_knight(kingdom, knight_index);
                } else {
                    write_line("No knights to delete.");
                }
                break;
            case 3:
                // Select knight to update
                if (kingdom.knights.size() > 0) {
                    int knight_index = select_knight(kingdom);
                    update_knight(kingdom.knights[knight_index]);
                } else {
                    write_line("No knights to update.");
                }
                break;
            case 4:
                write_kingdom(kingdom);
                break;
            case 5:
                write_line("Exiting kingdom management...");
                break;
            default:
                write_line("Invalid option. Try again.");
        }
    } while (option != 5);
}

int main() {
    kingdom_data my_kingdom = read_kingdom();

    update_kingdom(my_kingdom);  // Manage kingdom

    return 0;
}
