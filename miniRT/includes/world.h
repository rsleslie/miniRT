/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:08:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/25 19:33:04 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct s_world
{
    t_sphere	s1;
    t_sphere	s2;
    t_l			ligth;
}	t_world;

typedef struct  s_comps
{
    t_intersection  t;
    t_sphere        object;
    t_tuple         point;
    t_tuple         eyev;
    t_tuple         normalv;
    int             inside;
}   t_comps;

typedef struct s_c_world
{
    t_color     color;
    double      hsize;
    double      vsize;
    double      field_of_view;
    double      pixel_size;
    double      half_width;
    double      half_height;
    t_matrices  transform;
}   t_c_world;

t_world	        world(void);
t_world	        default_world(void);
t_xs	        intersect_world(t_sphere sp, t_rays r, t_xs xs);
t_xs	        intersections_world(t_world w, t_rays r);
t_xs	        order_xs(t_xs xs);
t_intersection	intersection_world(double n, t_sphere s);
t_comps	        prepare_computations(t_intersection i, t_rays r);
t_color	        shade_hit(t_world w, t_comps comps);
t_color	        color_at(t_world w, t_rays r);
t_matrices	    view_transform(t_tuple from, t_tuple to, t_tuple up);
t_c_world	    camera(double hsize, double vsize, double field_of_view);
t_rays	        ray_for_pixel(t_c_world camera, double px, double py);
t_canvas        render_img(t_c_world c, t_world w);

#endif