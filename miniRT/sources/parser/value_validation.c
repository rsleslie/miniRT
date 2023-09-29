/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:53:09 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 16:09:36 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_range_double(double n, double st, double end)
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

int	validation_double(char *str)
{
	int		pointer;
	size_t	i;

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
	size_t	i;

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
