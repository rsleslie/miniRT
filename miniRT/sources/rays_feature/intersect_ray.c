/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:59:56 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 16:59:57 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_xs	intersections(t_objects *rt, t_rays r)
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
		xs.data[xs.count - 1].t = ((-b
					-sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count - 2].t = ((-b
					+sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count -1].type = 1;
		xs.data[xs.count - 2].type = 1;
		xs.data[xs.count -1].sp = sp;
		xs.data[xs.count - 2].sp = sp;
	}
	return (xs);
}