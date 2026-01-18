#include "splashkit.h"
#define RADIUS 50

int main()
{
    double x, y; 
    color circle_color = COLOR_BLACK;

    open_window("Circle Mover by EJ", 800, 600);

    x = screen_width() / 2;
    y = screen_height() / 2;
    
    while (not quit_requested()) {
        process_events();

        // Press the 'C' key to change circle color
        if (key_typed(C_KEY)){
            circle_color = random_color();
        }

        // Move right
        if (key_down(RIGHT_KEY)) {
        x += 3;
        }

        // Move left
        if (key_down(LEFT_KEY)) {
            x -= 3;
        }

        // Prevent circle from leaving the screen (horizontally)
        if (x + RADIUS > screen_width()) {
            x = screen_width() - RADIUS;
        }
        if (x - RADIUS < 0) {
            x = RADIUS;
        }

        // Move up
        if (key_down(UP_KEY)) {
            y -= 3;
        }

        // Move down
        if (key_down(DOWN_KEY)) {
            y +=3;
        }

        // Prevent circle from leaving the screen (vertically)
        if (y + RADIUS > screen_height()) {
            y = screen_height() - RADIUS;
        }
        if (y - RADIUS < 0) {
            y = RADIUS;
        }

        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x, y, RADIUS);
        refresh_screen(60);
    }
    return 0;
}