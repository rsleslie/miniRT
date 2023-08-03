/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationTuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:29:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 21:33:02 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	compareTuple(t_tuple *tuple_1, t_tuple *tuple_2)
{
	if (!equal(tuple_1->x, tuple_2->x))
		return (FALSE);
	if (!equal(tuple_1->y, tuple_2->y))
		return (FALSE);
	if (!equal(tuple_1->z, tuple_2->z))
		return (FALSE);
	if (!equal(tuple_1->w, tuple_2->w))
		return (FALSE);
	return (TRUE);
}

t_tuple	addingTuple(t_tuple tuple_1, t_tuple tuple_2)
{
	t_tuple result;

	result.x = tuple_1.x + tuple_2.x;
	result.y = tuple_1.y + tuple_2.y;
	result.z = tuple_1.z + tuple_2.z;
	result.w = tuple_1.w + tuple_2.w;
	return (result);
}

t_tuple	subtractingTuple(t_tuple tuple_1, t_tuple tuple_2)
{
	t_tuple result;

	result.x = tuple_1.x - tuple_2.x;
	result.y = tuple_1.y - tuple_2.y;
	result.z = tuple_1.z - tuple_2.z;
	result.w = tuple_1.w - tuple_2.w;
	return (result);
}

t_tuple	multTuple(t_tuple tuple_1, float n)
{
	t_tuple result;

	result.x = tuple_1.x * n;
	result.y = tuple_1.y * n;
	result.z = tuple_1.z * n;
	result.w = tuple_1.w * n;
	return (result);
}

t_tuple	divTuple(t_tuple tuple_1, float n)
{
	t_tuple result;

	result.x = tuple_1.x / n;
	result.y = tuple_1.y / n;
	result.z = tuple_1.z / n;
	result.w = tuple_1.w / n;
	return (result);
}
