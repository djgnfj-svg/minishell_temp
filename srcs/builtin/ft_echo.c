/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:11:43 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/23 01:26:16 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(t_minishell *shell)
{
	int i;
	char **temp;
	char **buff;
	pid_t pid;
	buff = ft_split(shell->cmd->buff, ' ');
	i = 0;
	while(buff[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while(buff[++i])
	{
		temp[i] = buff[i];
		printf("temp[%d] = %s\n",i,temp[i]);
	}
	temp[i] = NULL;
	pid = fork();
	if (pid == 0)
		if(execve("/bin/echo", temp ,g_envp) == -1)
			fprintf(stderr, "에러 %s\n", strerror(errno));
	waitpid(pid, &shell->exit_status, 0);
	return (0);
}
