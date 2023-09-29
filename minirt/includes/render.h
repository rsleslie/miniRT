/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:36:25 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:11 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"

void	world_free(t_world *w);
void	init_render(t_data *data);
int		putting_it_in_the_window(t_data *data);
void	init_render_mlx(t_data *data);
int		close_esc(int keysym, t_data *data);
int		close_x(t_data *data);

#endif