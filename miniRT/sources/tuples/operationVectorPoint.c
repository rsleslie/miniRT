/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationVectorPoint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:31:35 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 19:10:27 by rleslie-         ###   ########.fr       */
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

t_tuple	subtractingPoint(t_tuple tuple_1, t_tuple tuple_2)
{
	t_tuple result;
	
	result.x = tuple_1.x - tuple_2.x;
	result.y = tuple_1.y - tuple_2.y;
	result.z = tuple_1.z - tuple_2.z;
	result.w = tuple_1.w - tuple_2.w;
	return (result);
}

t_tuple	subtractingVector(t_tuple tuple_1, t_tuple tuple_2)
{
	t_tuple result;
	
	result.x = tuple_1.x - tuple_2.x;
	result.y = tuple_1.y - tuple_2.y;
	result.z = tuple_1.z - tuple_2.z;
	result.w = tuple_1.w - tuple_2.w;
	return (result);
}

t_tuple	subtractingVecFromPoint(t_tuple tuple_1, t_tuple tuple_2)
{
	t_tuple result;
	
	result.x = tuple_1.x - tuple_2.x;
	result.y = tuple_1.y - tuple_2.y;
	result.z = tuple_1.z - tuple_2.z;
	
	return (point(result.x, result.y, result.z));
}