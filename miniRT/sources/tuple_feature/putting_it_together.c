/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putting_it_together.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:45:39 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/11 14:01:08 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_project	projectile(t_tuple p, t_tuple v)
{
    t_project proj;

	proj.position = p;
	proj.velocity = v;
	return (proj);
}

t_env	environment(t_tuple v1, t_tuple v2)
{
	t_env env;
	
	env.gravity = v1;
	env.wind = v2;

	return (env);
}

t_project	tick(t_env env, t_project proj)
{
	t_project	p;

	p.position = adding_tuple(proj.velocity, proj.position);
	p.velocity = adding_tuple(adding_tuple(proj.velocity, env.gravity),env.gravity);
	return (p);
}