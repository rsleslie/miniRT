/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:52:20 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/10 17:45:47 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	free_t_object(t_objects *rt)
{
	if (rt)
	{
		if (rt->sp)
			free(rt->sp);
		if (rt->pl)
			free(rt->pl);
		if (rt->cy)
			free(rt->cy);
	}
	free(rt);
}

int	main(int argc, char **argv)
{
	t_objects	*rt;

	if (argc != 2)
	{
		ft_putendl_fd("number of invalid arguments", 2);
		return (1);
	}
	rt = (t_objects *)malloc(sizeof(t_objects));
	rt->sp = NULL;
	rt->cy = NULL;
	rt->pl = NULL;
	if (!parser(&rt, argv[1]))
	{
		free_t_object(rt);
		return (1);
	}
	free_t_object(rt);
	
}