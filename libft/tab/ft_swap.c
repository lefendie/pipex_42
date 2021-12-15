/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:50:59 by lefendie          #+#    #+#             */
/*   Updated: 2021/09/28 12:24:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapint(int *tab, int i, int j)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}
