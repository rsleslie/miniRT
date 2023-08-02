/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:59:53 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 19:05:00 by rleslie-         ###   ########.fr       */
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

int	equal(float	a, float b)
{
	const float	EPSILON = 0.00001;
	if (fabsf(a - b) < EPSILON)
	{
		return (TRUE);
	}
	return (FALSE);
}
