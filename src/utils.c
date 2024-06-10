/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:13:37 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 15:07:23 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_z_min_max(t_vars *vars, int current_z)
{
	if (current_z > vars->z_max)
		vars->z_max = current_z;
	if (current_z < vars->z_min)
		vars->z_min = current_z;
}

void	init_vars(t_vars *vars)
{
	vars->y_count = 0;
	vars->x_count = 0;
	vars->offset_x = WINDOW_WIDTH / 2;
	vars->offset_y = WINDOW_HEIGHT / 2;
	vars->z_factor = 1;
	vars->zoom = 20;
	vars->angle_x_axis = 0;
	vars->angle_y_axis = 0;
	vars->angle_z_axis = 0;
	vars->z_max = 0;
	vars->z_min = 0;
	vars->flags.x_counted = FALSE;
	vars->flags.redraw = TRUE;
	vars->flags.isometric = FALSE;
	vars->flags.orthographic = FALSE;
	vars->flags.preset_color = FALSE;
	vars->flags.has_color = FALSE;
	vars->flags.color_checked = FALSE;
	vars->flags.color_initialized = FALSE;
}

void	free_cords(t_vars *vars, t_cord **cord)
{
	int	y;

	y = 0;
	while (y < vars->y_count)
	{
		free(cord[y]);
		y++;
	}
	free(cord);
}

void	exit_handler(char *error)
{
	perror(error);
	exit(1);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	free_cords(vars, vars->cord);
	free_cords(vars, vars->cord_ori);
	exit(EXIT_SUCCESS);
}
