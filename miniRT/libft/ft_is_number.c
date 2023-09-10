/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:49:50 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 17:47:18 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_number(char *str)
{
	int		pointer;
	size_t	i;

	pointer = 0;
	i = -1;
	if (ft_strlen(str) > 10)
		return (0);
	while (++i < ft_strlen(str))
	{
		if (str[i] == '.')
			pointer++;
	}
	if (pointer > 1)
		return (0);
	i = -1;
	while (++i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.')
				continue ;
			return (0);
		}
	}
	return (1);
}
