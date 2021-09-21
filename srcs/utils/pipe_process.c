/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:32:41 by ysong             #+#    #+#             */
/*   Updated: 2021/09/18 15:40:27 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pipe_process(t_minishell *shell)
{
	pid_t	pid;
	int		status;
	t_minishell *next_shell;

	next_shell = shell->next;
	if(shell->pipe_flag == 1)
	{
		next_shell->pre_flag = 1;
		pipe(next_shell->fds);
	}
	pid = fork();
	if (pid == 0)
		child_process(shell);
	waitpid(pid, &status, 0);
	if (shell->pipe_flag == 1)
		close(next_shell->fds[1]);
	if (shell->fds[0] != 0)
		close(shell->fds[0]);
	return 0;
}