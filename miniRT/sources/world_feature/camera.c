/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:56:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_c_world	camera(double hsize, double vsize, double field_of_view)
{
	t_c_world	c;
	double		half_view;
	double		aspect;

	c.field_of_view = field_of_view;
	c.vsize = vsize;
	c.hsize = hsize;
	half_view = tan(c.field_of_view / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2.0) / c.hsize;
	c.transform = id_matrix(create_matrices(4, 4), 1);
	return (c);
}
