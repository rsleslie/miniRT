/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:45:07 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:04 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	transform_number(const char *str, size_t i)
{
	float	j;
	float	result;
	float	aux;

	j = 0.1;
	aux = 0;
	result = 0;
	while (i < ft_strlen(str) && ft_isdigit(str[i]))
	{
		result = aux + (str[i] - '0');
		aux = result * 10.0;
		i++;
	}
	while (++i < ft_strlen(str) && ft_isdigit(str[i]))
	{
		aux = (str[i] - '0') * j;
		result += aux;
		j = j / 10;
	}
	return (result);
}

float	ft_atof(const char *str)
{
	size_t	i;
	int		signal;
	float	result;

	i = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * (-1);
		i++;
	}
	result = transform_number(str, i);
	return (result * signal);
}
