/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:39:23 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 16:52:42 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cord
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_cord;

typedef struct s_flag
{
	int	x_counted;
	int	redraw;
	int	isometric;
	int	orthographic;
	int	preset_color;
	int	has_color;
	int	color_checked;
	int	color_initialized;
}	t_flag;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		y_count;
	int		x_count;
	int		offset_x;
	int		offset_y;
	float	z_factor;
	int		zoom;
	int		angle_x_axis;
	int		angle_y_axis;
	int		angle_z_axis;
	int		z_max;
	int		z_min;
	t_img	img;
	t_cord	**cord;
	t_cord	**cord_ori;
	t_flag	flags;
}	t_vars;

typedef struct s_line_data
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color1;
	int	color2;
}	t_line_data;

typedef struct s_line_var
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;
	int	x_inc;
	int	y_inc;
}	t_line_var;

#endif
