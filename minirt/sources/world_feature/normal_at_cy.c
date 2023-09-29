/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:07:15 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_xs	*truncate_cylinder(t_cy cylinder, t_rays ray, t_xs *xs, double t[2])
{
	double	y0;
	double	y1;

	t = swap(t);
	y0 = ray.origin.y + t[0] * ray.direction.y;
	if (cylinder.min < y0 && y0 < cylinder.max)
	{
		xs->count += 1;
		xs->data[xs->count - 1].t = t[0];
		xs->data[xs->count - 1].type = 2;
		xs->data[xs->count - 1].cy = cylinder;
	}
	y1 = ray.origin.y + t[1] * ray.direction.y;
	if (cylinder.min < y1 && y1 < cylinder.max)
	{
		xs->count += 1;
		xs->data[xs->count - 1].t = t[1];
		xs->data[xs->count - 1].cy = cylinder;
		xs->data[xs->count - 1].type = 2;
	}
	return (xs);
}

t_xs	*local_intersect_cyl(t_cy cylinder, t_rays ray, t_xs *xs)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	t[2];

	ray = transform(ray, cylinder.inverse);
	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (equal(a, 0))
		return (xs);
	b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	disc = discriminant(a, b, c);
	if (disc < 0)
		return (xs);
	t[0] = (-b - sqrt(disc)) / (2 * a);
	t[1] = (-b + sqrt(disc)) / (2 * a);
	xs = truncate_cylinder(cylinder, ray, xs, t);
	xs = intersect_caps(cylinder, ray, xs);
	return (xs);
}

t_tuple	normal_at_cyl(t_cy cylinder, t_tuple point)
{
	double	dist;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(cylinder.inverse, point);
	dist = pow(object_point.x, 2) + pow(object_point.z, 2);
	if (dist < 1 && object_point.y >= cylinder.max - EPSILON)
		object_normal = vector(0, 1, 0);
	else if (dist < 1 && object_point.y <= cylinder.min + EPSILON)
		object_normal = vector(0, -1, 0);
	else
		object_normal = vector(object_point.x, 0, object_point.z);
	world_normal = mult_matrix_tuple(cylinder.transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

int	check_cap(t_rays ray, double t, t_cy cy)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if (pow(x, 2) + pow(z, 2) <= 1)
		return (TRUE);
	return (FALSE);
	(void)cy;
}

t_xs	*intersect_caps(t_cy cyl, t_rays ray, t_xs *xs)
{
	double	t;

	if (equal(ray.direction.y, 0))
		return (xs);
	t = (cyl.min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cyl))
	{
		xs->count += 1;
		xs->data[xs->count - 1].t = t;
		xs->data[xs->count - 1].type = 2;
		xs->data[xs->count - 1].cy = cyl;
	}
	t = (cyl.max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cyl))
	{
		xs->count += 1;
		xs->data[xs->count - 1].t = t;
		xs->data[xs->count - 1].type = 2;
		xs->data[xs->count - 1].cy = cyl;
	}
	return (xs);
}
