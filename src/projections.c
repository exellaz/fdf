/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:23 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/09 14:09:27 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_projections(int keycode, t_vars *vars)
{
	if (keycode == KEY_O || keycode == KEY_I)
	{
		reset_view(vars);
		if (keycode == KEY_O)
		{
			vars->flags.isometric = FALSE;
			vars->flags.orthographic = TRUE;
		}
		else if (keycode == KEY_I)
		{
			vars->flags.isometric = TRUE;
			vars->flags.orthographic = FALSE;
		}
	}
	if (vars->flags.orthographic == TRUE)
		orthographic_projections(keycode, vars);
}

void	orthographic_projections(int keycode, t_vars *vars)
{
	if (keycode == KEY_T)
	{
		vars->angle_x_axis = 0;
		vars->angle_y_axis = 0;
		vars->angle_z_axis = 0;
	}
	else if (keycode == KEY_G)
	{
		vars->angle_x_axis = 90;
		vars->angle_y_axis = -90;
		vars->angle_z_axis = 0;
	}
	else if (keycode == KEY_F)
	{
		vars->angle_x_axis = 90;
		vars->angle_y_axis = 0;
		vars->angle_z_axis = 0;
	}
}

void	do_isometric(t_vars *vars, t_cord ***cord)
{
	float	matrix[3][3];

	matrix[0][0] = cos(0.523599);
	matrix[0][1] = -cos(0.523599);
	matrix[0][2] = 0;
	matrix[1][0] = sin(0.523599);
	matrix[1][1] = sin(0.523599);
	matrix[1][2] = -1;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 0;
	multiply_matrix(vars, cord, matrix);
}

void	reset_view(t_vars *vars)
{
	vars->angle_x_axis = 0;
	vars->angle_y_axis = 0;
	vars->angle_z_axis = 0;
	vars->z_factor = 1;
	vars->offset_x = WINDOW_WIDTH / 2;
	vars->offset_y = WINDOW_HEIGHT / 2;
	vars->zoom = ((WINDOW_WIDTH / vars->x_count) / 3);
	if (vars->flags.orthographic == TRUE)
		vars->flags.orthographic = FALSE;
	else if (vars->flags.isometric == TRUE)
		vars->flags.isometric = FALSE;
}
