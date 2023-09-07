/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:16:23 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/06 22:14:43 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return ;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
	str = NULL;
}
int	bytes_file(char *file)
{
	int		fd;
	int		byte;
	char	buf[1];

	byte = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1) != 0)
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


// char	**split_space(char **tab)
// {
// 	int	i;
// 	int	size;
// 	char **s;

// 	i = -1;
	
// 	size = ft_tab_len(tab);
// 	return (s);
// }

//função de validação de argumento

int	validation_obj(char **str)
{
	char **str_aux;
	int i;

	i = -1;
	str_aux = NULL;
	while (++i < ft_tab_len(str))
	{
		ft_free_tab(str_aux);	
		str_aux = ft_split(str[i], 32);
		if (ft_strncmp(str_aux[0], "A", 2) == 0 && ft_tab_len(str_aux) == 3)
			continue ;
		else if (ft_strncmp(str_aux[0], "C", 2) == 0 && ft_tab_len(str_aux) == 4)	
			continue ;
		else if (ft_strncmp(str_aux[0], "L", 2) == 0 && ft_tab_len(str_aux) == 3)	
			continue ;
		else if (ft_strncmp(str_aux[0], "sp", 3) == 0 && ft_tab_len(str_aux) == 4)	
			continue ;
		else if (ft_strncmp(str_aux[0], "pl", 3) == 0 && ft_tab_len(str_aux) == 4)	
			continue ;
		else if (ft_strncmp(str_aux[0], "cy", 3) == 0 && ft_tab_len(str_aux) == 5)	
			continue ;
		else
		{
			ft_free_tab(str_aux);
			ft_putendl_fd("arguments error", 2);
			return (FALSE);
		}
	}
	ft_free_tab(str_aux);
	return (TRUE);
}

int	validation_acl(char **str)
{
	char **str_aux;
	int	ambient;
	int	camera;
	int	ligth;
	int i;

	i = -1;
	str_aux = NULL;
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
	ft_putendl_fd("identifier error", 2);
	return (FALSE);
}

int	validation_str(char **str)
{
	/*
	vou ver se os argumentos são validos retorna true ou false,
	vai chegar um ** quebra cada string e verificar  primeiro arqgumento	
	*/
	if (!validation_obj(str))
		return (FALSE);
	/*
	quebrar cada string e verificar a quantidade de argumento retorna true e false
	*/
	
	// if (!validation_args(str))
	// 	return (FALSE); o validation_obj ja faz isso
	/*
	validar cad argumento 
	*/
	/*
		validação de Ambiente Camera e Ligth
	*/
	if (!validation_acl(str))
		return (FALSE);
	/*
		validation dos argumentos de cada identificador
	*/
	return (TRUE);
}



char **read_file(char *file)
{
	int		fd;
	char 	*buffer;
	char    *join;
	char	**split_line;

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
	{
		ft_free_tab(split_line);
		ft_putendl_fd("few arguments", 2);
		return (NULL);
	}
	return (split_line);
}

int	parser(char *file)
{
	char **split_file;

	split_file = read_file(file);
	if (!split_file)
		return (FALSE);
	//char uma função de validação de argumentos
	if (!validation_str(split_file))
	{
		ft_free_tab(split_file);
		return (FALSE);
	}
	ft_free_tab(split_file);
	return (TRUE);
}