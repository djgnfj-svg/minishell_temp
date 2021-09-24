/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:48:52 by ysong             #+#    #+#             */
/*   Updated: 2021/09/25 08:34:18 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void show_prompt(void)
{
	char cmds[1024];
	getcwd(cmds,1024);
	write(1, cmds, ft_strlen(cmds));
	write(1, "$ ", 3);
}
int show_error(char const *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

static int	run_shell(t_minishell *shell)
{
	int i;

	i = -1;
	// 이부분을 t_LIST형태로 반복해야됨
	while (shell)
	{
		if (shell->cmd->cmd == NULL)
			shell->cmd->cmd = " ";
		if (shell->pipe_flag == 0)
			while (++i < BLTIN_NUM)
				run_blt(shell, i);
		else if (shell->re_flag == 1)
			re_process(shell);
		else
			pipe_process(shell);
		shell = shell->next;
	}
	return 1;
}


void	minishell(char **en)
{
	int		status;
	char	*line;
	t_minishell *shell;
	// t_minishell *test_shell;/

	// char	**cmd;

	status = 1;
	while (status)
	{
		show_prompt();
		if(get_next_line(0,&line) > 0)
		{
			shell = (t_minishell *)malloc(sizeof(t_minishell));
			shell = parse_data(line);
			status = run_shell(shell);
			free(line);
		}
	}
	// free(line);
	(void)en;
}