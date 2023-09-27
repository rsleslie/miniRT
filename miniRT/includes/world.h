/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:08:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 15:33:59 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H



t_world	        world(void);
t_world	        default_world(void);
// t_xs	        (t_sphere sp, t_rays r, t_xs xs);
// t_xs	        intersections_world(t_world w, t_rays r);
t_xs	        order_xs(t_xs xs);
t_intersection	intersection_world(double n, t_sphere s);
t_comps	        prepare_computations(t_intersection i, t_rays r);
t_color	        shade_hit(t_world *w, t_comps comps);
t_color	        color_at(t_world *w, t_rays r);
t_matrices	    view_transform(t_tuple from, t_tuple to, t_tuple up);
t_c_world	    camera(double hsize, double vsize, double field_of_view);
t_rays	        ray_for_pixel(t_c_world camera, double px, double py);
void            render_img(t_c_world c, t_world *w);
t_matrices	    view_transform_two(t_tuple from, t_tuple to, t_tuple up);
//plane
t_xs	        local_intersect(t_pl pl, t_rays r, t_xs xs);
int             is_shadowed(t_world *w, t_tuple p);

#endif