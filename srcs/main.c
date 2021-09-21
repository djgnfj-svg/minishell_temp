/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:59:00 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/18 15:19:03 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//임시로 만듬 만약에 3중포인터로 움직일수 있다면 그방향으로 가도 좋을듯
char	**g_envp = NULL;

static char			**copy_envp(char **envs)
{
	char	**new;
	int		i;

	i = 0;
	while (envs[++i] != NULL)
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (envs[++i])
		new[i] = ft_strdup(envs[i]);
	new[i] = NULL;
	return (new);
}

int	main(int argc, char *argv[], char *envp[])
{
	g_envp = copy_envp(envp);
	minishell(envp);
	(void)argc;
	(void)argv;
	return (0);
}