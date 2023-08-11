/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:57:32 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/10 16:59:33 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

int		compare_tuple(t_tuple *t1, t_tuple *t2);
int		equal(float a, float b);
float	magnitude(t_tuple tuple);
float	dot(t_tuple t1, t_tuple t2);
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple	subtracting_point(t_tuple t1, t_tuple t2);
t_tuple	subtracting_vector(t_tuple t1, t_tuple t2);
t_tuple	sub_vec_from_point(t_tuple t1, t_tuple t2);
t_tuple	tuples(float x, float y, float z, float w);
t_tuple	adding_tuple(t_tuple t1, t_tuple t2);
t_tuple	subtracting_tuple(t_tuple t1, t_tuple t2);
t_tuple	negate(t_tuple t1);
t_tuple	div_tuple(t_tuple t1, float n);
t_tuple	mult_tuple(t_tuple t1, float n);
t_tuple	normalize(t_tuple tuple);
t_tuple	cross(t_tuple a, t_tuple b);

#endif