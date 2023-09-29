/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:52:20 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:10 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_world	*w;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nWrong number of arguments.", 2);
		return (0);
	}
	data = (t_data *)malloc(sizeof(t_data));
	w = (t_world *)malloc(sizeof(t_world));
	w->rt = (t_objects *)malloc(sizeof(t_objects));
	w->rt->sp = NULL;
	w->rt->cy = NULL;
	w->rt->pl = NULL;
	if (!parser(&w->rt, argv[1]))
	{
		world_free(w);
		exit(0);
	}
	data->w = w;
	init_render_mlx(data);
	return (0);
}
