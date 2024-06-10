/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:44:10 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 14:59:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient(int min_color, int max_color, int len, int position)
{
	float	increment[3];
	int		rgb[3];
	int		new_color;

	increment[0] = (float)((get_r(max_color)) - (get_r(min_color)))
		/ (float)len;
	increment[1] = (float)((get_g(max_color)) - (get_g(min_color)))
		/ (float)len;
	increment[2] = (float)((get_b(max_color)) - (get_b(min_color)))
		/ (float)len;
	rgb[0] = (get_r(min_color)) + round(position * increment[0]);
	rgb[1] = (get_g(min_color)) + round(position * increment[1]);
	rgb[2] = (get_b(min_color)) + round(position * increment[2]);
	new_color = get_rgb(rgb[0], rgb[1], rgb[2]);
	return (new_color);
}

void	init_preset_color_map(t_vars *vars, t_cord ***cord, t_cord **cord_ori)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	vars->flags.color_initialized = TRUE;
	while (y < vars->y_count)
	{
		x = 0;
		while (x < vars->x_count)
		{
			if (vars->z_max != vars->z_min && vars->flags.preset_color == TRUE)
				(*cord)[y][x].color = lerp_colors(vars, cord_ori[y][x].z);
			else
				(*cord)[y][x].color = WHITE_CLR;
			x++;
		}
		y++;
	}
}

int	get_color(float normalized_z, int max_color, int min_color)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	r = get_r(min_color) + (get_r(max_color) - get_r(min_color)) * normalized_z;
	g = get_g(min_color) + (get_g(max_color) - get_g(min_color)) * normalized_z;
	b = get_b(min_color) + (get_b(max_color) - get_b(min_color)) * normalized_z;
	new_color = get_rgb(r, g, b);
	return (new_color);
}

float	get_fraction(t_vars *vars, float x)
{
	if (vars->z_min != vars->z_max)
		return ((x - vars->z_min) / (vars->z_max - vars->z_min));
	return (0);
}

int	lerp_colors(t_vars *vars, float cord_ori_z)
{
	float	normalized_z;
	int		cord_color;

	normalized_z = get_fraction(vars, cord_ori_z);
	cord_color = get_color(normalized_z, MINT_CLR, CYAN_CLR);
	return (cord_color);
}
