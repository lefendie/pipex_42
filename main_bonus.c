/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:30:27 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/15 11:21:28 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: redirection_and_pipes_tranfer
 *  -------------------------
 *  Function only intended for pipex, allows the redirection from a file to
 *  a command, then the data transfer between commands and pipes and then
 *  the redirection to a file
 *
 *  pipe_duo: List containing a duo of pipes
 *  argc:			Number of program arguments
 *  argv:			List containing the program arguments
 *  envp:			List containing the envirronement variables
 *
 *  Returns: Success state
 */

int	redirection_and_pipes_tranfer(int **pipe_duo, int argc, char **argv,
		char **envp)
{
	int	id;

	id = fork();
	if (!pipe_duo[0] || !pipe_duo[1])
		return (0);
	if (!id)
	{
		if (!redirect_read(argv[1]))
			return (0);
		if (!branch_write_to(pipe_duo[1], 1))
			return (FAILURE);
		exec_command(argv[2], envp);
	}
	if (argc > 5)
	{
		if (!transfer_pipe(pipe_duo, argv + 3, argc - 6, envp))
			return (FAILURE);
	}
	if (!redirect_write(argv[argc - 1]))
		return (FAILURE);
	if (!branch_read_to(pipe_duo[1], 0))
		return (FAILURE);
	exec_command(argv[argc - 2], envp);
	return (SUCCESS);
}

/*
 *  Function: here_doc_and_pipes
 *  -------------------------
 *  Function only intended for pipex, allows the here_doc for the first
 *  command, the commands and pipe transfer and the redirection >> to the
 *  last file
 *  pipe_duo: List containing a duo of pipes
 *  argc:			Number of program arguments
 *  argv:			List containing the program arguments
 *  envp:			List containing the envirronement variables
 *
 *  Returns: Success state
 */

int	here_doc_and_pipes(int **pipe_duo, int argc, char **argv, char **envp)
{
	int	hrdc_pipe[2];
	int	id;

	pipe(hrdc_pipe);
	id = fork();
	if (!id)
	{
		if (!branch_write_to(pipe_duo[1], 1))
			return (FAILURE);
		here_doc(argv, hrdc_pipe);
		exec_command(argv[3], envp);
	}
	if (!branch_read_to(hrdc_pipe, 0))
		return (FAILURE);
	if (argc > 6)
	{
		if (!transfer_pipe(pipe_duo, argv + 4, argc - 7, envp))
			return (FAILURE);
	}	
	if (!redirect_write_end(argv[argc - 1]))
		return (FAILURE);
	if (!branch_read_to(pipe_duo[1], 0))
		return (FAILURE);
	exec_command(argv[argc - 2], envp);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		**pipe_duo;

	if (argc < 5)
		return (FAILURE);
	if (!check_command(argv, envp))
		return (FAILURE);
	id = fork();
	if (!id)
	{
		create_pipe_duo(&pipe_duo);
		if (lb_isstr_start_equal(argv[1], "here_doc"))
			here_doc_and_pipes(pipe_duo, argc, argv, envp);
		else
			redirection_and_pipes_tranfer(pipe_duo, argc, argv, envp);
	}
	wait(NULL);
	return (SUCCESS);
}
