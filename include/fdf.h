/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:39:07 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/10 15:42:14 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "macros.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <mlx.h>

//Parsing
void	count_lines(char *input, int *line_count);
int		count_word(char *str, char c);
void	parse_input(char *input, t_vars *vars);
void	parse_lines(t_vars *vars, int fd);
void	store_cords(t_vars *vars, t_cord ***cord, char **str_arr, int y);

//Initializing
void	init_vars(t_vars *vars);

//Put Pixel
void	put_image_pixel(t_img *img, int x, int y, int color);

//MLX
void	mlx(t_vars *vars);

//Rendering
int		render(t_vars *vars);
void	render_vertical(t_vars *vars, t_cord ***grid);
void	render_horizontal(t_vars *vars, t_cord ***grid);
void	render_grid(t_vars *vars, t_cord ***grid);

//Bresenham
void	swap_cords(t_line_data *line);
void	small_slope(t_img *img, t_line_data cord);
void	big_slope(t_img *img, t_line_data cord);
void	render_line(t_img *img, t_line_data line);

//Colors
int		gradient(int min_color, int max_color, int len, int position);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
int		get_rgb(int r, int g, int b);
int		lerp_colors(t_vars *vars, float cord_ori_z);
int		get_color(float normalized_z, int max_color, int min_color);
float	get_fraction(t_vars *vars, float z);
void	init_preset_color_map(t_vars *vars, t_cord ***cord, t_cord **cord_ori);

//Translations
void	center_cords_on_origin(t_vars *vars, t_cord ***cord_ori);
void	translate_2d(t_vars *vars, t_cord ***cord, float tx, float ty);
void	reset_view(t_vars *vars);

//Resize
void	resize(t_vars *vars);

//Rotations
void	multiply_matrix(t_vars *vars, t_cord ***cord, float matrix[3][3]);
void	rotate_about_x_axis(t_vars *vars, t_cord ***cord, float angle);
void	rotate_about_z_axis(t_vars *vars, t_cord ***cord, float angle);
void	rotate_about_y_axis(t_vars *vars, t_cord ***cord, float angle);

//Projections
void	do_isometric(t_vars *vars, t_cord ***cord);
void	orthographic_projections(int keycode, t_vars *vars);

//Side Bar
void	render_side_bar(void *mlx_ptr, void *win_ptr);
void	put_projection_controls(void *mlx_ptr, void *win_ptr, int *y);
void	put_rotate_controls(void *mlx_ptr, void *win_ptr, int *y);
void	put_transformation_controls(void *mlx_ptr, void *win_ptr, int *y);

//Key Handlers
void	handle_rotation(int keycode, t_vars *vars);
void	handle_translation(int keycode, t_vars *vars);
void	handle_projections(int keycode, t_vars *vars);
void	handle_zoom_and_z_factor(int keycode, t_vars *vars);
int		key_events(int keycode, t_vars *vars);

//Utils
t_cord	**duplicate_coordinates(t_vars *vars, t_cord **cord);
float	get_radians(float angle_degrees);
void	update_z_min_max(t_vars *vars, int current_z);

//Free & Exit
void	free_cords(t_vars *vars, t_cord **cord);
void	exit_handler(char *error);
int		close_window(t_vars *vars);

#endif
