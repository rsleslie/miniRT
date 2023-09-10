/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:28:00 by rleslie-          #+#    #+#             */
/*   Updated: 2023/09/09 19:38:46 by rleslie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "miniRT.h"

typedef struct s_cy
{
	t_tuple	coordinates;
	t_tuple	vector;
	float	diameter;
	float	heigth;
	t_color	color;
}	t_cy;

typedef struct s_pl
{
	t_tuple	coordinates;
	t_tuple	vector;
	t_color	color;
}	t_pl;

typedef struct s_sp
{
	t_tuple	coordinates;
	float	diameter;
	t_color	color;
}	t_sp;

typedef struct s_l
{
	t_tuple	coordinates;
	float	brightness;
	t_color	color;
}	t_l;

typedef struct s_c
{
	t_tuple	coordinates;
	t_tuple	vector;
	int		fov;
}	t_c;

typedef struct s_a
{
	t_color	color;
	float	ratio;
}	t_a;

typedef struct s_objects
{
	t_a		a;
	t_c		c;
	t_l		l;
	int		n_sp;
	int		n_pl;
	int		n_cy;
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;
}	t_objects;

#endif