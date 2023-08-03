/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:59:53 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 21:33:06 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	tuples(float x, float y, float z, float w)
{
	t_tuple	data;
	data.x = x;
	data.y = y;
	data.z = z;
	data.w = w;
	return (data);
}

t_tuple	negate(t_tuple tuple_1)
{
	t_tuple negateTuple;

	negateTuple.x = tuple_1.x * (-1);
	negateTuple.y = tuple_1.y * (-1);
	negateTuple.z = tuple_1.z * (-1);
	negateTuple.w = tuple_1.w * (-1);
	return (negateTuple);
}

int	equal(float	a, float b)
{
	const float	EPSILON = 0.00001;
	if (fabsf(a - b) < EPSILON)
	{
		return (TRUE);
	}
	return (FALSE);
}
