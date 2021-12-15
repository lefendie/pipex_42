/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:31:26 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/09 11:29:00 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void	free_path_bin(char **func_arg, char **path_list);
char	**get_path_env(char **envp);
char	*get_bin(char *command, char **envp);
int		check_command(char **argv, char **envp);
int		close_pipe(int *pipe);
int		ft_get_next_line(int fd, char **line);

#endif
