/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:48:52 by ysong             #+#    #+#             */
/*   Updated: 2021/09/18 14:26:18 by ysong            ###   ########.fr       */
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
	int ret;
	int pipe_open;
	int status;
	int i;
	pid_t pid;

	i = -1;
	pipe_open = 0;
	ret = 1;
	if(shell->cmd->cmd == NULL)
		shell->cmd->cmd = " ";
	// todo 파이프 확인부분
	if (shell->pipe_flag == 1 || (shell->prev && shell->prev->pipe_flag == 1))
	{
		pipe_open = 1;
		if (pipe(shell->fds))
			return (exit_fatal());
	}
	if (shell->pipe_flag == 0)
	{
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
	}
	else
	{
		//명령어 실행부분
		pid = fork();
		if (pid < 0)
			return (exit_fatal());
		else if (pid == 0)
		{
			child_process(shell);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (pipe_open)
			{
				close(shell->fds[1]);
				if (!shell->next)
					close(shell->fds[0]);
			}
			if (shell->prev && shell->prev->pipe_flag == 1)
				close(shell->prev->fds[0]);
			freeshell(&shell);
		}
	}
	return ret;
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
			// while(shell)
			// {
			// 	// printf("%s\n",shell->cmd->cmd);
			// 	// printf("%d\n",shell->pipe_flag);
			// 	test_shell=shell;
			// 	if (test_shell->next)
			// 		test_shell = test_shell->next;
			// 	else
			// 		break;
			// }
			status = run_shell(shell);
			free(line);
		}
	}
	free(line);
	(void)en;
}