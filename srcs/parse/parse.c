/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:38:03 by ysong             #+#    #+#             */
/*   Updated: 2021/09/20 02:09:19 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_minishell *init_shell(char *line, t_minishell *shell, int pipe)
{
	shell = (t_minishell *)malloc(sizeof(t_minishell));
	shell->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	shell->cmd->cmd = ft_split(line, ' ')[0];
	shell->cmd->buff = line;
	shell->exit_status = 0;
	if (pipe > 1)
		shell->pipe_flag = 1;
	else
		shell->pipe_flag = 0;
	shell->pre_flag = 0;
	shell->next = NULL;
	shell->prev = NULL;
	return shell;
}

static void connect_list(t_minishell **temp, t_minishell **shell)
{
	if (!*shell)
	{
		*shell = *temp;
	}
	else
	{
		(*shell)->next = *temp;
		(*temp)->prev = *shell;
		*shell = (*shell)->next;
	}
}

int list_rewind(t_minishell **shell)
{
	while (*shell && (*shell)->prev)
		*shell = (*shell)->prev;
	return (0);
}

t_minishell *parse_data(char *line)
{
	char **commnd_list;
	t_minishell *temp;
	t_minishell *shell;
	int i;

	i = 0;
	commnd_list = ft_split(line, '|');
	while (commnd_list[i])
		i++;
	
	shell = init_shell(line, shell, i);
	if (i > 0)
	{
		// echo 시 '\|' '\\|' 예외는 나중``
		i = 0;
		while (commnd_list[++i])
		{
			temp = init_shell(commnd_list[i],temp, i);
			connect_list(&temp, &shell);
		}
		list_rewind(&shell);
	}
	return shell;
}