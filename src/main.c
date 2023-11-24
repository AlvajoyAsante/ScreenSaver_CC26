/*
 *--------------------------------------
 * Program Name: SCRNSVR
 * Author: ALVJOY123
 * License: BSD-3-Clause license
 * Description: CEMETECH CONTEST 26
 *--------------------------------------
 */

#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <compression.h>
#include <sys/lcd.h>
#include <sys/timers.h>
#include <math.h>
#include <time.h>

#include "main.h"
#include "gfx/gfx.h"

struct SCREEN_SAVER_SETTINGS_t SCREEN_SAVER_SETTINGS;
gfx_sprite_t *temp;

// Util Functions Below
/**
 * Resets the palette to its default state.
 */
static void reset_palette(void)
{
    gfx_SetPalette(palette, sizeof_palette, 0);
}

/**
 * Resets all screensaver settings to their default values.
 */
static void reset_settings(void)
{
    SCREEN_SAVER_SETTINGS.background_dx = DEFAULT_BACKGROUND_DX;
    SCREEN_SAVER_SETTINGS.background_dy = DEFAULT_BACKGROUND_DY;

    SCREEN_SAVER_SETTINGS.background_costnum = 0;
    SCREEN_SAVER_SETTINGS.icon_costnum = 0;
    SCREEN_SAVER_SETTINGS.globe_costnum = 0;

    for (int i = 0; i < 5; i++)
    {
        SCREEN_SAVER_SETTINGS.globe_x[i] = (GFX_LCD_WIDTH - GLOBE10_width) / 2;
        SCREEN_SAVER_SETTINGS.globe_y[i] = (GFX_LCD_HEIGHT - GLOBE10_height) / 2;

        SCREEN_SAVER_SETTINGS.globe_x_vel[i] = randInt(3, 5);
        if (randInt(0, 1))
            SCREEN_SAVER_SETTINGS.globe_x_vel[i] *= -1;
        SCREEN_SAVER_SETTINGS.globe_y_vel[i] = randInt(3, 5);
        if (randInt(0, 1))
            SCREEN_SAVER_SETTINGS.globe_y_vel[i] *= -1;
    }

    SCREEN_SAVER_SETTINGS.tick = 0;
}

/**
 * Gradually fades out the palette.
 * Credit: https://github.com/merthsoft/blockdudece/blob/c650916f5bb048840e8b9b65d85467489664ef5e/src/effects.h#L6
 *
 * @param basePalette The base palette to fade from.
 * @param start The starting index of the palette to fade.
 * @param length The length of the palette to fade.
 */
static void fade_out(uint16_t *base_palette, uint8_t start, uint8_t length)
{
    for (int step = 255; step >= 0; step--)
    {
        for (int i = start; i < start + length; i++)
            gfx_palette[i] = gfx_Darken(base_palette[i], step);
    }
}

/**
 * Prints a string centered on the screen.
 *
 * @param str The string to print.
 */
static void PrintCentered(const char *str)
{
    gfx_PrintStringXY(str,
                      (GFX_LCD_WIDTH - gfx_GetStringWidth(str)) / 2,
                      (GFX_LCD_HEIGHT - 8) / 2);
}

/**
 * Prints a string centered on the screen vertically, at a specified y-coordinate.
 *
 * @param str The string to print.
 * @param y The y-coordinate to print the string at.
 */
static void PrintCentered_Y(const char *str, int y)
{
    gfx_PrintStringXY(str,
                      (GFX_LCD_WIDTH - gfx_GetStringWidth(str)) / 2,
                      y);
}

// Update, Render, Initialization Below
/**
 * Initializes the screensaver by allocating necessary resources and setting up initial values.
 */
static void screensaver_Initialize(void)
{
    temp = gfx_MallocSprite(ICON_BALL_1_width, ICON_BALL_1_height);

    reset_settings();

    SCREEN_SAVER_SETTINGS.curr_screen = 1;
    SCREEN_SAVER_SETTINGS.prev_screen = 1;
}

/**
 * Renders the current screensaver screen based on the current screen state.
 */
static void screensaver_Render(void)
{
    switch (SCREEN_SAVER_SETTINGS.curr_screen)
    {
    case 1:
        /* Print the message on the screen */
        for (int i = 0; i < 5; i++)
        {
            gfx_TransparentSprite_NoClip(CEMETECH_LOGO, SCREEN_SAVER_SETTINGS.globe_x[i], SCREEN_SAVER_SETTINGS.globe_y[i]);
        }

        gfx_SetTextScale(2, 2);
        PrintCentered("CEMETECH CONTEST 26");

        gfx_SetTextScale(1, 1);
        if (randInt(0, 2))
            PrintCentered_Y("Press Any Key to Exit", 220);
        
        PrintCentered_Y("Developed by Alvajoy123", 230);
        break;

    case 2:
        /* Bouncing Globe */
        zx7_Decompress(temp, CEMETECH_GLOBE[SCREEN_SAVER_SETTINGS.globe_costnum]);

        if (SCREEN_SAVER_SETTINGS.globe_type)
        {
            for (int i = 0; i < 5; i++)
            {
                gfx_TransparentSprite_NoClip(temp, SCREEN_SAVER_SETTINGS.globe_x[i], SCREEN_SAVER_SETTINGS.globe_y[i]);
            }
        }
        else
        {
            gfx_ScaledTransparentSprite_NoClip(temp, SCREEN_SAVER_SETTINGS.globe_x[0], SCREEN_SAVER_SETTINGS.globe_y[0], 2, 2);
        }

        break;

    case 3:
        // Cemetech Logo
        for (int k = 0; k < 15; k++)
        {
            gfx_SetColor(150);
            gfx_TransparentSprite_NoClip(CEMETECH_LOGO, SCREEN_SAVER_SETTINGS.background_dx - 17, k * 16);
            gfx_TransparentSprite_NoClip(CEMETECH_LOGO, SCREEN_SAVER_SETTINGS.background_dx + 288, k * 16);
        }

        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                SCREEN_SAVER_SETTINGS.icon_costnum = row * 3 + col;

                if (SCREEN_SAVER_SETTINGS.background_costnum < 4)
                {
                    zx7_Decompress(temp, icons[SCREEN_SAVER_SETTINGS.icon_costnum][SCREEN_SAVER_SETTINGS.background_costnum]);
                }

                int x = SCREEN_SAVER_SETTINGS.background_dx + col * (ICON_BALL_1_width + 2);
                int y = SCREEN_SAVER_SETTINGS.background_dy + row * (ICON_BALL_1_height + 1);
                gfx_TransparentSprite_NoClip(temp, x, y);
            }
        }
        break;

    case 4:
        if (SCREEN_SAVER_SETTINGS.background_costnum < 4)
        {
            zx7_Decompress(temp, icons[SCREEN_SAVER_SETTINGS.icon_costnum][SCREEN_SAVER_SETTINGS.background_costnum]);
        }

        if (SCREEN_SAVER_SETTINGS.icon_type)
        {
            // Still Ball
            int x = (GFX_LCD_WIDTH - ICON_BALL_1_width * 2) / 2;
            int y = (GFX_LCD_HEIGHT - ICON_BALL_1_height * 2) / 2;

            gfx_ScaledTransparentSprite_NoClip(temp, x, y, 2, 2);
        }
        else
        {
            // Randowmly Ball
            gfx_TransparentSprite_NoClip(temp, SCREEN_SAVER_SETTINGS.globe_x[0], SCREEN_SAVER_SETTINGS.globe_y[0]);
        }

        break;

    default:
        fade_out(gfx_palette, 1, 255);
        gfx_FillScreen(0);
        gfx_BlitBuffer();
        reset_palette();

        // Needed yo put this here :(
        SCREEN_SAVER_SETTINGS.curr_screen += 1;
        break;
    }

    gfx_BlitBuffer();

    gfx_FillScreen(0);
}

/**
 * Updates the screensaver's current state and renders the appropriate screen.
 */
static void screensaver_Update(void)
{
    // current screen ticker

    if (SCREEN_SAVER_SETTINGS.curr_screen < 5)
    {
        SCREEN_SAVER_SETTINGS.screen_tick++;

        if (SCREEN_SAVER_SETTINGS.screen_tick > screen_times[SCREEN_SAVER_SETTINGS.curr_screen - 1])
        {
            SCREEN_SAVER_SETTINGS.curr_screen = 5;
            SCREEN_SAVER_SETTINGS.screen_tick = 0;
        }
    }
    else
    {
        SCREEN_SAVER_SETTINGS.screen_tick = 0;
    }

    switch (SCREEN_SAVER_SETTINGS.curr_screen)
    {
    case 1: // Title
        for (int i = 0; i < 5; i++)
        {
            SCREEN_SAVER_SETTINGS.globe_x[i] += SCREEN_SAVER_SETTINGS.globe_x_vel[i];
            SCREEN_SAVER_SETTINGS.globe_y[i] += SCREEN_SAVER_SETTINGS.globe_y_vel[i];

            // Apply a gravitational force towards the center of the screen
            int centerX = GFX_LCD_WIDTH / 2;
            int centerY = GFX_LCD_HEIGHT / 2;

            int dx = abs(centerX - SCREEN_SAVER_SETTINGS.globe_x[i]);
            int dy = abs(centerY - SCREEN_SAVER_SETTINGS.globe_y[i]);

            int distance = sqrt(dx * dx + dy * dy);

            float forceX = -dx * 0.1 / distance;
            float forceY = -dy * 0.1 / distance;

            // Check if the new velocity would cause the globe to move out of bounds
            if (SCREEN_SAVER_SETTINGS.globe_x[i] < 0 ||
                SCREEN_SAVER_SETTINGS.globe_x[i] > GFX_LCD_WIDTH)
            {
                // Reverse the velocity if it would cause the globe to move out of bounds
                SCREEN_SAVER_SETTINGS.globe_x[i] = 0;
                SCREEN_SAVER_SETTINGS.globe_x_vel[i] *= -1;
            }

            // Check if the new velocity would cause the globe to move out of bounds
            if (SCREEN_SAVER_SETTINGS.globe_y[i] < 0 ||
                SCREEN_SAVER_SETTINGS.globe_y[i] > GFX_LCD_HEIGHT)
            {
                // Reverse the velocity if it would cause the globe to move out of bounds
                SCREEN_SAVER_SETTINGS.globe_y[i] = 0;
                SCREEN_SAVER_SETTINGS.globe_y_vel[i] *= -1;
            }

            SCREEN_SAVER_SETTINGS.globe_x_vel[i] += (int)forceX;
            SCREEN_SAVER_SETTINGS.globe_y_vel[i] += (int)forceY;
        }
        break;

    case 2: // Moving Globe

        if (SCREEN_SAVER_SETTINGS.globe_type)
        {
            for (int i = 0; i < 5; i++)
            {
                // Update globe position
                SCREEN_SAVER_SETTINGS.globe_x[i] += SCREEN_SAVER_SETTINGS.globe_x_vel[i];
                SCREEN_SAVER_SETTINGS.globe_y[i] += SCREEN_SAVER_SETTINGS.globe_y_vel[i];

                // Check for and handle out-of-bounds conditions
                if (SCREEN_SAVER_SETTINGS.globe_x[i] < 1)
                {
                    SCREEN_SAVER_SETTINGS.globe_x[i] = 1;
                    SCREEN_SAVER_SETTINGS.globe_x_vel[i] *= -1;
                }
                else if (SCREEN_SAVER_SETTINGS.globe_x[i] + GLOBE10_width > GFX_LCD_WIDTH)
                {
                    SCREEN_SAVER_SETTINGS.globe_x[i] = GFX_LCD_WIDTH - GLOBE10_width;
                    SCREEN_SAVER_SETTINGS.globe_x_vel[i] *= -1;
                }

                if (SCREEN_SAVER_SETTINGS.globe_y[i] < 1)
                {
                    SCREEN_SAVER_SETTINGS.globe_y[i] = 1;
                    SCREEN_SAVER_SETTINGS.globe_y_vel[i] *= -1;
                }
                else if (SCREEN_SAVER_SETTINGS.globe_y[i] + GLOBE10_height > GFX_LCD_HEIGHT)
                {
                    SCREEN_SAVER_SETTINGS.globe_y[i] = GFX_LCD_HEIGHT - GLOBE10_height;
                    SCREEN_SAVER_SETTINGS.globe_y_vel[i] *= -1;
                }
            }
        }
        else
        {
            // Update globe position
            SCREEN_SAVER_SETTINGS.globe_x[0] += SCREEN_SAVER_SETTINGS.globe_x_vel[0];
            SCREEN_SAVER_SETTINGS.globe_y[0] += SCREEN_SAVER_SETTINGS.globe_y_vel[0];

            // Check for and handle out-of-bounds conditions
            if (SCREEN_SAVER_SETTINGS.globe_x[0] < 1)
            {
                SCREEN_SAVER_SETTINGS.globe_x[0] = 1;
                SCREEN_SAVER_SETTINGS.globe_x_vel[0] *= -1;
            }
            else if (SCREEN_SAVER_SETTINGS.globe_x[0] + GLOBE10_width * 2 > GFX_LCD_WIDTH)
            {
                SCREEN_SAVER_SETTINGS.globe_x[0] = GFX_LCD_WIDTH - GLOBE10_width * 2;
                SCREEN_SAVER_SETTINGS.globe_x_vel[0] *= -1;
            }

            if (SCREEN_SAVER_SETTINGS.globe_y[0] < 1)
            {
                SCREEN_SAVER_SETTINGS.globe_y[0] = 1;
                SCREEN_SAVER_SETTINGS.globe_y_vel[0] *= -1;
            }
            else if (SCREEN_SAVER_SETTINGS.globe_y[0] + GLOBE10_height * 2 > GFX_LCD_HEIGHT)
            {
                SCREEN_SAVER_SETTINGS.globe_y[0] = GFX_LCD_HEIGHT - GLOBE10_height * 2;
                SCREEN_SAVER_SETTINGS.globe_y_vel[0] *= -1;
            }
        }

        // Update Globe costume
        if (SCREEN_SAVER_SETTINGS.tick >= 2)
        {
            SCREEN_SAVER_SETTINGS.globe_costnum++;

            if (SCREEN_SAVER_SETTINGS.globe_costnum >= 11)
                SCREEN_SAVER_SETTINGS.globe_costnum = 0;
        }
        else
        {
            SCREEN_SAVER_SETTINGS.tick++;
        }

        break;

    case 3: // Tele backgrounds
            // Update position
        if (SCREEN_SAVER_SETTINGS.background_dx < 320)
        {
            SCREEN_SAVER_SETTINGS.background_dx += 5;
        }
        else
        {
            SCREEN_SAVER_SETTINGS.background_dx = DEFAULT_BACKGROUND_DX;
        }

        // Costume Ticker
        if (SCREEN_SAVER_SETTINGS.tick >= 1)
        {
            // Update background costume
            SCREEN_SAVER_SETTINGS.background_costnum++;

            if (SCREEN_SAVER_SETTINGS.background_costnum >= 4)
            {
                SCREEN_SAVER_SETTINGS.background_costnum = 0;
            }

            // Rest Ticker
            SCREEN_SAVER_SETTINGS.tick = 0;
        }
        else
        {
            SCREEN_SAVER_SETTINGS.tick++;
        }

        SCREEN_SAVER_SETTINGS.background_dy = DEFAULT_BACKGROUND_DY;
        break;

    case 4: // Solo backgrounds
        // Costume Ticker
        if (!SCREEN_SAVER_SETTINGS.icon_type)
        {
            // Move randomly
            // Update globe position
            SCREEN_SAVER_SETTINGS.globe_x[0] += SCREEN_SAVER_SETTINGS.globe_x_vel[0];
            SCREEN_SAVER_SETTINGS.globe_y[0] += SCREEN_SAVER_SETTINGS.globe_y_vel[0];

            // Check for and handle out-of-bounds conditions
            if (SCREEN_SAVER_SETTINGS.globe_x[0] < 1)
            {
                SCREEN_SAVER_SETTINGS.globe_x[0] = 1;
                SCREEN_SAVER_SETTINGS.globe_x_vel[0] *= -1;
            }
            else if (SCREEN_SAVER_SETTINGS.globe_x[0] + ICON_BALL_1_width > GFX_LCD_WIDTH)
            {
                SCREEN_SAVER_SETTINGS.globe_x[0] = GFX_LCD_WIDTH - ICON_BALL_1_width;
                SCREEN_SAVER_SETTINGS.globe_x_vel[0] *= -1;
            }

            if (SCREEN_SAVER_SETTINGS.globe_y[0] < 1)
            {
                SCREEN_SAVER_SETTINGS.globe_y[0] = 1;
                SCREEN_SAVER_SETTINGS.globe_y_vel[0] *= -1;
            }
            else if (SCREEN_SAVER_SETTINGS.globe_y[0] + ICON_BALL_1_height > GFX_LCD_HEIGHT)
            {
                SCREEN_SAVER_SETTINGS.globe_y[0] = GFX_LCD_HEIGHT - ICON_BALL_1_height;
                SCREEN_SAVER_SETTINGS.globe_y_vel[0] *= -1;
            }
        }

        if (SCREEN_SAVER_SETTINGS.tick >= 3)
        {
            // Update background costume
            SCREEN_SAVER_SETTINGS.background_costnum++;

            if (SCREEN_SAVER_SETTINGS.background_costnum >= 4)
            {
                SCREEN_SAVER_SETTINGS.background_costnum = 0;
            }

            // Rest Ticker
            SCREEN_SAVER_SETTINGS.tick = 0;
        }
        else
        {
            SCREEN_SAVER_SETTINGS.tick++;
        }
        break;

    default:
        if (SCREEN_SAVER_SETTINGS.curr_screen > 5)
        {
            reset_settings();

            SCREEN_SAVER_SETTINGS.curr_screen = ++SCREEN_SAVER_SETTINGS.prev_screen;

            if (SCREEN_SAVER_SETTINGS.curr_screen == 2)
            {
                SCREEN_SAVER_SETTINGS.globe_type = randInt(0, 1);
            }
            else if (SCREEN_SAVER_SETTINGS.curr_screen == 4)
            {
                SCREEN_SAVER_SETTINGS.icon_costnum = randInt(0, 8);
                SCREEN_SAVER_SETTINGS.icon_type = randInt(0, 1);
            }

            if (SCREEN_SAVER_SETTINGS.curr_screen > 4)
            {
                SCREEN_SAVER_SETTINGS.curr_screen = 2;
                SCREEN_SAVER_SETTINGS.prev_screen = 2;
            }
        }
        SCREEN_SAVER_SETTINGS.screen_tick = 0;
        break;
    }
}

int main(void)
{
    uint8_t level = lcd_BacklightLevel;

    // Randomize System
    srand(time(NULL));

    // Backlight Init
    boot_WaitShort();
    lcd_BacklightLevel = 215;

    // Setting Init
    screensaver_Initialize();

    gfx_Begin();

    // Palette Jumbo
    gfx_SetPalette(palette, sizeof_palette, 0);
    gfx_SetTransparentColor(1);

    // Buffering
    gfx_SetDrawBuffer();
    gfx_FillScreen(0);
    gfx_BlitBuffer();

    // Text Colors
    gfx_SetTextTransparentColor(0);
    gfx_SetTextFGColor(255);
    gfx_SetTextBGColor(0);

    // Main loop
    do
    {
        screensaver_Render();
        screensaver_Update();
    } while (!os_GetCSC());

    // Free Temp Sprite for decompression
    free(temp);

    gfx_End();

    // Restore Backlight Level
    boot_WaitShort();
    lcd_BacklightLevel = level;

    return 1;
}