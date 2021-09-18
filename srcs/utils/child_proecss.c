/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proecss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:33:13 by ysong             #+#    #+#             */
/*   Updated: 2021/09/18 14:22:02 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void child_process(t_minishell *shell)
{
    int		ret;
    int     i;

	ret = EXIT_SUCCESS;
	if (shell->pipe_flag == 1)
	{
		dup2(shell->next->fds[1], STDOUT);
		close(shell->next->fds[1]);
	}
	if (shell->fds[0] != 0)
	{
		dup2(shell->fds[0], STDIN);
		close(shell->fds[0]);
	}
    i = -1;
    while (++i < BLTIN_NUM)
    {
        if (!ft_strcmp(shell->cmd->cmd, blt_str(i)))
        {
            ret = (*blt_func(i))(shell);
            break;
        }
        else if(i == 6)
            write(1, "commend not found\n", ft_strlen("commend not found\n"));
    }
	exit(ret);
}