/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:28:31 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 15:58:12 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "world.h"
# include "object.h"
# include "tuple.h"

t_rays			ray(t_tuple origin, t_tuple direction);
t_tuple			position(t_rays r, double t);
t_sphere		sphere(double ray);
double			discriminant(double a, double b, double c);
t_rays			transform(t_rays r, t_matrices m);
t_sphere		set_transform(t_sphere s, t_matrices t);
t_tuple			normal_at(t_sp s, t_tuple p);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_l				point_light(t_tuple	position, t_color intensity);
t_m				material(void);
t_color			lighting(t_m m, t_l light, t_comps comps, int in_shadow);

#endif
