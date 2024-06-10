/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:38:10 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 15:00:31 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_horizontal(t_vars *vars, t_cord ***grid)
{
	int			i;
	int			j;
	t_line_data	line;

	j = 0;
	while (j < vars->y_count)
	{
		i = 0;
		while (i < vars->x_count - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j][i + 1].x);
			line.y2 = round((*grid)[j][i + 1].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j][i + 1].color;
			render_line(&vars->img, line);
			i++;
		}
		j++;
	}
}

void	render_vertical(t_vars *vars, t_cord ***grid)
{
	int			i;
	int			j;
	t_line_data	line;

	i = 0;
	while (i < vars->x_count)
	{
		j = 0;
		while (j < vars->y_count - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j + 1][i].x);
			line.y2 = round((*grid)[j + 1][i].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j + 1][i].color;
			render_line(&vars->img, line);
			j++;
		}
		i++;
	}
}

void	render_grid(t_vars *vars, t_cord ***grid)
{
	render_horizontal(vars, grid);
	render_vertical(vars, grid);
}

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	if (vars->flags.redraw == TRUE)
	{
		if (vars->flags.has_color == FALSE
			&& vars->flags.color_initialized == FALSE)
			init_preset_color_map(vars, &vars->cord, vars->cord_ori);
		resize(vars);
		ft_bzero(vars->img.addr, (WINDOW_HEIGHT
				* WINDOW_WIDTH * (vars->img.bpp / 8)));
		rotate_about_x_axis(vars, &vars->cord, vars->angle_x_axis);
		rotate_about_y_axis(vars, &vars->cord, vars->angle_y_axis);
		rotate_about_z_axis(vars, &vars->cord, vars->angle_z_axis);
		if (vars->flags.isometric == TRUE)
			do_isometric(vars, &vars->cord);
		translate_2d(vars, &vars->cord, vars->offset_x, vars->offset_y);
		render_grid(vars, &vars->cord);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		render_side_bar(vars->mlx, vars->win);
		vars->flags.redraw = FALSE;
	}
	return (0);
}

t_cord	**duplicate_coordinates(t_vars *vars, t_cord **cord)
{
	int		y;
	t_cord	**dupe;

	dupe = ft_calloc(vars->y_count, sizeof(t_cord *));
	if (dupe == NULL)
		exit_handler(MALLOC_ERR);
	y = 0;
	while (y < vars->y_count)
	{
		dupe[y] = ft_calloc(vars->x_count, sizeof(t_cord));
		if (dupe[y] == NULL)
			exit_handler(MALLOC_ERR);
		ft_memcpy(dupe[y], cord[y], vars->x_count * sizeof(t_cord));
		y++;
	}
	return (dupe);
}
