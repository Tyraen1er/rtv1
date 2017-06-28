/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:17:23 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/27 18:31:00 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_check_numbers(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit && str[i] != ' ')
			return (0);
	return (1);
}

int		ft_objectid(char *str)
{
	if (ft_strcmp(str, "sphere:") == 0)
		return (0);
	else if (ft_strcmp(str, "plan:") == 0)
		return (1);
	else if (ft_strcmp(str, "cone:") == 0)
		return (2);
	else if (ft_strcmp(str, "cylinder:") == 0)
		return (3);
	else
		return (-1);
}
