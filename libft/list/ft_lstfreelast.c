/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreelast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:07:28 by lefendie          #+#    #+#             */
/*   Updated: 2021/11/13 10:22:04 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_lstfreelast(t_list **lst)
//{
//	t_list *sav_list;
//
//	sav_list = *lst;
//	if (*lst)
//	{
//		while ((*lst)->next)
//			(*lst) = (*lst)->next;
//		free((*lst)->next->content);
//		free((*lst)->next);
//		(*lst)->next = NULL;
//		*lst = sav_list;
//	}
//}
