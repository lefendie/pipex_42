/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:16:19 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 15:45:19 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_BONUS_H
# define REDIRECTION_BONUS_H

int	redirect_write_end(char *file);
int	transfer_pipe(int **pipe_duo, char **cmd_list,
		int cmd_count, char **envp);
int	here_doc(char **argv, int *hrdc_pipe);
int	exec_write_end(int **pipe_duo, char **argv, int argc, char **envp);

#endif
