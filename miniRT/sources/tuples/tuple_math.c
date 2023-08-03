/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:42:44 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 22:51:16 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

float	magnitude(t_tuple tuple)
{
	t_tuple	magTuple;
	float		numberMagnitude;

	magTuple.x = pow(tuple.x, 2);
	magTuple.y = pow(tuple.y, 2);
	magTuple.z = pow(tuple.z, 2);
	magTuple.w = pow(tuple.w, 2);
	numberMagnitude = sqrt((magTuple.x + magTuple.y + magTuple.z + magTuple.w));
	return (numberMagnitude);
}

t_tuple normalize(t_tuple tuple)
{
	t_tuple	newTuple;
	float	numberMagnitude;

	numberMagnitude = magnitude(tuple);
	newTuple.x = tuple.x / numberMagnitude;
	newTuple.y = tuple.y / numberMagnitude;
	newTuple.z = tuple.z / numberMagnitude;
	newTuple.w = tuple.w / numberMagnitude;
	return (newTuple);		
}
