/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:29:37 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/03 05:21:55 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SPD 0.10
# define MOVE_DIST 0.10
# define S_W 1024 
# define S_H 768

# ifdef __linux__
#  define XK_ESCAPE 0xff1b
#  define XK_W 0x0077
#  define XK_A 0x0061
#  define XK_S 0x0073
#  define XK_D 0x0064
#  define XK_LEFT 0xff51
#  define XK_RIGHT 0xff53
# else
#  define XK_ESCAPE 53
#  define XK_W 13
#  define XK_A 0
#  define XK_S 1
#  define XK_D 2
#  define XK_LEFT 123
#  define XK_RIGHT 124
# endif

enum	e_err_codes
{
	ERR_ARGS = 1,
	ERR_FILE,
	ERR_ACCESS,
	ERR_GNL,
	ERR_MLX,
	ERR_MALLOC,
	ERR_INFO,
	ERR_MAP_NULL,
	ERR_MAP_OPEN,
	ERR_MAP_CHAR,
	ERR_MAP_MULTIPLAYER,
};

#endif
