/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:11:43 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/18 01:08:56 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(t_minishell *shell)
{
	int i;
	char **temp;
	char **buff;

	int status;
	
	buff = ft_split(shell->cmd->buff, ' ');
	i = 0;
	while(buff[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while(buff[++i])
		temp[i] = buff[i];
	temp[i] = NULL;
	if((status = execve("/bin/echo", temp ,g_envp)) == -1)
		fprintf(stderr, "에러 %s\n", strerror(errno));
	return (status);
}
