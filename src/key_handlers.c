/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:56:13 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 13:53:02 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_events(int keycode, t_vars *vars)
{
	vars->flags.redraw = TRUE;
	if (keycode == KEY_ESC)
		close_window(vars);
	else if (keycode == KEY_DOT)
	{
		vars->flags.preset_color = !vars->flags.preset_color;
		vars->flags.color_initialized = FALSE;
	}
	else if (keycode == KEY_R)
		reset_view(vars);
	handle_zoom_and_z_factor(keycode, vars);
	handle_projections(keycode, vars);
	if (vars->flags.orthographic == FALSE)
		handle_rotation(keycode, vars);
	handle_translation(keycode, vars);
	return (0);
}

void	handle_translation(int keycode, t_vars *vars)
{
	int	tx;
	int	ty;

	tx = 0;
	ty = 0;
	if (keycode == KEY_UP)
		ty = -10;
	else if (keycode == KEY_DOWN)
		ty = 10;
	else if (keycode == KEY_LEFT)
		tx = -10;
	else if (keycode == KEY_RIGHT)
		tx = 10;
	vars->offset_x += tx;
	vars->offset_y += ty;
}

void	handle_zoom_and_z_factor(int keycode, t_vars *vars)
{
	if (keycode == KEY_MINUS && vars->zoom > 1)
		vars->zoom--;
	else if (keycode == KEY_PLUS)
		vars->zoom++;
	else if (keycode == KEY_Z)
		vars->z_factor += 0.05;
	else if (keycode == KEY_X)
		vars->z_factor -= 0.05;
}

void	handle_rotation(int keycode, t_vars *vars)
{
	float	rotate_amt;

	rotate_amt = 5;
	if (keycode == KEY_D)
		vars->angle_z_axis += rotate_amt;
	else if (keycode == KEY_A)
		vars->angle_z_axis += -rotate_amt;
	else if (keycode == KEY_W)
		vars->angle_x_axis += rotate_amt;
	else if (keycode == KEY_S)
		vars->angle_x_axis += -rotate_amt;
	else if (keycode == KEY_L)
		vars->angle_y_axis += rotate_amt;
	else if (keycode == KEY_J)
		vars->angle_y_axis += -rotate_amt;
}
