/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:24:32 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/09 13:26:39 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_radians(float angle_degrees)
{
	float	radians;

	radians = angle_degrees * (PI / 180);
	return (radians);
}

void	multiply_matrix(t_vars *vars, t_cord ***cord, float matrix[3][3])
{
	int		x;
	int		y;
	float	new_x;
	float	new_y;
	float	new_z;

	y = 0;
	while (y < vars->y_count)
	{
		x = 0;
		while (x < vars->x_count)
		{
			new_x = (*cord)[y][x].x * matrix[0][0] + (*cord)[y][x].y
				* matrix[0][1] + (*cord)[y][x].z * matrix[0][2];
			new_y = (*cord)[y][x].x * matrix[1][0] + (*cord)[y][x].y
				* matrix[1][1] + (*cord)[y][x].z * matrix[1][2];
			new_z = (*cord)[y][x].x * matrix[2][0] + (*cord)[y][x].y
				* matrix[2][1] + (*cord)[y][x].z * matrix[2][2];
			(*cord)[y][x].x = new_x;
			(*cord)[y][x].y = new_y;
			(*cord)[y][x].z = new_z;
			x++;
		}
		y++;
	}
}

void	rotate_about_x_axis(t_vars *vars, t_cord ***cord, float angle)
{
	float	matrix[3][3];

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(get_radians(angle));
	matrix[1][2] = -sin(get_radians(angle));
	matrix[2][0] = 0;
	matrix[2][1] = sin(get_radians(angle));
	matrix[2][2] = cos(get_radians(angle));
	multiply_matrix(vars, cord, matrix);
}

void	rotate_about_y_axis(t_vars *vars, t_cord ***cord, float angle)
{
	float	matrix[3][3];

	matrix[0][0] = cos(get_radians(angle));
	matrix[0][1] = 0;
	matrix[0][2] = sin(get_radians(angle));
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(get_radians(angle));
	matrix[2][1] = 0;
	matrix[2][2] = cos(get_radians(angle));
	multiply_matrix(vars, cord, matrix);
}

void	rotate_about_z_axis(t_vars *vars, t_cord ***cord, float angle)
{
	float	matrix[3][3];

	matrix[0][0] = cos(get_radians(angle));
	matrix[0][1] = -sin(get_radians(angle));
	matrix[0][2] = 0;
	matrix[1][0] = sin(get_radians(angle));
	matrix[1][1] = cos(get_radians(angle));
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	multiply_matrix(vars, cord, matrix);
}
