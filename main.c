/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:30:24 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/09 20:16:27 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirection_and_pipes(char **argv, char **envp)
{
	int	id;
	int	pipe_fd[2];

	pipe(pipe_fd);
	id = fork();
	if (!id)
	{
		if (!redirect_read(argv[1]))
			return (FAILURE);
		if (!branch_write_to(pipe_fd, 1))
			return (FAILURE);
		exec_command(argv[2], envp);
	}
	wait(NULL);
	if (!redirect_write(argv[4]))
		return (0);
	if (!branch_read_to(pipe_fd, 0))
		return (FAILURE);
	exec_command(argv[3], envp);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	id;

	if (argc != 5)
		return (FAILURE);
	if (!check_command(argv, envp))
		return (FAILURE);
	id = fork();
	if (!id)
		redirection_and_pipes(argv, envp);
}
