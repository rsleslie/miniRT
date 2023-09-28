/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:57:32 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/28 14:30:58 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

int			compare_tuple(t_tuple t1, t_tuple t2);
int			equal(double a, double b);
double		magnitude(t_tuple tuple);
double		dot(t_tuple t1, t_tuple t2);
t_tuple		point(double x, double y, double z);
t_tuple		vector(double x, double y, double z);
t_tuple		subtracting_point(t_tuple t1, t_tuple t2);
t_tuple		subtracting_vector(t_tuple t1, t_tuple t2);
t_tuple		sub_vec_from_point(t_tuple t1, t_tuple t2);
t_tuple		tuples(double x, double y, double z, double w);
t_tuple		adding_tuple(t_tuple t1, t_tuple t2);
t_tuple		subtracting_tuple(t_tuple t1, t_tuple t2);
t_tuple		negate(t_tuple t1);
t_tuple		div_tuple(t_tuple t1, double n);
t_tuple		mult_tuple(t_tuple t1, double n);
t_tuple		normalize(t_tuple tuple);
t_tuple		cross(t_tuple a, t_tuple b);
int			equal_tuple(t_tuple t1, t_tuple t2);

#endif