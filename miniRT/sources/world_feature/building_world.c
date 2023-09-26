/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:01:47 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 17:46:25 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_xs intersections(t_objects *rt, t_rays r);

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

// t_xs intersections_world(t_world w, t_rays r)
// {
// 	t_xs	xs;

// 	xs.count = 0;
// 	xs = intersect_world(w.s1, r, xs);
// 	xs = intersect_world(w.s2, r, xs);
// 	xs = order_xs(xs);
// 	return (xs);
// }

// t_xs	intersect_world(t_sphere sp, t_rays r, t_xs xs)
// {
// 	t_tuple	sphere_to_ray;
// 	double	a;
// 	double	b;
// 	double	c;

// 	r = transform(r, sp.transform);
// 	sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
// 	a = dot(r.direction, r.direction);
// 	b = 2.0 * dot(r.direction, sphere_to_ray);
// 	c = dot(sphere_to_ray, sphere_to_ray) - 1.0;
// 	if (discriminant(a, b, c) < 0)
// 		return (xs);
// 	else
// 	{
// 		xs.count += 2;
// 		xs.data[xs.count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2. * a));
// 		xs.data[xs.count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2. * a));
// 		xs.data[xs.count -1].sp = sp;
// 		xs.data[xs.count  - 2].sp = sp;
// 	}
// 	return (xs);
// }

// t_intersection	intersection_world(double n, t_sphere s)
// {
// 	t_intersection	t;

// 	t.t = n;
// 	t.sp = s;
// 	return (t);
// }

t_tuple	normal_at_world(t_sp sp, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(sp.inverse, p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(sp.transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

// t_tuple	normal_at_world(t_sphere s, t_tuple p)
// {
// 	t_tuple	v;
// 	t_tuple	object_point;
// 	t_tuple	object_normal;
// 	t_tuple	world_normal;

// 	object_point = mult_matrix_tuple(s.transform, p);
// 	object_normal = subtracting_point(object_point, point(0, 0, 0));
// 	world_normal = mult_matrix_tuple(s.transpose, object_normal);
// 	world_normal.w = 0;
// 	return (normalize(world_normal));
// }

// t_comps	prepare_computations(t_intersection i, t_rays r)
// {
// 	t_comps	comps;
	
// 	comps.t.t = i.t;
// 	comps.object = i.object;
// 	comps.point = position(r, comps.t.t);
// 	comps.eyev = negate(r.direction);
// 	comps.normalv = normal_at_world(comps.object, comps.point);
// 	if (dot(comps.normalv, comps.eyev) < 0)
// 	{
// 		comps.inside = TRUE;
// 		comps.normalv = negate(comps.normalv);
// 	}
// 	else
// 		comps.inside = FALSE;
// 	return (comps);
// }
t_tuple local_normal_at(t_pl pl, t_tuple local_point)
{
	(void)pl;
	(void)local_point;
	return (vector(0, 1, 0));
}

t_tuple	normal_at_pl(t_pl pl, t_tuple p)
{
	t_tuple	v;
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_point = mult_matrix_tuple(pl.inverse, p);
	local_normal = local_normal_at(pl, local_point);
	world_normal = mult_matrix_tuple(pl.transpose, local_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

t_comps	prepare_computations(t_intersection i, t_rays r)
{
	t_comps	comps;
	
	comps.t.t = i.t;
	comps.type = i.type;
	if (i.type == 1)
		comps.sp = i.sp;
	else if (i.type == 3)
		comps.pl = i.pl;
	comps.point = position(r, comps.t.t);
	comps.eyev = negate(r.direction);
	if (i.type == 1)
		comps.normalv = normal_at_world(comps.sp, comps.point);
	else if (i.type == 3)
		comps.normalv = normal_at_pl(comps.pl, comps.point);
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
	
	if (comps.type == 1)
		color = lighting(comps.sp.material, w.ligth, comps.point, comps.eyev, comps.normalv);
	else if (comps.type == 3)
		color = lighting(comps.pl.material, w.ligth, comps.point, comps.eyev, comps.normalv);
	return (color);	
}

t_intersection	hit_two(t_xs xs)
{
	t_intersection	i;
	int j;
	
	j= -1;
	while (++j < xs.count)
	{
		if (xs.data[j].t > 0)
		{
			i = xs.data[j];
			break ;
		}
		else
			i.t = -1;
	}
	return (i);
}

t_color	color_at(t_world w, t_rays r)
{
	t_xs			xs;
	t_comps			comps;
	t_color			result_color;
	t_intersection	i;
	int j;
	
	xs = intersections(w.rt, r);
	if (equal(xs.count, 0))
		return (get_color(0, 0, 0));
	j = -1;
	while (++j < xs.count)
	{
		if (xs.data[j].t > 0)
		{
			i = xs.data[j];
			break ;
		}
		else
			i.t = -1;
	}
	if (equal(i.t, -1))
		return (get_color(0, 0, 0));
	comps = prepare_computations(i, r);
	result_color = shade_hit(w, comps);
	// printf("%lf, %lf, %lf\n", result_color.r, result_color.g, result_color.b);
	return (result_color);
}
