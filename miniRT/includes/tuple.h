/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:57:32 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 13:47:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct t_project
{
	t_tuple position;
	t_tuple velocity;
}	t_project;

typedef struct s_env
{
	t_tuple gravity;
	t_tuple wind;
}	t_env;

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
t_env		environment(t_tuple v1, t_tuple v2);
t_project	projectile(t_tuple p, t_tuple v);
t_project	tick(t_env env, t_project proj);
int 		equal_tuple(t_tuple t1, t_tuple t2);

#endif