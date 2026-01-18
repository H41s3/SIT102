#include "splashkit.h"

void load_resources()
{
    // Load bitmaps
    load_bitmap("background", "background.png");
    load_bitmap("sprite1", "sprite1.png");
    load_bitmap("sprite2", "sprite2.png");

    // Load sound effects
    load_sound_effect("effect1", "effect1.wav");
    load_sound_effect("effect2", "effect2.wav");
}

void draw_scene( string sprite,  string sound_effect)
{
    // Clear the screen with a white background
    clear_screen(COLOR_WHITE);

    // Draw the background
    draw_bitmap("background", 0, 0);

    // Draw the sprite in the center of the screen
    draw_bitmap(sprite, (screen_width() - bitmap_width(sprite)) / 2, (screen_height() - bitmap_height(sprite)) / 2);

    // Play the sound effect
    play_sound_effect(sound_effect);

    // Refresh the screen to show the drawn content
    refresh_screen();
}

int main()
{
    // Open a new window
    open_window("Make Scene", 900, 700);

    // Load resources
    load_resources();

    // Draw the first scene with the first sound effect
    draw_scene("sprite1", "effect1");
    delay(3000); // Delay for 3 seconds

    // Draw the second scene with the second sound effect
    draw_scene("sprite2", "effect2");
    delay(3000); // Delay for 3 seconds

    // Close window after animation
    // 10 seconds before closing
    delay(10000);
    return 0;
}
