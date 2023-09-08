/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/08 18:28:18 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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

int	parser(char *file)
{
	char	**split_file;

	split_file = read_file(file);
	if (!split_file)
		return (FALSE);
	if (!validation_of_file_arguments(split_file))
	{
		ft_free_tab(split_file);
		ft_putendl_fd("error declaring file arguments", 2);
		return (FALSE);
	}
	
	ft_free_tab(split_file);
	return (TRUE);
}
