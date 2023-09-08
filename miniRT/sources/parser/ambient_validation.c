/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:04 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/08 16:27:27 by rleslie-         ###   ########.fr       */
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
