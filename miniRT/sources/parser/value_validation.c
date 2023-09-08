/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:53:09 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/07 21:31:47 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_range_float(float n, float st, float end)
{
	if (n >= st && n <= end)
		return (TRUE);
	return (FALSE);
}

int	validation_range_int(int num, int start, int end)
{
	if (num >= start && num <= end)
		return (TRUE);
	return (FALSE);
}

int	validation_float(char *str)
{
	int	pointer;
	int	i;

	pointer = 0;
	i = -1;
	if (ft_strlen(str) > 7)
		return (FALSE);
	while (++i < ft_strlen(str))
	{
		if (str[i] == '.')
			pointer++;
	}
	if (pointer != 1)
		return (FALSE);
	i = -1;
	while (++i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.')
				continue ;
			return (FALSE);
		}
	}
	return (TRUE);
}

int	validation_int(char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) > 10)
		return (FALSE);
	while (++i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}

int	validation_color(char *str)
{
	char	**color;
	int		pointer;
	int		i;

	i = -1;
	pointer = 0;
	while (++i < ft_strlen(str))
	{
		if (str[i] == ',')
			pointer++;
	}
	if (pointer != 2)
		return (FALSE);
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
