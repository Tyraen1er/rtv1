/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_quad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 21:36:35 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/05 21:38:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_quad	ft_create_quad(t_point fst, t_point scd)
{
	t_quad	new;

	new = (t_quad){fst, scd};
	return (new);
}
