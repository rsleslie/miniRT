/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:20:10 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 17:06:14 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	normal_at(t_sp s, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(s.inverse, p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(s.transpose, object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}

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