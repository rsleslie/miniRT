/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:33:01 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/28 14:33:04 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_double(char *str)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(str))
	{
		if (str[i] == '.')
			return (1);
	}
	return (0);
}