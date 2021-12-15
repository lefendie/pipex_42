/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_isstr_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:56:18 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/09 11:30:09 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lb_isstr_equal(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str2[i] && !str1[i])
		return (SUCCESS);
	return (FAILURE);
}

int	lb_isstr_start_equal(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str2[i])
		return (SUCCESS);
	return (FAILURE);
}
