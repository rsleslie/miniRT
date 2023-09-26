/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defining_a_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:58:46 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 11:36:58 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_matrices	orientation_matrices(t_tuple left, t_tuple forward, t_tuple true_up)
{
	t_matrices m;

	m = create_matrices(4, 4);
	m.matrices[0][0] = left.x;
	m.matrices[0][1] = left.y;
	m.matrices[0][2] = left.z;
	m.matrices[1][0] = true_up.x;
	m.matrices[1][1] = true_up.y;
	m.matrices[1][2] = true_up.z;
	m.matrices[2][0] = -forward.x;
	m.matrices[2][1] = -forward.y;
	m.matrices[2][2] = -forward.z;
	m.matrices[3][3] = 1;
	return (m);
}

t_matrices	view_transform_two(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple 	forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrices	orientation;
	t_tuple		upn;

	forward = to;
	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	orientation = orientation_matrices(left, forward, true_up);
	orientation = mult_matrices(orientation, translation(-from.x, -from.y, -from.z));
	return (orientation);
}

t_matrices	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple 	forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrices	orientation;
	t_tuple		upn;

	forward = normalize(subtracting_tuple(to, from));
	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	orientation = orientation_matrices(left, forward, true_up);
	orientation = mult_matrices(orientation, translation(-from.x, -from.y, -from.z));
	return (orientation);
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

t_rays	ray_for_pixel(t_c_world camera, double px, double py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	
	t_rays	r;
	t_tuple	pixel;
	
	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;

	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;

	pixel = mult_matrix_tuple(inverse(camera.transform),
			point(world_x, world_y, -1));

	r.origin = mult_matrix_tuple(inverse(camera.transform), point(0, 0, 0));

	r.direction = normalize(subtracting_point(pixel, r.origin));
	return (r);
}

void	render_img(t_c_world c, t_world w)
{
	t_color		color;
	t_color		c_d;
	t_rays		r;
	int			x;
	int			y;

	y = -1;
	while (++y < c.vsize - 1)
	{
		x = -1;
		while (++x < c.hsize - 1)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(w, r);
			c_d = rgb_to_double(color);
			// printf("%lf, %lf, %lf\n", color.r, color.g, color.b);
			img_pix_put(w.data, (int)x, (int)y, set_color(c_d));
		}
	}
}