#include "splashkit.h"

void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    // Draw the ground
    fill_circle(COLOR_GREEN, 400, 600, 200);
    // Draw the house body
    fill_rectangle(COLOR_GRAY, 350, 400, 100, 150);
    // Draw the roof
    fill_triangle(COLOR_RED, 300, 400, 500, 400, 400, 300);
    refresh_screen();
}

// my custom scene
void draw_custom_scene()
{
    clear_screen(COLOR_WHITE);
    // Example of custom scene: A tree with a sun
    fill_circle(COLOR_YELLOW, 700, 100, 50); // Sun
    fill_rectangle(COLOR_BROWN, 100, 450, 50, 150); // Tree trunk
    fill_circle(COLOR_GREEN, 125, 400, 75); // Tree leaves
    refresh_screen();
}

int main()
{
    open_window("Shape Drawing", 800, 600);

    // First scene: house
    draw_house_scene();
    delay(1000);

    // Clear screen and draw custom scene
    draw_custom_scene();
    delay(1000);

    // Draw house again
    draw_house_scene();
    delay(1000);

    // Draw custom scene again
    draw_custom_scene();
    delay(1000);

    return 0;
}
