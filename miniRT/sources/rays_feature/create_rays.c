/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:25:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 15:46:46 by rleslie-         ###   ########.fr       */
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

t_sphere	sphere(void)
{
	t_sphere	s;
	t_matrices	m;

	s.radius = 1;
	m = create_matrices(4, 4);
	s.transform = id_matrix(m);
	s.material = material();
	// s.transform.matrices[0][0] = 0.5;
	// s.transform.matrices[1][1] = 0.5;
	// s.transform.matrices[2][2] = 0.5;
	// s.transform.matrices[0][3] = 1;
	// s.transform.matrices[1][3] = 1;
	// s.transform.matrices[2][3] = 1;
	s.transform = inverse(s.transform);
	return (s);
}

double	discriminant(double a, double b, double c)
{
	double	d;

	d = ((b * b) - 4 * a * c);
	return (d);
}

// t_xs teste_intesections(t_objects *rt, t_rays r)
// {
		
// }

// t_xs	intersect(t_sphere s, t_rays r)
// {
// 	t_tuple	sphere_to_ray;
// 	t_xs	result;
// 	double	a;
// 	double	b;
// 	float	c;

// 	r = transform(r, s.transform);
// 	sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
// 	a = dot(r.direction, r.direction);
// 	b = 2 * dot(r.direction, sphere_to_ray);
// 	c = dot(sphere_to_ray, sphere_to_ray) - 1;
// 	if (discriminant(a, b, c) < 0)
// 		result.count = 0;
// 	else
// 	{
// 		result.count += 2;
// 		result.data[0].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
// 		result.data[1].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
// 		result.data[0].object = s;
// 		result.data[1].object = s;
// 	}
// 	return (result);
// }


t_xs teste_intesections(t_objects *rt, t_rays r)
{
	t_xs	xs;
	int		i;

	i = -1;
	xs.count = 0;
	while (++i < rt->n_sp)
		xs = intersect(rt->sp[i], r, xs);
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
		xs.data[xs.count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
		xs.data[xs.count -1].object = sp;
		xs.data[xs.count  - 2].object = sp;
	}
	return (xs);
}
