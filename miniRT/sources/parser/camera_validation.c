/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:24:55 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 17:57:08 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_camera(char **str)
{
	int		i;
	char	**str_aux;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "C", 2) == 0)
			break ;
	}
	if (!validation_coordinates(str_aux[1]))
		return (FALSE);
	if (!validation_coordinates(str_aux[2]))
		return (FALSE);
	if (!validation_int(str_aux[3]))
		return (FALSE);
	if (!validation_range_int(ft_atoi(str_aux[3]), 0, 180))
		return (FALSE);
	if (!validation_normalize_vector(str_aux[2]))
		return (FALSE);
	ft_free_tab(str_aux);
	return (TRUE);
}
