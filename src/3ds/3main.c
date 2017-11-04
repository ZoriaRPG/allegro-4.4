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
 *      Replacement for the Allegro program main() function to execute
 *      the 3DS stuff.
 *
 *      See readme.txt for copyright information.
 */

#include <3ds.h>

extern void *_mangled_main_address;

/* main:
 *  Replacement for main function.
 */
int main(int argc, char *argv[])
{
   int (*real_main) (int, char *[]) = (int (*) (int, char *[])) _mangled_main_address;

   return (*real_main)(argc, argv);
}
