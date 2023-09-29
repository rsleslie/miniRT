/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:01:47 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 15:51:55 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_comps	init_values_comps(t_comps comps, t_intersection i, t_rays r)
{
	comps.t.t = i.t;
	comps.type = i.type;
	if (i.type == 1)
		comps.sp = i.sp;
	else if (i.type == 3)
		comps.pl = i.pl;
	else if (i.type == 2)
		comps.cy = i.cy;
	comps.point = position(r, comps.t.t);
	comps.eyev = negate(r.direction);
	if (i.type == 1)
		comps.normalv = normal_at_world(comps.sp, comps.point);
	else if (i.type == 3)
		comps.normalv = normal_at_pl(comps.pl, comps.point);
	else if (i.type == 2)
		comps.normalv = normal_at_cyl(comps.cy, comps.point);
	return (comps);
}

t_comps	prepare_computations(t_intersection i, t_rays r)
{
	t_comps	comps;

	comps = (t_comps){0};
	comps = init_values_comps(comps, i, r);
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
	color = (t_color){0};
	if (comps.type == 1)
	{
		color = lighting(comps.sp.material, w->ligth, comps, s);
	}
	else if (comps.type == 3)
	{
		color = lighting(comps.pl.material, w->ligth, comps, s);
	}
	else if (comps.type == 2)
	{
		color = lighting(comps.cy.material, w->ligth, comps, s);
	}
	return (color);
}

t_color	color_at(t_world *w, t_rays r)
{
	t_comps			comps;
	t_color			result_color;
	t_intersection	i;

	i = hit(w, r);
	if (equal(i.t, -1))
		return (get_color(0, 0, 0));
	comps = prepare_computations(i, r);
	result_color = shade_hit(w, comps);
	return (result_color);
}
