/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:26:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/21 15:47:05 by rleslie-         ###   ########.fr       */
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
	t_matrices	id;
	t_matrices	transpose;
	t_matrices	transform;
	t_m			material;
}	t_sphere;

typedef struct s_intersection
{
	double		t;
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
t_tuple			position(t_rays r, double t);
t_sphere		sphere(void);
t_intersection	hit(t_xs xs);
// t_intersection	intersection(double n, t_sphere s);
t_intersection	intersection(double n, t_sp s);
t_rays			transform(t_rays r, t_matrices m);
t_sphere		set_transform(t_sphere s, t_matrices t);
t_tuple			normal_at(t_sp s, t_tuple p);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_l				point_light(t_tuple	position, t_color intensity);
t_m				material(void);
t_color			lighting(t_m m, t_l light, t_tuple position, t_tuple eyev, t_tuple normalv);

#endif
