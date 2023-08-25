/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:25:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/24 21:11:12 by rleslie-         ###   ########.fr       */
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

t_tuple	position(t_rays r, float t)
{
	t_tuple	result;

	result = mult_tuple(r.direction, t);
	result = adding_tuple(r.origin, result);
	return (result);
}

t_sphere	sphere(void)
{
	t_sphere	s;

	s.radius = 1;
	return (s);
}

float	discriminant(float a, float b, float c)
{
	float	d;

	d = ((b * b) - (4 * a * c));
	return (d);
}

t_xs	intersect(t_sphere s, t_rays r)
{
	t_tuple	sphere_to_ray;
	t_xs	result;
	float	a;
	float	b;
	float	c;

	r = transform(r, inverse(s.transform));
	sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
	a = dot(r.direction, r.direction);
	b = 2 * dot(r.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	if (discriminant(a, b, c) < 0)
		result.count = 0;
	else
	{
		result.count = 2;
		result.data[0].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
		result.data[1].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
		result.data[0].object = s;
		result.data[1].object = s;
	}
	return (result);
}
