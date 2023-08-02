/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationTuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:29:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 20:22:11 by rleslie-         ###   ########.fr       */
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

t_tuple	negate(t_tuple tuple_1)
{
	t_tuple negateTuple;
	
	negateTuple.x = tuple_1.x * (-1);
	negateTuple.y = tuple_1.y * (-1);
	negateTuple.z = tuple_1.z * (-1);
	negateTuple.w = tuple_1.w * (-1);
	return (negateTuple);
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

