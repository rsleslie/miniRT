/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:45:29 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 15:48:03 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	loop_validation_coordinates(char **aux, int i)
{
	int	j;

	j = -1;
	while ((size_t)++j < ft_strlen(aux[i]))
	{
		if (aux[i][j] == '-' || aux[i][j] == '+'
		|| aux[i][j] == '.')
			j++;
		if (!ft_isdigit(aux[i][j]))
		{
			ft_free_tab(aux);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	aux_normalize_vector(char **aux)
{
	if (!validation_range_int(ft_atoi(aux[0]), -1, 1))
	{
		ft_free_tab(aux);
		return (FALSE);
	}
	return (TRUE);
}
