/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:42:44 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/03 17:26:04 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

float	magnitude(t_tuple tuple)
{
	t_tuple	mag_tuple;
	float	num_magnitude;

	mag_tuple.x = pow(tuple.x, 2);
	mag_tuple.y = pow(tuple.y, 2);
	mag_tuple.z = pow(tuple.z, 2);
	mag_tuple.w = pow(tuple.w, 2);
	num_magnitude = sqrt((mag_tuple.x + mag_tuple.y + mag_tuple.z
				+ mag_tuple.w));
	return (num_magnitude);
}

t_tuple	normalize(t_tuple tuple)
{
	t_tuple	new_tuple;
	float	num_magnitude;

	num_magnitude = magnitude(tuple);
	new_tuple.x = tuple.x / num_magnitude;
	new_tuple.y = tuple.y / num_magnitude;
	new_tuple.z = tuple.z / num_magnitude;
	new_tuple.w = tuple.w / num_magnitude;
	return (new_tuple);
}

float	dot(t_tuple t1, t_tuple t2)
{
	float	product;

	product = ((t1.x * t2.x) + (t1.y * t2.y) + (t1.z * t2.z) + (t1.w * t2.w));
	return (product);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	new_vector;

	new_vector = vector((a.y * b.z - a.z * b.y),
			(a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));
	return (new_vector);
}
