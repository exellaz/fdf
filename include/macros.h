/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:39:14 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 16:51:48 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define TRUE 1
# define FALSE 0

# define PI 3.14159
# define HEX_BASE "0123456789ABCDEF"

# define WHITE_CLR 0xFFFFFF
# define RED_CLR 0xFF0000
# define GREEN_CLR 0x00FF00
# define BLUE_CLR 0x0000FF
# define MINT_CLR 0xA7FF83
# define CYAN_CLR 0x76EFF0

# define MALLOC_ERR "Failed to allocate memory"
# define FILE_ERR "Unable to open the file"

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_MINUS 27
#  define KEY_PLUS 24
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_J 38
#  define KEY_L 37
#  define KEY_DOT 47
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_R 15
#  define KEY_I 34
#  define KEY_O 31
#  define KEY_F 3
#  define KEY_T 17
#  define KEY_G 5

# elif __linux__
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_J 106
#  define KEY_L 108
#  define KEY_DOT 46
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_R 114
#  define KEY_I 105
#  define KEY_O 111
#  define KEY_F 102
#  define KEY_T 116
#  define KEY_G 103
#  define KEY_U 117
# endif

#endif
