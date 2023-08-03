/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:33:32 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/02 23:13:19 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define FALSE 0
# define TRUE 1

#include "../libft/libft.h"
#include <math.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

// create pointer and vector
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);

// vector and pointer operation
t_tuple	subtractingPoint(t_tuple tuple_1, t_tuple tuple_2);
t_tuple	subtractingVector(t_tuple tuple_1, t_tuple tuple_2);
t_tuple	subtractingVecFromPoint(t_tuple tuple_1, t_tuple tuple_2);
int		equal(float	a, float b);

//tuple
t_tuple	tuples(float x, float y, float z, float w);

// tuple operation
int		compareTuple(t_tuple *tuple_1, t_tuple *tuple_2);
float	magnitude(t_tuple tuple);
t_tuple	addingTuple(t_tuple tuple_1, t_tuple tuple_2);
t_tuple	subtractingTuple(t_tuple tuple_1, t_tuple tuple_2);
t_tuple	negate(t_tuple tuple_1);
t_tuple	divTuple(t_tuple tuple_1, float n);
t_tuple	multTuple(t_tuple tuple_1, float n);
t_tuple normalize(t_tuple tuple);
float	dot(t_tuple t1, t_tuple t2);
t_tuple	cross(t_tuple a, t_tuple b);



#endif