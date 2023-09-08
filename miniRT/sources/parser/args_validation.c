/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:18 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/07 20:28:08 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_ambient(char **str)
{
	int		i;
	char	**str_aux;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "A", 2) == 0)
			break ;
	}
	if (!validation_float(str_aux[1])
		|| !validation_range_float(ft_atof(str_aux[1]), 0, 1))
	{
		ft_free_tab(str_aux);
		return (FALSE);
	}
	if (!validation_color(str_aux[2]))
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
	//camera
	// if(!validation_camera(str))
	// 	return(FALSE);
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
