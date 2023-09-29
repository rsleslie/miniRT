/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:30:51 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validation_color(char *str)
{
	char	**color;
	int		i;

	i = -1;
	color = ft_split(str, ',');
	if (ft_tab_len(color) != 3)
	{
		ft_free_tab(color);
		return (FALSE);
	}
	if (!validation_int(color[0]) || !validation_int(color[1])
		|| !validation_int(color[2]))
	{
		ft_free_tab(color);
		return (FALSE);
	}
	if (!validation_range_int(ft_atoi(color[0]), 0, 255)
		|| !validation_range_int(ft_atoi(color[1]), 0, 255)
		|| !validation_range_int(ft_atoi(color[2]), 0, 255))
	{
		ft_free_tab(color);
		return (FALSE);
	}
	ft_free_tab(color);
	return (TRUE);
}
