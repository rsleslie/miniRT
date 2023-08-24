/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:26:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/17 16:23:40 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "tuple.h"

typedef struct s_rays
{
	t_tuple	origin;
	t_tuple	direction;
}	t_rays;

typedef struct s_sphere
{
	int	radius;
}	t_sphere;

typedef struct s_intersection
{
	float		t;
	t_sphere	object;
}	t_intersection;

typedef struct s_xs
{
	int				count;
	t_intersection	data[2];
}	t_xs;

t_rays		ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_rays r, float t);
t_sphere	sphere();
t_xs		intersect(t_sphere s, t_rays r);

t_intersection	intersection(float n, t_sphere s);
t_xs	intersections(t_intersection i1, t_intersection i2);
// t_xs	intersections(t_intersection i, ...);

#endif
