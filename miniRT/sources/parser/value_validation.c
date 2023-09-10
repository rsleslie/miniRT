/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:53:09 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 18:53:03 by rleslie-         ###   ########.fr       */
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
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] == '.')
			pointer++;
		if (pointer > 1)
			return (FALSE);
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
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}
