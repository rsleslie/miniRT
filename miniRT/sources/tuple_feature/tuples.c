/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:59:53 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 13:47:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	tuples(double x, double y, double z, double w)
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
	t_tuple	negate_tuple;

	negate_tuple.x = tuple_1.x * (-1);
	negate_tuple.y = tuple_1.y * (-1);
	negate_tuple.z = tuple_1.z * (-1);
	negate_tuple.w = tuple_1.w * (-1);
	return (negate_tuple);
}

int	equal(double a, double b)
{
	if (fabsf(a - b) < EPSILON)
	{
		return (TRUE);
	}
	return (FALSE);
}
