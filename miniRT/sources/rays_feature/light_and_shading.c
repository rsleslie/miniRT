/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:54:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 15:46:24 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	normal_at(t_sphere s, t_tuple p)
{
	t_tuple	v;
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mult_matrix_tuple(inverse(s.transform), p);
	object_normal = subtracting_point(object_point, point(0, 0, 0));
	world_normal = mult_matrix_tuple(transpose(inverse(s.transform)), object_normal);
	world_normal.w = 0;
	return (normalize(world_normal));
}
