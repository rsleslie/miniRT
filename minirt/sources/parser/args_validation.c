/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:18 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 18:01:46 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validation_coordinates(char *str)
{
	char	**aux;
	int		i;

	i = -1;
	aux = ft_split(str, ',');
	if (ft_tab_len(aux) != 3)
	{
		ft_free_tab(aux);
		return (FALSE);
	}
	while (++i < ft_tab_len(aux))
	{
		if (!loop_validation_coordinates(aux, i))
			return (FALSE);
	}
	ft_free_tab(aux);
	return (TRUE);
}

int	validation_normalize_vector(char *str)
{
	char	**aux;
	int		i;

	i = -1;
	aux = ft_split(str, ',');
	if (!validation_range_double(ft_atof(aux[0]), -1, 1))
		return (FALSE);
	if (!validation_range_double(ft_atof(aux[1]), -1, 1))
		return (FALSE);
	if (!validation_range_double(ft_atof(aux[2]), -1, 1))
		return (FALSE);
	if (!equal(magnitude(vector(ft_atof(aux[0]), ft_atof(aux[1]), ft_atof(aux[2]))), 1))
		return (FALSE);
	ft_free_tab(aux);
	return (TRUE);
}

int	validation_ligth(char **str)
{
	int		i;
	char	**str_aux;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "L", 2) == 0)
			break ;
	}
	if (!validation_coordinates(str_aux[1]) || !validation_color(str_aux[3]))
	{
		ft_free_tab(str_aux);
		return (FALSE);
	}
	if (!validation_double(str_aux[2])
		|| !validation_range_double(ft_atof(str_aux[2]), 0, 1))
	{
		ft_free_tab(str_aux);
		return (FALSE);
	}
	ft_free_tab(str_aux);
	return (TRUE);
}

int	validation_args(char **str)
{
	if (!validation_ambient(str))
		return (FALSE);
	if (!validation_camera(str))
		return (FALSE);
	if (!validation_ligth(str))
		return (FALSE);
	if (!validation_multiples_sphere(str))
		return (FALSE);
	if (!validation_multiples_plane(str))
		return (FALSE);
	if (!validation_multiples_cylinder(str))
		return (FALSE);
	return (TRUE);
}
