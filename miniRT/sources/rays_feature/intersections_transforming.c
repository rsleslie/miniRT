/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_transforming.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:09:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/26 16:23:19 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_intersection	intersection(double n, t_sp s)
{
	t_intersection	t;

	t.t = n;
	t.sp = s;
	return (t);
}

// t_xs	intersections_i(t_intersection i1, t_xs xs)
// {	
// 	xs.data[xs.count].t = i1.t;
// 	xs.data[xs.count].object = i1.object;
// 	xs.count++;
// 	return (xs);
// }

t_intersection	hit(t_xs xs)
{
	// int				i;
	// t_intersection	x;
	t_intersection	result;

	// i = 0;
	// result.t = -1;
	// while (i < xs.count)
	// {
	// 	if (xs.data[i].t > 0)
	// 	{
	// 		if (equal(result.t, -1))
	// 		{
	// 			result = xs.data[i];
	// 		}
	// 		else if (xs.data[i].t < result.t)
	// 			result = xs.data[i];
	// 	}
	// 	i++;
	// }
	// if (result.t <= 0)
	// {
	// 	result.t = -1; 
	// 	return (result);
	// }
	result = xs.data[0];
	return (result);
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
