/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:27:21 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/28 14:45:48 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_world	world(void)
{
	t_world	w;

	w.ligth = point_light(point(-10, 10, -10), get_color(1, 1, 1));
	w.s1 = sphere(1.0);
	w.s1.material.color = get_color(0.8, 1.0, 0.6);
	w.s1.material.diffuse = (double)0.7;
	w.s1.material.specular = (double)0.2;
	w.s2 = sphere(0.5);
	w.s2.transform = translation(0, 0, 10);
	return (w);
}

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
