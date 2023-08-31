/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:36:31 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/30 21:37:21 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_color	get_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	color_scale(double f, t_color color)
{
	return ((t_color){f * color.r, f * color.g, f * color.b});
}

t_color	add_colors(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r + c2.r;
	c3.g = c1.g + c2.g;
	c3.b = c1.b + c2.b;
	return (c3);
}

t_color	sub_colors(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r - c2.r;
	c3.g = c1.g - c2.g;
	c3.b = c1.b - c2.b;
	return (c3);
}

t_color	hadamard_product(t_color c1, t_color c2)
{
	t_color	c3;

	c3.r = c1.r * c2.r;
	c3.g = c1.g * c2.g;
	c3.b = c1.b * c2.b;
	return (c3);
}
