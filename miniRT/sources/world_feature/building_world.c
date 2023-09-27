/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:01:47 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:55:47 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_world	world(void)
{
	t_world	w;

	w.ligth = point_light(point(-10, 10, -10), get_color(1, 1, 1));
	w.s1 = sphere(1.0);
	w.s1.material.color = get_color(0.8, 1.0, 0.6);
	w.s1.material.diffuse = (double)0.7;
	w.s1.material.specular = (double)0.2;
	w.s2 = sphere(0.5);
	w.s2.transform = translation(0, 0, 10);
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
		while (j < xs.count)
		{
			if (xs.data[i].t > xs.data[j].t)
				counter++;
			j++;
		}	
		order.data[counter] = xs.data[i];
	}
	return (order);
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
	comps.over_point = mult_tuple(comps.normalv, EPSILON);
	comps.over_point = adding_tuple(comps.point, comps.over_point);
	return (comps);
}

t_color	shade_hit(t_world *w, t_comps comps)
{
	t_color	color;
	int		s;

	s = is_shadowed(w, comps.over_point);
	if (comps.type == 1)
	{
		color = lighting(comps.sp.material, w->ligth, comps, s);
	}
	else if (comps.type == 3)
	{
		color = lighting(comps.pl.material, w->ligth, comps, s);
	}
	return (color);
}

t_color	color_at(t_world *w, t_rays r)
{
	t_comps			comps;
	t_color			result_color;
	t_intersection	i;
	int				j;

	i = hit(w, r);
	if (equal(i.t, -1))
		return (get_color(0, 0, 0));
	comps = prepare_computations(i, r);
	result_color = shade_hit(w, comps);
	return (result_color);
}
