/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:57:54 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/08 17:58:26 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_sphere(char **str)
{
	if (!validation_coordinates(str[1]))
		return (FALSE);
	if (!is_number(str[2]))
		return (FALSE);
	if(!validation_color(str[3]))
		return (FALSE);
	return (TRUE);
}

int	validation_multiples_sphere(char **str)
{
	int		i;
	char	**str_aux;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "sp", 3) == 0)
		{
			if(!validation_sphere(str_aux))
			{
				ft_free_tab(str_aux);
				return (FALSE);
			}
		}
	}
	ft_free_tab(str_aux);
	return (TRUE);
}
