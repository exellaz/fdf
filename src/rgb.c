/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:52:25 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/06/03 14:59:52 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return ((color & 0xFF));
}

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
