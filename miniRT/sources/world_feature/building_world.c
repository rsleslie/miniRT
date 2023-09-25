/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:01:47 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/25 14:58:23 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_world	default_world(void)
{
	t_world	w;

	w = world();
	return (w);
}

t_world	world(void)
{
	t_world	w;

	w.ligth = point_light(point(-10, 10, -10), get_color(1, 1, 1));	
	w.s1 = sphere(1.0);
	w.s1.material.color = get_color(0.8, 1.0, 0.6);
	w.s1.material.diffuse = (double)0.7;
	w.s1.material.specular = (double)0.2;
	w.s2 = sphere(0.5);
	return (w);
}

t_xs	order_xs(t_xs xs)
{
	t_xs	order;
	int		counter;
	int		i;
	int		j;

	order.count = xs.count;
	i = -1;
	counter = 0;
	while (++i < xs.count)
	{
		j = 0;
		counter = 0;
		while(j < xs.count)
		{
			if (xs.data[i].t > xs.data[j].t)
				counter++;
			j++;
		}	
		order.data[counter] = xs.data[i];
	}
	return (order);
}

t_xs intersections_world(t_world w, t_rays r)
{
	t_xs	xs;

	xs.count = 0;
	xs = intersect_world(w.s1, r, xs);
	xs = intersect_world(w.s2, r, xs);
	xs = order_xs(xs);
	return (xs);
}

t_xs	intersect_world(t_sphere sp, t_rays r, t_xs xs)
{
	t_tuple	sphere_to_ray;
	double	a;
	double	b;
	double	c;

	r = transform(r, sp.transform);
	sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
	a = dot(r.direction, r.direction);
	b = 2.0 * dot(r.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1.0;
	if (discriminant(a, b, c) < 0)
		return (xs);
	else
	{
		xs.count += 2;
		xs.data[xs.count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2. * a));
		xs.data[xs.count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2. * a));
		xs.data[xs.count -1].s_world = sp;
		xs.data[xs.count  - 2].s_world = sp;
	}
	return (xs);
}

t_intersection	intersection_world(double n, t_sphere s)
{
	t_intersection	t;

	t.t = n;
	t.s_world = s;
	return (t);
}

t_tuple	normal_at_world(t_sphere s, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(s.transform, p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(s.transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_comps	prepare_computations(t_intersection i, t_rays r)
{
	t_comps	comps;
	
	comps.t.t = i.t;
	comps.object = i.s_world;
	comps.point = position(r, comps.t.t);
	comps.eyev = negate(r.direction);
	comps.normalv = normal_at_world(comps.object, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate(comps.normalv);
	}
	else
		comps.inside = FALSE;
	return (comps);
}

t_color	shade_hit(t_world w, t_comps comps)
{
	t_color color;

	color = lighting(comps.object.material, w.ligth,
			comps.point, comps.eyev, comps.normalv);
	return (color);	
}

t_color	color_at(t_world w, t_rays r)
{
	t_xs			xs;
	t_intersection	i;
	t_comps			comps;
	t_color			result_color;
	
	xs = intersections_world(w, r);
	if (equal(xs.count, 0))
		return (get_color(0, 0, 0));
	i = hit(xs);
	if (equal(i.t, -1))
		return (get_color(0, 0, 0));
	comps = prepare_computations(i, r);
	result_color = shade_hit(w, comps);
	return (result_color);
}

