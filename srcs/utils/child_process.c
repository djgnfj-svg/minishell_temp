/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:13 by ysong             #+#    #+#             */
/*   Updated: 2021/09/20 02:06:49 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void child_process(t_minishell *shell)
{
    int     i;
	t_minishell *next_shell;
	int ret;

	ret = EXIT_SUCCESS;
	next_shell = shell->next;
	if (shell->pipe_flag == 1)
	{
		dup2(next_shell->fds[1], STDOUT);
		close(next_shell->fds[1]);
	}
	if (shell->fds[0] != 0)
	{
		dup2(shell->fds[0], STDIN);
		close(shell->fds[0]);
	}
    i = -1;
    while (++i < BLTIN_NUM)
	{
        run_blt(shell, i);
	}
	exit(ret);
}