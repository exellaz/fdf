/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:27:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/14 14:48:42 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
		return (0);
	init_vars(&vars);
	count_lines(av[1], &vars.y_count);
	parse_input(av[1], &vars);
	center_cords_on_origin(&vars, &vars.cord_ori);
	mlx(&vars);
	return (0);
}

void	mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit_handler(MALLOC_ERR);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "win");
	vars->img.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_hook(vars->win, 2, 1, &key_events, vars);
	mlx_hook(vars->win, 17, 1, &close_window, vars);
	mlx_loop(vars->mlx);
}
