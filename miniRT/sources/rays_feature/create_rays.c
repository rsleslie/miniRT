/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:25:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 17:13:17 by rleslie-         ###   ########.fr       */
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

// t_xs intersections(t_objects *rt, t_rays r)
// {
// 	t_xs	order;
// 	t_xs	xs;
// 	int		i;

// 	i = -1;
// 	xs.count = 0;
// 	while (++i < rt->n_sp)
// 		xs = intersect(rt->sp[i], r, xs);
// 	xs = order_xs(xs);
// 	return (xs);
// }

t_xs	intersect(t_sp sp, t_rays r, t_xs xs)
{
	t_tuple	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	r = transform(r, sp.inverse);
	sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
	a = dot(r.direction, r.direction);
	b = 2 * dot(r.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	if (discriminant(a, b, c) < 0)
		return (xs);
	else
	{
		xs.count += 2;
		xs.data[xs.count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count -1].type = 1;
		xs.data[xs.count  - 2].type = 1;
		xs.data[xs.count -1].sp = sp;
		xs.data[xs.count  - 2].sp = sp;
	}
	return (xs);
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

t_xs intersections(t_objects *rt, t_rays r)
{
	t_xs	order;
	t_xs	xs;
	int		i;

	i = -1;
	xs.count = 0;
	while (++i < rt->n_sp)
		xs = intersect(rt->sp[i], r, xs);
	i = -1;
	while (++i < rt->n_pl)
		xs = local_intersect(rt->pl[i], r, xs);
	xs = order_xs(xs);
	return (xs);
}