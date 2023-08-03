/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:29:30 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 23:34:52 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	compare_tuple(t_tuple *t1, t_tuple *t2)
{
	if (!equal(t1->x, t2->x))
		return (FALSE);
	if (!equal(t1->y, t2->y))
		return (FALSE);
	if (!equal(t1->z, t2->z))
		return (FALSE);
	if (!equal(t1->w, t2->w))
		return (FALSE);
	return (TRUE);
}

t_tuple	adding_tuple(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x + t2.x;
	result.y = t1.y + t2.y;
	result.z = t1.z + t2.z;
	result.w = t1.w + t2.w;
	return (result);
}

t_tuple	subtracting_tuple(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	result.w = t1.w - t2.w;
	return (result);
}

t_tuple	mult_tuple(t_tuple t1, float n)
{
	t_tuple	result;

	result.x = t1.x * n;
	result.y = t1.y * n;
	result.z = t1.z * n;
	result.w = t1.w * n;
	return (result);
}

t_tuple	div_tuple(t_tuple t1, float n)
{
	t_tuple	result;

	result.x = t1.x / n;
	result.y = t1.y / n;
	result.z = t1.z / n;
	result.w = t1.w / n;
	return (result);
}
