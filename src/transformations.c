/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:42:32 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 13:23:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_2d(t_vars *vars, t_cord ***cord, float tx, float ty)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->y_count)
	{
		x = 0;
		while (x < vars->x_count)
		{
			(*cord)[y][x].x += tx;
			(*cord)[y][x].y += ty;
			x++;
		}
		y++;
	}
}

void	resize(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->y_count)
	{
		x = 0;
		while (x < vars->x_count)
		{
			vars->cord[y][x].x = vars->cord_ori[y][x].x * vars->zoom;
			vars->cord[y][x].y = vars->cord_ori[y][x].y * vars->zoom;
			vars->cord[y][x].z = vars->cord_ori[y][x].z
				* vars->z_factor * vars->zoom;
			x++;
		}
		y++;
	}
}

void	center_cords_on_origin(t_vars *vars, t_cord ***cord_ori)
{
	*cord_ori = duplicate_coordinates(vars, vars->cord);
	vars->zoom = ((WINDOW_WIDTH / vars->x_count) / 3);
	translate_2d(vars, cord_ori, -(vars->x_count / 2), -(vars->y_count / 2));
}
