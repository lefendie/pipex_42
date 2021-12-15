/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lb_strcontstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:36:44 by lefendie          #+#    #+#             */
/*   Updated: 2021/11/26 15:37:11 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lb_strcontstr(char *str, char *str2)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (*str && *str == str2[i])
		{
			i++;
			str++;
		}
		if (!str2[i])
			return (SUCCESS);
		if (!i)
			str++;
	}
	return (FAILURE);
}
