/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:37:34 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 16:34:33 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	set_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	if (color.b < 0.0)
		color.b = 0.0;
	if (color.g < 0.0)
		color.g = 0.0;
	if (color.r < 0.0)
		color.r = 0.0;
	if (color.b > 1.0)
		color.b = 1.0;
	if (color.g > 1.0)
		color.g = 1.0;
	if (color.r > 1.0)
		color.r = 1.0;
	r = (int)(color.r * 255.0);
	g = (int)(color.g * 255.0);
	b = (int)(color.b * 255.0);
	return (0xFF << 24 | r << 16 | g << 8 | b);
}

t_color	rgb_to_double(t_color color)
{
	t_color	color_d;

	color_d.r = color.r / 255.0;
	color_d.g = color.g / 255.0;
	color_d.b = color.b / 255.0;
	return (color_d);
}
