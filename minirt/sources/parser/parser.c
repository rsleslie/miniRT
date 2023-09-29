/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	validation_of_file_arguments(char **str)
{
	if (!validation_obj(str))
		return (FALSE);
	if (!validation_acl(str))
		return (FALSE);
	if (!validation_args(str))
		return (FALSE);
	return (TRUE);
}

int	*parser(t_objects **rt, char *file)
{
	char		**split_file;

	split_file = read_file(file);
	if (!split_file)
	{
		ft_putendl_fd("Error\nInvalid file.", 2);
		return (FALSE);
	}
	if (!validation_of_file_arguments(split_file))
	{
		ft_free_tab(split_file);
		ft_putendl_fd("Error\nWrong file arguments", 2);
		return (FALSE);
	}
	create_object(rt, split_file);
	ft_free_tab(split_file);
	return ((int *)TRUE);
}
