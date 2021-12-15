/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:59:57 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 22:11:04 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_FUNC_H
# define IS_FUNC_H

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdbl(char *str);
int	ft_isdigit(int c);
int	ft_isint(char *str);
int	ft_isprint(int c);
int	ft_isint_in(int *int_list, int nb, int n);
int	ft_isstrdigit(char *str);
int	lb_isstr_equal(char *str1, char *str2);
int	lb_isstr_start_equal(char *str1, char *str2);

#endif
