/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:26:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/12 16:20:35 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "tuple.h"
# include "object.h"

typedef struct s_rays
{
	t_tuple	origin;
	t_tuple	direction;
}	t_rays;

typedef struct s_sphere
{
	int			radius;
	t_matrices	transform;
}	t_sphere;

typedef struct s_intersection
{
	float		t;
	t_sp	object;
}	t_intersection;

typedef struct s_xs
{
	int				count;
	t_intersection	data[1024];
}	t_xs;

// t_xs			intersect(t_sphere s, t_rays r);
t_xs 			teste_intesections(t_objects *rt, t_rays r);
t_xs			intersect(t_sp sp, t_rays r, t_xs xs);
t_xs			intersections(t_intersection i1, t_xs xs);
t_rays			ray(t_tuple origin, t_tuple direction);
t_tuple			position(t_rays r, float t);
t_sphere		sphere();
t_intersection	hit(t_xs xs);
// t_intersection	intersection(float n, t_sphere s);
t_intersection	intersection(float n, t_sp s);
t_rays			transform(t_rays r, t_matrices m);
t_sphere		set_transform(t_sphere s, t_matrices t);

#endif
