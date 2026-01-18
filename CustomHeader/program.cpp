#include "splashkit.h"
#include "terminal_user_input.h"
using namespace std;

int main() {
    string name = read_string("Enter your name: ");
    int age = read_integer("Enter your age: ");

    write_line("Welcome, " + name + "!");
    write_line("Great you are " + to_string(age) + " years old.");

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
