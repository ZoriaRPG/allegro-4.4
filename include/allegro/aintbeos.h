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
 *      Definitions for internal use by the BeOS configuration.
 *
 *      By Jason Wilkins.
 *
 *      See readme.txt for copyright information.
 */


#ifndef __BEOS__
   #error bad include
#endif

#include "bealleg.h"

#ifdef __cplusplus
extern status_t       ignore_result;

extern volatile int32 focus_count;
#endif

#ifdef __cplusplus
extern "C" {
#endif

int  be_key_init(void);
void be_key_exit(void);
void be_key_set_leds(int leds);
void be_key_wait_for_input(void);
void be_key_stop_waiting_for_input(void);
void be_key_suspend(void);
void be_key_resume(void);

int  be_sys_init(void);
void be_sys_exit(void);
void _be_sys_get_executable_name(char *output, int size);
void be_sys_get_executable_name(char *output, int size);
int be_sys_find_resource(char *dest, AL_CONST char *resource, int size);
void be_sys_set_window_title(AL_CONST char *name);
int be_sys_set_window_close_button(int enable);
void be_sys_set_window_close_hook(void (*proc)(void));
void be_sys_message(AL_CONST char *msg);
int be_sys_desktop_color_depth(void);
void be_sys_yield_timeslice(void);
int be_sys_set_display_switch_mode(int mode);
int be_sys_set_display_switch_cb(int dir, void (*cb)(void));
void be_sys_remove_display_switch_cb(void (*cb)(void));
void be_sys_suspend(void);
void be_sys_resume(void);
void be_main_suspend(void);
void be_main_resume(void);
void be_display_switch_callback(int dir);

struct BITMAP *be_gfx_fullscreen_init(int w, int h, int v_w, int v_h, int color_depth);
struct BITMAP *be_gfx_fullscreen_safe_init(int w, int h, int v_w, int v_h, int color_depth);
void be_gfx_fullscreen_exit(struct BITMAP *b);
void be_gfx_fullscreen_acquire(struct BITMAP *b);
void be_gfx_fullscreen_release(struct BITMAP *b);
void be_gfx_fullscreen_set_palette(AL_CONST struct RGB *p, int from, int to, int vsync);
int  be_gfx_fullscreen_scroll(int x, int y);
void be_gfx_fullscreen_vsync(void);
void be_gfx_fullscreen_accelerate(int color_depth);
#ifdef ALLEGRO_NO_ASM
unsigned long be_gfx_fullscreen_accel_read_write_bank(BITMAP *bmp, int line);
void be_gfx_fullscreen_unwrite_bank(BITMAP *bmp);
unsigned long be_gfx_fullscreen_read_write_bank(BITMAP *bmp, int line);
#else
unsigned long _be_gfx_fullscreen_accel_read_write_bank_asm(BITMAP *bmp, int line);
void _be_gfx_fullscreen_unwrite_bank_asm(BITMAP *bmp);
unsigned long _be_gfx_fullscreen_read_write_bank_asm(BITMAP *bmp, int line);
#endif

struct BITMAP *be_gfx_windowed_init(int w, int h, int v_w, int v_h, int color_depth);
void be_gfx_windowed_exit(struct BITMAP *b);
void be_gfx_windowed_acquire(struct BITMAP *bmp);
void be_gfx_windowed_release(struct BITMAP *bmp);
void be_gfx_windowed_set_palette(AL_CONST struct RGB *p, int from, int to, int vsync);
void be_gfx_windowed_vsync(void);
#ifdef ALLEGRO_NO_ASM
void be_gfx_windowed_unwrite_bank(BITMAP *bmp);
unsigned long be_gfx_windowed_read_write_bank(BITMAP *bmp, int line);
#else
void _be_gfx_windowed_unwrite_bank_asm(BITMAP *bmp);
unsigned long _be_gfx_windowed_read_write_bank_asm(BITMAP *bmp, int line);
#endif

int  be_time_init(void);
void be_time_exit(void);
//int  be_time_can_simulate_retrace(void);
//void be_time_simulate_retrace(int enable);
void be_time_rest(long time, AL_METHOD(void, callback, (void)));
void be_time_suspend(void);
void be_time_resume(void);

int be_mouse_init(void);
void be_mouse_exit(void);
void be_mouse_position(int x, int y);
void be_mouse_set_range(int x1, int y1, int x2, int y2);
void be_mouse_set_speed(int xspeed, int yspeed);
void be_mouse_get_mickeys(int *mickeyx, int *mickeyy);

int be_joy_init(void);
void be_joy_exit(void);
int be_joy_poll(void);

int be_sound_detect(int input);
int be_sound_init(int input, int voices);
void be_sound_exit(int input);
int be_sound_buffer_size();
int be_sound_mixer_volume(int volume);
void be_sound_suspend(void);
void be_sound_resume(void);

int be_midi_detect(int input);
int be_midi_init(int input, int voices);
void be_midi_exit(int input);
int be_midi_mixer_volume(int volume);
void be_midi_key_on(int inst, int note, int bend, int vol, int pan);
void be_midi_key_off(int voice);
void be_midi_set_volume(int voice, int vol);
void be_midi_set_pitch(int voice, int note, int bend);
void be_midi_set_pan(int voice, int pan);

#ifdef __cplusplus
}
#endif
