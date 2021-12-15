/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:49 by lefendie          #+#    #+#             */
/*   Updated: 2021/11/17 15:03:04 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_alloc_int_tab(int **tab, int size)
{
	*tab = malloc(sizeof(int) * size);
	if (!(*tab))
		return (FAILURE);
	ft_bzero(*tab, size);
	return (SUCCESS);
}
