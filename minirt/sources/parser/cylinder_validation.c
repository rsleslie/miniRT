/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:23:28 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validation_cylinder(char **str)
{
	if (!validation_coordinates(str[1]))
		return (FALSE);
	if (!validation_coordinates(str[2]))
		return (FALSE);
	if (!validation_normalize_vector(str[2]))
		return (FALSE);
	if (!is_number(str[3]))
		return (FALSE);
	if (!is_number(str[4]))
		return (FALSE);
	if (!validation_color(str[5]))
		return (FALSE);
	return (TRUE);
}

int	validation_multiples_cylinder(char **str)
{
	int		i;
	char	**str_aux;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "cy", 3) == 0)
		{
			if (!validation_cylinder(str_aux))
			{
				ft_free_tab(str_aux);
				return (FALSE);
			}
		}
	}
	ft_free_tab(str_aux);
	return (TRUE);
}
