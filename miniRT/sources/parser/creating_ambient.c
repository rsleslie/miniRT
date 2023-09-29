/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:05:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 16:32:00 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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
	camera.fov = ft_atoi(aux[3]) * (PI / 180.0);
	ft_free_tab(aux);
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
	ft_free_tab(aux);
	return (ligth);
}

t_a	create_ambient(char **a)
{
	t_a		ambient;
	int		i;
	char	**aux;

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
