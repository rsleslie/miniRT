/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:04:38 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 16:47:33 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	counter_obj(char *obj, char **args)
{
	int		i;
	int		counter;
	char	**aux;

	i = -1;
	counter = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], obj, ft_strlen(obj)) == 0)
			counter++;
	}
	ft_free_tab(aux);
	return (counter);
}

int	calloc_obj(char **args, t_objects **rt)
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

t_a	create_ambient(char **a)
{
	t_a	ambient;
	int		i;
	char	**aux;
	char	**color;
	
	i = -1;
	aux = NULL;
	while (++i < ft_tab_len(a))
	{
		ft_free_tab(aux);
		aux = ft_split(a[i], 32);
		if (ft_strncmp(aux[0], "A", 2) == 0)
			break ;
	}
	ambient.ratio = ft_atof(aux[1]);
	ambient.color = color_obj(aux[2]);
	ft_free_tab(aux);
	return (ambient);	
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

t_c	create_camera(char **args)
{
	int		i;
	char	**aux;
	t_c		camera;

	i = -1;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "C", 2) == 0)
			break ;
	}
	camera.coordinates = get_coordenates(aux[1]);
	camera.vector = get_vector(aux[2]);
	camera.fov = ft_atoi(aux[3]);
	return (camera);
}

t_l	create_ligth(char **args)
{
	int		i;
	char	**aux;
	t_l		ligth;

	i = -1;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "L", 2) == 0)
			break ;
	}
	ligth.coordinates = get_coordenates(aux[1]);
	ligth.brightness = ft_atof(aux[2]);
	ligth.color = color_obj(aux[3]);
	return (ligth);
}

t_sp	add_sp(char **str)
{
	t_sp	sp;

	sp.coordinates = get_coordenates(str[1]);
	sp.diameter = ft_atof(str[2]);
	sp.color = color_obj(str[3]);
	return (sp);	
}

void	create_sp(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		
		if (ft_strncmp(aux[0], "sp", 3) == 0)
		{
			(*rt)->sp[j] = add_sp(aux);
			j++;	
		}
	}
	ft_free_tab(aux);
}

t_pl	add_pl(char **str)
{
	t_pl	pl;

	pl.coordinates = get_coordenates(str[1]);
	pl.vector = get_vector(str[2]);
	pl.color = color_obj(str[3]);
	return (pl);	
}

void	create_plane(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "pl", 3) == 0)
		{
			(*rt)->pl[j] = add_pl(aux);
			j++;	
		}
	}
	ft_free_tab(aux);
}


t_cy	add_cy(char **str)
{
	t_cy	cy;

	cy.coordinates = get_coordenates(str[1]);
	cy.vector = get_vector(str[2]);
	cy.diameter = ft_atof(str[3]);
	cy.heigth = ft_atof(str[4]);
	cy.color = color_obj(str[5]);
	return (cy);	
}

void	create_cy(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "cy", 3) == 0)
		{
			(*rt)->cy[j] = add_cy(aux);
			j++;	
		}
	}
	ft_free_tab(aux);
}

t_objects	create_object(t_objects **rt, char **args)
{
	t_a 	ambient_str;
	
	calloc_obj(args, rt);
	(*rt)->a = create_ambient(args);
	(*rt)->c = create_camera(args);
	(*rt)->l = create_ligth(args);
	create_sp(rt, args);
	create_plane(rt, args);
	// create_cy(rt, args);
}
