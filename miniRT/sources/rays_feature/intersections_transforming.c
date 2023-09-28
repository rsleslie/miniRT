/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_transforming.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:09:52 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 22:01:28 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_intersection	intersection(double n, t_sp s)
{
	t_intersection	t;

	t.t = n;
	t.sp = s;
	return (t);
}


t_xs    *test_order_xs(t_xs *xs)
{
    t_xs    *order = malloc(sizeof(t_xs));
    int        counter;
    int        i;
    int        j;

    order->count = xs->count;
    i = -1;
    counter = 0;
    while (++i < xs->count)
    {
        j = 0;
        counter = 0;
        while(j < xs->count)
        {
            if (xs->data[i].t > xs->data[j].t)
                counter++;
            j++;
        }    
        order->data[counter] = xs->data[i];
    }
    free(xs);
    return (order);
}

t_xs    *teste_local_intersect(t_pl pl, t_rays r, t_xs *xs)
{
    t_tuple    sphere_to_ray;

    if (fabs(r.direction.y) < EPSILON)
        return (xs);
    else
    {
        xs->count += 1;
        xs->data[xs->count - 1].t = (-r.origin.y) / r.direction.y;
        xs->data[xs->count -1].pl = pl;
        xs->data[xs->count -1].type = 3;
    }
    return (xs);
}


t_xs    *teste_intersect(t_sp sp, t_rays r, t_xs *xs)
{
    t_tuple    sphere_to_ray;
    float    a;
    float    b;
    float    c;

    r = transform(r, sp.inverse);
    sphere_to_ray = subtracting_tuple(r.origin, point(0, 0, 0));
    a = dot(r.direction, r.direction);
    b = 2 * dot(r.direction, sphere_to_ray);
    c = dot(sphere_to_ray, sphere_to_ray) - 1;
    if (discriminant(a, b, c) < 0)
        return (xs);
    else
    {
        xs->count += 2;
        xs->data[xs->count - 1].t = ((-b - sqrt(discriminant(a, b, c))) / (2 * a));
        xs->data[xs->count - 2].t = ((-b + sqrt(discriminant(a, b, c))) / (2 * a));
        xs->data[xs->count -1].type = 1;
        xs->data[xs->count  - 2].type = 1;
        xs->data[xs->count -1].sp = sp;
        xs->data[xs->count  - 2].sp = sp;
    }
    return (xs);
}

t_xs *test_intersections(t_objects *rt, t_rays r, t_xs *xs)
{
    t_xs    *order;
    int        i;

    i = -1;
    xs->count = 0;
    while (++i < rt->n_sp)
        xs = teste_intersect(rt->sp[i], r, xs);
    i = -1;
    while (++i < rt->n_pl)
        xs = teste_local_intersect(rt->pl[i], r, xs);
     i = -1;
    while (++i < rt->n_cy)
        xs = local_intersect_cyl(rt->cy[i], r, xs);
    i = -1;
    while (++i < rt->n_cy)
        xs = intersect_caps(rt->cy[i], r, xs);
    order = test_order_xs(xs);
    return (order);
}

t_intersection	hit(t_world *w, t_rays r)
{
	t_intersection	i;
	int				j;
	t_xs     *xs = malloc(sizeof(t_xs));

	i.t = -1;
	xs = test_intersections(w->rt, r, xs);
	if (xs->count == 0)
		return (i);
	j = -1;
	while (++j < xs->count)
	{
		if (xs->data[j].t > 0)
		{
			i = xs->data[j];
			break ;
		}
		else
			i.t = -1;
	}
    free(xs);
	return (i);
}

t_rays	transform(t_rays r, t_matrices m)
{
	t_rays	r2;

	r2.origin = mult_matrix_tuple(m, r.origin);
	r2.direction = mult_matrix_tuple(m, r.direction);
	return (r2);
}

t_sphere	set_transform(t_sphere s, t_matrices t)
{
	s.transform = mult_matrices(s.transform, t);
	return (s);
}
