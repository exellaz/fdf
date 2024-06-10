/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:30:49 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 15:01:45 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_rotate_controls(void *mlx_ptr, void *win_ptr, int *y)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Close window: ESC");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Rotate about X-axis: W / S");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Rotate about Z-axis: A / D");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Rotate about Y-axis: J / L");
}

void	put_transformation_controls(void *mlx_ptr, void *win_ptr, int *y)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Move image: Arrow keys");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Resize: + / -");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Increase elevation: Z");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Decrease elevation: X");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Toggle preset color: .");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Reset view: R");
}

void	put_projection_controls(void *mlx_ptr, void *win_ptr, int *y)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Isometric View: I");
	mlx_string_put(mlx_ptr, win_ptr, 15, *y += 30, WHITE_CLR,
		"Orthographic View: O");
	mlx_string_put(mlx_ptr, win_ptr, 40, *y += 20, WHITE_CLR,
		"Front View: F");
	mlx_string_put(mlx_ptr, win_ptr, 40, *y += 20, WHITE_CLR,
		"Top View: T");
	mlx_string_put(mlx_ptr, win_ptr, 40, *y += 20, WHITE_CLR,
		"Side View: G");
}

void	render_side_bar(void *mlx_ptr, void *win_ptr)
{
	int	y;

	y = 30;
	put_rotate_controls(mlx_ptr, win_ptr, &y);
	put_transformation_controls(mlx_ptr, win_ptr, &y);
	put_projection_controls(mlx_ptr, win_ptr, &y);
}
