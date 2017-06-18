/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_in_quad_to_ratio.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 21:32:56 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/15 14:21:37 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	ft_point_in_quad_to_ratio(t_quad quad, t_point point)
{
	t_point	ratio;

	ratio.x = (point.x - quad.tl.x) / (quad.br.x - quad.tl.x);
	ratio.y = (point.y - quad.tl.y) / (quad.br.y - quad.tl.y);
	return (ratio);
}
