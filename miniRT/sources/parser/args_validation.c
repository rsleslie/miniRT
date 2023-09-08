/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:18 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/08 16:27:22 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_coordinates(char *str)
{
	char	**aux;
	int		i;
	int		j;
	
	i = -1;
	aux = ft_split(str, ',');
	if (ft_tab_len(aux) != 3)
		return (FALSE);
	while (++i < ft_tab_len(aux))
	{
		j = -1;
		while (++j < ft_strlen(aux[i]))
		{
			if (aux[i][j] == '-' || aux[i][j] == '+'
			|| aux[i][j] == '.')
				j++;
			if (!ft_isdigit(aux[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	validation_normalize_vector(char *str)
{
	char **aux;

	aux = ft_split(str, ',');
	if (!validation_int(aux[0]))
		return (FALSE);
	if (!validation_int(aux[1]))
		return (FALSE);
	if (!validation_int(aux[2]))
		return (FALSE);
	if (!validation_range_int(ft_atoi(aux[0]), -1, 1))
		return (FALSE);
	if (!validation_range_int(ft_atoi(aux[1]), -1, 1))
		return (FALSE);
	if (!validation_range_int(ft_atoi(aux[2]), -1, 1))
		return (FALSE);
	return (TRUE);
}

int	validation_args(char **str)
{
	if (!validation_ambient(str))
		return (FALSE);
	//camera
	if(!validation_camera(str))
		return(FALSE);
	// //ligth
	// if (!validation_ligth(str))
	// 	return (FALSE);
	// //sphere
	// if (!validation_sphere(str))
	// 	return (FALSE);
	// //plane
	// if (!validation_plane(str))
	// 	return (FALSE);
	// //cylinder
	// if (!validation_cylinder(str))
	// 	return (FALSE);
	return (TRUE);
}
