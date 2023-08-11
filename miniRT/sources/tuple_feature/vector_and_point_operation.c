/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationVectorPoint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:31:35 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 23:31:45 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	point(float x, float y, float z)
{
	return (tuples(x, y, z, 1));
}

t_tuple	vector(float x, float y, float z)
{
	return (tuples(x, y, z, 0));
}

t_tuple	subtracting_point(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	result.w = t1.w - t2.w;
	return (result);
}

t_tuple	subtracting_vector(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	result.w = t1.w - t2.w;
	return (result);
}

t_tuple	sub_vec_from_point(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	return (point(result.x, result.y, result.z));
}
