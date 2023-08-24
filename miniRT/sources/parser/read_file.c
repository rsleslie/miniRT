/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:16:23 by rleslie-          #+#    #+#             */
/*   Updated: 2023/08/23 22:37:38 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	bytes_file(char *file)
{
	int		fd;
	int		byte;
	char	buf[1];

	byte = 0;
	fd = open(file, O_RDONLY);
	while(read(fd, buf, 1) != 0)
		byte++;
	if (byte == 0)
	{
		ft_putendl_fd("Error\nEmpty file\n", 2);
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (byte);
	
	// read(fd, buffer, byte);
}

// int	check_acl(char **file)
// {
	
// }

char	**split_space(char **tab)
{
	int	i;
	int	size;
	char **s;

	i = -1;
	size = ft_tab_len(tab);
	return (s);
}

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
	str = NULL;
}

char **read_file(char *file)
{
	int		fd;
	char 	*buffer;
	char    *join;
	char	**split_line;
	char	**split_spc;

	join = NULL;
	fd = open(file, O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		buffer = ft_strjoin(buffer, "\n");
		join = ft_strjoin(join, buffer);
		free(buffer);	 
	}
	close(fd);
	split_line = ft_split(join, '\n');
	free(join);
	if (ft_tab_len(split_line) < 3)
		return (NULL);
	//split_spc = split_space(split_line);
	ft_free_tab(split_line);
	return (**split_spc);
}