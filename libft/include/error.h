/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:58:41 by lefendie          #+#    #+#             */
/*   Updated: 2021/09/13 11:19:53 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	ft_choose_print_color(char color);
void	ft_exit(void);
void	ft_exit_with_error(char *error_message, char color);
void	ft_exit_with_error_func(char *error_message, void (*func)(void *data),
			void *data, char color);
void	ft_exit_with_error_var(char *error_message, char *additional_info,
			char color);

#endif
