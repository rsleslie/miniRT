/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:52:10 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_arg(int argc)
{
	if (argc == 2)
		return (TRUE);
	return (FALSE);
}

int	check_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror("");
		return (FALSE);
	}
	if ((argv[1][ft_strlen(argv[1]) - 1]) == 't' &&
		(argv[1][ft_strlen(argv[1]) - 2] == 'r') &&
		(argv[1][ft_strlen(argv[1]) - 3] == '.'))
	{
		close(fd);
		return (TRUE);
	}
	close(fd);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("file extension error", 2);
	return (FALSE);
}
