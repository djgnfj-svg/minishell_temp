/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:12:30 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/13 06:40:04 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(t_minishell *shell)
{
	int i;

	i = 0;
	while(g_envp[i])
	{
		write(1, g_envp[i], ft_strlen(g_envp[i]));
		write(1,"\n",1);
		i++;
	}
	(void)shell;
	return (0);
}
