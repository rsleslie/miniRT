/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:59:56 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 15:48:56 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_xs	*order_xs(t_xs *xs)
{
	t_xs	*order;
	int		counter;
	int		i;
	int		j;

	order = (t_xs *)malloc(sizeof(t_xs));
	order->count = xs->count;
	i = -1;
	counter = 0;
	while (++i < xs->count)
	{
		j = 0;
		counter = 0;
		while (j < xs->count)
		{
			if (xs->data[i].t > xs->data[j].t)
				counter++;
			j++;
		}
		order->data[counter] = xs->data[i];
	}
	free(xs);
	return (order);
}

t_xs	*local_intersect_pl(t_pl pl, t_rays r, t_xs *xs)
{
	r = transform(r, pl.inverse);
	if (fabs(r.direction.y) < EPSILON)
		return (xs);
	else
	{
		xs->count += 1;
		xs->data[xs->count - 1].t = (-r.origin.y) / r.direction.y;
		xs->data[xs->count -1].pl = pl;
		xs->data[xs->count -1].type = 3;
	}
	return (xs);
}

t_xs	*intersect(t_sp sp, t_rays r, t_xs *xs)
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
		xs->count += 2;
		xs->data[xs->count - 1].t = ((-b
					- sqrt(discriminant(a, b, c))) / (2 * a));
		xs->data[xs->count - 2].t = ((-b
					+ sqrt(discriminant(a, b, c))) / (2 * a));
		xs->data[xs->count -1].type = 1;
		xs->data[xs->count - 2].type = 1;
		xs->data[xs->count -1].sp = sp;
		xs->data[xs->count - 2].sp = sp;
	}
	return (xs);
}

t_xs	*intersections(t_objects *rt, t_rays r, t_xs *xs)
{
	t_xs	*order;
	int		i;

	i = -1;
	xs->count = 0;
	while (++i < rt->n_sp)
		xs = intersect(rt->sp[i], r, xs);
	i = -1;
	while (++i < rt->n_pl)
		xs = local_intersect_pl(rt->pl[i], r, xs);
	i = -1;
	while (++i < rt->n_cy)
		xs = local_intersect_cyl(rt->cy[i], r, xs);
	order = order_xs(xs);
	return (order);
}
