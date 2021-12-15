/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:31:51 by lefendie          #+#    #+#             */
/*   Updated: 2021/11/17 14:45:41 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint_in(int *int_list, int nb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (nb == int_list[i])
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}
