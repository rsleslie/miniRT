/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:03:53 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 18:48:53 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	create_cy(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "cy", 3) == 0)
		{
			(*rt)->cy[j] = add_cy(aux);
			j++;
		}
	}
	ft_free_tab(aux);
}

void	create_sp(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "sp", 3) == 0)
		{
			(*rt)->sp[j] = add_sp(aux);
			j++;
		}
	}
	ft_free_tab(aux);
}

void	create_plane(t_objects **rt, char **args)
{
	int		i;
	int		j;
	char	**aux;

	i = -1;
	j = 0;
	aux = NULL;
	while (++i < ft_tab_len(args))
	{
		ft_free_tab(aux);
		aux = ft_split(args[i], 32);
		if (ft_strncmp(aux[0], "pl", 3) == 0)
		{
			(*rt)->pl[j] = add_pl(aux);
			j++;
		}
	}
	ft_free_tab(aux);
}
