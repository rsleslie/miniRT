/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_transforming.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:09:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_intersection	hit(t_world *w, t_rays r)
{
	t_intersection	i;
	int				j;
	t_xs			*xs;

	i.t = -1;
	xs = (t_xs *)malloc(sizeof(t_xs));
	xs = intersections(w->rt, r, xs);
	if (xs->count == 0)
		return (i);
	j = -1;
	while (++j < xs->count)
	{
		if (xs->data[j].t > 0)
		{
			i = xs->data[j];
			break ;
		}
		else
			i.t = -1;
	}
	free(xs);
	return (i);
}

t_rays	transform(t_rays r, t_matrices m)
{
	t_rays	r2;

	r2.origin = mult_matrix_tuple(m, r.origin);
	r2.direction = mult_matrix_tuple(m, r.direction);
	return (r2);
}

t_sphere	set_transform(t_sphere s, t_matrices t)
{
	s.transform = mult_matrices(s.transform, t);
	return (s);
}
