#ifndef MAIN_H
#define MAIN_H

/**
 * Default speed/starting position for the background animation.
 */
#define DEFAULT_BACKGROUND_DX 17

/**
 * Default speed/starting position for the background animation.
 */
#define DEFAULT_BACKGROUND_DY 0

#include <tice.h>
#include <graphx.h>
#include "gfx/gfx.h"

// Arrays containing the compressed image data for all animation frames.
unsigned char *ICON_BALL[4] = {ICON_BALL_1_compressed, ICON_BALL_2_compressed, ICON_BALL_3_compressed, ICON_BALL_4_compressed};
unsigned char *ICON_BLOCKGUY[4] = {ICON_BLOCKGUY_1_compressed, ICON_BLOCKGUY_2_compressed, ICON_BLOCKGUY_3_compressed, ICON_BLOCKGUY_4_compressed};
unsigned char *ICON_BLOCK[4] = {ICON_BLOCK_1_compressed, ICON_BLOCK_2_compressed, ICON_BLOCK_3_compressed, ICON_BLOCK_4_compressed};
unsigned char *ICON_BOUNCE[4] = {ICON_BOUNCE_1_compressed, ICON_BOUNCE_2_compressed, ICON_BOUNCE_3_compressed, ICON_BOUNCE_4_compressed};
unsigned char *ICON_CALCZAP[4] = {ICON_CALCZAP_1_compressed, ICON_CALCZAP_2_compressed, ICON_CALCZAP_3_compressed, ICON_CALCZAP_4_compressed};
unsigned char *ICON_DKONG[4] = {ICON_DKONG_1_compressed, ICON_DKONG_2_compressed, ICON_DKONG_3_compressed, ICON_DKONG_4_compressed};
unsigned char *ICON_FLAPPYBIRD[4] = {ICON_FLAPPYBIRD_1_compressed, ICON_FLAPPYBIRD_2_compressed, ICON_FLAPPYBIRD_3_compressed, ICON_FLAPPYBIRD_4_compressed};
unsigned char *ICON_MARIO[4] = {ICON_MARIO_1_compressed, ICON_MARIO_2_compressed, ICON_MARIO_3_compressed, ICON_MARIO_4_compressed};
unsigned char *ICON_PORTAL[4] = {ICON_PORTAL_1_compressed, ICON_PORTAL_2_compressed, ICON_PORTAL_3_compressed, ICON_PORTAL_4_compressed};

/**
 * An array of icon images used for the screensaver.
 */
unsigned char **icons[] = {
    ICON_BALL,
    ICON_BLOCKGUY,
    ICON_BLOCK,
    ICON_BOUNCE,
    ICON_CALCZAP,
    ICON_DKONG,
    ICON_FLAPPYBIRD,
    ICON_MARIO,
    ICON_PORTAL,
};

/**
 * Array containing the compressed image data for all animation frames of the globe.
 */
unsigned char *CEMETECH_GLOBE[11] = {GLOBE1_compressed, GLOBE2_compressed, GLOBE3_compressed, GLOBE4_compressed, GLOBE5_compressed, GLOBE6_compressed, GLOBE7_compressed, GLOBE8_compressed, GLOBE9_compressed, GLOBE10_compressed,
                                     GLOBE11_compressed};

/**
 * An array of time values representing the duration of each screen.
 * Index 0: Title screen
 * Index 1: Globe screen
 * Index 2: Icon animation screen
 * Index 3: Fade-out screen
 */
uint8_t screen_times[4] = {100, 200, 215, 200};

/**
 * A structure containing various settings for the screensaver.
 */
struct SCREEN_SAVER_SETTINGS_t
{
    int background_dx;
    int background_dy;

    uint8_t background_costnum;
    uint8_t icon_costnum;
    uint8_t globe_costnum;

    uint8_t icon_type;
    uint8_t globe_type;

    int globe_x[5];
    int globe_y[5];
    int globe_x_vel[5];
    int globe_y_vel[5];

    uint8_t tick;
    uint8_t screen_tick;

    uint8_t curr_screen;
    uint8_t prev_screen;
};
extern struct SCREEN_SAVER_SETTINGS_t SCREEN_SAVER_SETTINGS;

#endif /* _SERIAL_H_ */