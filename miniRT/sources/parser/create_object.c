/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:04:38 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/27 11:56:02 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	calloc_obj(char **args, t_objects **rt)
{
	if (counter_obj("sp", args) > 0)
	{
		(*rt)->n_sp = counter_obj("sp", args);
		(*rt)->sp = ft_calloc(sizeof(t_sp), counter_obj("sp", args));
	}
	else
		(*rt)->n_sp = 0;
	if (counter_obj("pl", args) > 0)
	{
		(*rt)->n_pl = counter_obj("pl", args);
		(*rt)->pl = ft_calloc(sizeof(t_pl), counter_obj("pl", args));
	}
	else
		(*rt)->n_pl = 0;
	if (counter_obj("cy", args) > 0)
	{
		(*rt)->n_cy = counter_obj("cy", args);
		(*rt)->cy = ft_calloc(sizeof(t_cy), counter_obj("cy", args));
	}
	else
		(*rt)->n_cy = 0;
}

t_color	color_obj(char *str)
{
	t_color	color;
	char	**aux;

	aux = ft_split(str, ',');
	color = get_color((double)ft_atof(aux[0]),
			(double)ft_atof(aux[1]), (double)ft_atof(aux[2]));
	ft_free_tab(aux);
	return (color);
}

t_tuple	get_coordenates(char *args)
{
	char	**aux;
	t_tuple	p;

	aux = ft_split(args, ',');
	p = point(ft_atof(aux[0]), ft_atof(aux[1]), ft_atof(aux[2]));
	ft_free_tab(aux);
	return (p);
}

t_tuple	get_vector(char *args)
{
	char	**aux;
	t_tuple	vec;

	aux = ft_split(args, ',');
	vec = vector(ft_atof(aux[0]), ft_atof(aux[1]), ft_atof(aux[2]));
	ft_free_tab(aux);
	return (vec);
}

void	create_object(t_objects **rt, char **args)
{
	t_a	ambient_str;

	calloc_obj(args, rt);
	(*rt)->a = create_ambient(args);
	(*rt)->c = create_camera(args);
	(*rt)->l = create_ligth(args);
	create_sp(rt, args);
	create_plane(rt, args);
	create_cy(rt, args);
}
