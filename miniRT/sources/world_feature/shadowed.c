/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:16:23 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/28 14:44:23 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	*swap(double *t)
{
	double	temp;

	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
	return (t);
}

int	is_shadowed(t_world *w, t_tuple p)
{
	t_tuple			v;
	t_tuple			direction;
	double			distance;
	t_rays			r;
	t_intersection	i;

	v = subtracting_tuple(w->ligth.position, p);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray(p, direction);
	i = hit(w, r);
	if (i.t == -1)
		return (FALSE);
	if (i.t < distance)
		return (TRUE);
	else
		return (FALSE);
}
