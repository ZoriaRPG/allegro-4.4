/*         ______   ___    ___
 *        /\  _  \ /\_ \  /\_ \
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      3DS specific header defines.
 *
 *      See readme.txt for copyright information.
 */

#ifndef AL3DS_H
#define AL3DS_H

#ifndef ALLEGRO_3DS
   #error bad include
#endif

/* System driver */
#define SYSTEM_3DS   AL_ID('3','D','S',' ')
AL_VAR(SYSTEM_DRIVER, system_3ds);

/* Timer driver */
#define TIMER_3DS    AL_ID('3','D','S','T')
AL_VAR(TIMER_DRIVER, timer_3ds);

/* Keyboard driver */
#define KEYB_3DS     AL_ID('3','D','S','K')
AL_VAR(KEYBOARD_DRIVER, keybd_glue_3ds);

/* Gfx driver */
#define GFX_3DS      AL_ID('3','D','S','G')
AL_VAR(GFX_DRIVER, gfx_3ds);

/* Digital sound driver */
#define DIGI_3DS     AL_ID('3','D','S','S')
AL_VAR(DIGI_DRIVER, digi_3ds);

/* Joystick drivers */
#define JOYSTICK_3DS AL_ID('3','D','S','J')
AL_VAR(JOYSTICK_DRIVER, joystick_3ds);

#endif
