/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/07 21:29:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	validation_str(char **str)
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
	if (!validation_str(split_file))
	{
		ft_free_tab(split_file);
		return (FALSE);
	}
	ft_free_tab(split_file);
	return (TRUE);
}
