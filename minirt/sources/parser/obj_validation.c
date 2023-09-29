/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:50:49 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	aux_validation_acl(int i, char **str, char **str_aux)
{
	int		ambient;
	int		camera;
	int		ligth;

	ambient = 0;
	camera = 0;
	ligth = 0;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "A", 2) == 0)
			ambient++;
		if (ft_strncmp(str_aux[0], "C", 2) == 0)
			camera++;
		if (ft_strncmp(str_aux[0], "L", 2) == 0)
			ligth++;
	}
	ft_free_tab(str_aux);
	if (ambient == 1 && camera == 1 && ligth == 1)
		return (TRUE);
	return (FALSE);
}

int	validation_acl(char **str)
{
	char	**str_aux;
	int		i;

	i = -1;
	str_aux = NULL;
	if (aux_validation_acl(i, str, str_aux))
		return (TRUE);
	return (FALSE);
}

int	validation_obj(char **str)
{
	char	**aux;
	int		i;

	i = -1;
	aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(aux);
		aux = ft_split(str[i], 32);
		if ((ft_strncmp(aux[0], "A", 2) == 0 && ft_tab_len(aux) == 3)
			|| (ft_strncmp(aux[0], "C", 2) == 0 && ft_tab_len(aux) == 4)
			|| (ft_strncmp(aux[0], "L", 2) == 0 && ft_tab_len(aux) == 4)
			|| (ft_strncmp(aux[0], "sp", 3) == 0 && ft_tab_len(aux) == 4)
			|| (ft_strncmp(aux[0], "pl", 3) == 0 && ft_tab_len(aux) == 4)
			|| (ft_strncmp(aux[0], "cy", 3) == 0 && ft_tab_len(aux) == 6))
			continue ;
		else
		{
			ft_free_tab(aux);
			return (FALSE);
		}
	}
	ft_free_tab(aux);
	return (TRUE);
}
