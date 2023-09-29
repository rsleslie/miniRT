/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:08:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 14:36:06 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

t_world			world(void);
t_intersection	intersection_world(double n, t_sphere s);
t_xs			*intersections(t_objects *rt, t_rays r, t_xs *xs);
t_xs			*intersect(t_sp sp, t_rays r, t_xs *xs);
t_xs			*local_intersect_pl(t_pl pl, t_rays r, t_xs *xs);
t_xs			*order_xs(t_xs *xs);
t_comps			prepare_computations(t_intersection i, t_rays r);
t_color			shade_hit(t_world *w, t_comps comps);
t_color			color_at(t_world *w, t_rays r);
t_matrices		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_c_world		camera(double hsize, double vsize, double field_of_view);
t_rays			ray_for_pixel(t_c_world camera, double px, double py);
void			render_img(t_c_world c, t_data *data);
t_matrices		view_transform_two(t_tuple from, t_tuple to, t_tuple up);
int				is_shadowed(t_world *w, t_tuple p);
t_intersection	hit(t_world *w, t_rays r);
t_tuple			normal_at_world(t_sp sp, t_tuple p);
t_tuple			local_normal_at(t_pl pl, t_tuple local_point);
t_tuple			normal_at_pl(t_pl pl, t_tuple p);
t_xs			*local_intersect_cyl(t_cy cylinder, t_rays ray, t_xs *xs);
t_tuple			normal_at_cyl(t_cy cylinder, t_tuple point);
int				check_cap(t_rays ray, double t, t_cy cy);
t_xs			*intersect_caps(t_cy cyl, t_rays ray, t_xs *xs);
double			*swap(double *t);
void			world_free(t_world *w);

#endif