/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:25:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:00:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_rays	ray(t_tuple origin, t_tuple direction)
{
	t_rays	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_tuple	position(t_rays r, double t)
{
	t_tuple	result;

	result = mult_tuple(r.direction, t);
	result = adding_tuple(r.origin, result);
	return (result);
}

t_sphere	sphere(double ray)
{
	t_sphere	s;
	t_matrices	m;

	s.radius = ray;
	m = create_matrices(4, 4);
	s.id = id_matrix(m, ray);
	s.material = material();
	s.transform = inverse(s.id);
	s.transpose = transpose(s.transform);
	return (s);
}

double	discriminant(double a, double b, double c)
{
	double	d;

	d = ((b * b) - 4 * a * c);
	return (d);
}

t_xs	local_intersect(t_pl pl, t_rays r, t_xs xs)
{
	t_tuple	sphere_to_ray;

	if (fabs(r.direction.y) < EPSILON)
		return (xs);
	else
	{
		xs.count += 1;
		xs.data[xs.count - 1].t = (-r.origin.y) / r.direction.y;
		xs.data[xs.count -1].pl = pl;
		xs.data[xs.count -1].type = 3;
	}
	return (xs);
}
