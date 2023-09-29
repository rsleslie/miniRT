/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:35:24 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 14:35:39 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	world_free(t_world *w)
{
	if (w->rt->sp != NULL)
		free(w->rt->sp);
	if (w->rt->cy != NULL)
		free(w->rt->cy);
	if (w->rt->pl != NULL)
		free(w->rt->pl);
	free(w->rt);
	free(w);
}
