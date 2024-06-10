/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:08:57 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/09 15:23:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_lines(char *input, int *line_count)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_handler(FILE_ERR);
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		(*line_count)++;
		free(input);
	}
	close(fd);
}

void	parse_input(char *input, t_vars *vars)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		exit_handler(FILE_ERR);
	vars->cord = malloc(vars->y_count * sizeof(t_cord *));
	if (vars->cord == NULL)
		exit_handler(MALLOC_ERR);
	parse_lines(vars, fd);
}

void	parse_lines(t_vars *vars, int fd)
{
	int		y;
	char	*line;
	char	**str_arr;

	y = 0;
	while (y < vars->y_count)
	{
		line = get_next_line(fd);
		str_arr = ft_split(line, ' ');
		if (vars->flags.x_counted == FALSE)
		{
			vars->x_count = count_word(line, ' ');
			vars->flags.x_counted = TRUE;
		}
		vars->cord[y] = malloc(vars->x_count * sizeof(t_cord));
		if (vars->cord[y] == NULL)
			exit_handler(MALLOC_ERR);
		store_cords(vars, &vars->cord, str_arr, y);
		free(line);
		ft_free_s_arr(str_arr);
		y++;
	}
}

void	store_cords(t_vars *vars, t_cord ***cord, char **str_arr, int y)
{
	int	i;
	int	x;

	x = -1;
	while (++x < vars->x_count)
	{
		(*cord)[y][x].x = x;
		(*cord)[y][x].y = y;
		(*cord)[y][x].z = ft_atoi(str_arr[x]);
		update_z_min_max(vars, (*cord)[y][x].z);
		if (ft_strchr(str_arr[x], ',') != 0)
		{
			i = 0;
			while (str_arr[x][i] != 'x')
				i++;
			vars->cord[y][x].color = ft_atoi_base((&str_arr[x][++i]), HEX_BASE);
			if (vars->flags.color_checked != TRUE)
			{
				vars->flags.has_color = TRUE;
				vars->flags.color_checked = TRUE;
			}
		}
		else
			vars->cord[y][x].color = WHITE_CLR;
	}
}

int	count_word(char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (count);
}
