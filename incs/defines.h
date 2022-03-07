#ifndef DEFINES_H
# define DEFINES_H

# ifdef __linux__
#  define XK_Escape 0xff1b
#  define XK_w 0x0077
#  define XK_a 0x0061
#  define XK_s 0x0073
#  define XK_d 0x0064
#  define XK_Left 0xff51
#  define XK_Right 0xff53
# else
#  define XK_Escape 53
#  define XK_w 13
#  define XK_a 0
#  define XK_s 1
#  define XK_d 2
#  define XK_Left 123
#  define XK_Right 124
# endif

# define ROT_SPEED 0.05
# define MOVE_DIST 0.15

#endif
