/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:03:48 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/09 14:20:09 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	small_slope(t_img *img, t_line_data line)
{
	t_line_var	var;

	var.dx = line.x2 - line.x1;
	var.dy = line.y2 - line.y1;
	var.y_inc = 1;
	if (var.dy < 0)
		var.y_inc = -1;
	var.p = (2 * abs(var.dy)) - var.dx;
	var.x = line.x1;
	var.y = line.y1;
	while (var.x <= line.x2)
	{
		put_image_pixel(img, var.x, var.y, gradient(line.color1,
				line.color2, abs(var.dx), var.x - line.x1));
		if (var.p <= 0)
			var.p = var.p + (2 * abs(var.dy));
		else
		{
			var.p = var.p + (2 * (abs(var.dy) - var.dx));
			var.y += var.y_inc;
		}
		var.x++;
	}
}

void	big_slope(t_img *img, t_line_data line)
{
	t_line_var	var;

	var.dx = line.x2 - line.x1;
	var.dy = line.y2 - line.y1;
	var.x_inc = 1;
	if (var.dx < 0)
		var.x_inc = -1;
	var.p = (2 * var.dy) - abs(var.dx);
	var.x = line.x1;
	var.y = line.y1;
	while (var.y <= line.y2)
	{
		put_image_pixel(img, var.x, var.y, gradient(line.color1,
				line.color2, abs(var.dy), var.y - line.y1));
		if (var.p <= 0)
			var.p = var.p + (2 * abs(var.dx));
		else if (var.p > 0 && var.dx != 0)
		{
			var.p = var.p + (2 * (abs(var.dx) - var.dy));
			var.x += var.x_inc;
		}
		var.y++;
	}
}

void	swap_cords(t_line_data *line)
{
	int	temp;

	temp = line->x1;
	line->x1 = line->x2;
	line->x2 = temp;
	temp = line->y1;
	line->y1 = line->y2;
	line->y2 = temp;
	temp = line->color1;
	line->color1 = line->color2;
	line->color2 = temp;
}

void	render_line(t_img *img, t_line_data line)
{
	if (abs(line.x2 - line.x1) > abs(line.y2 - line.y1))
	{
		if (line.x1 > line.x2)
			swap_cords(&line);
		small_slope(img, line);
	}
	else
	{
		if (line.y1 > line.y2)
			swap_cords(&line);
		big_slope(img, line);
	}
}

void	put_image_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
