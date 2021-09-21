/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:12:52 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/18 16:47:45 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int check_env(char *en_name)
{
	int i;

	i = -1;
	while(en_name[++i])
		if(ft_isalnum(en_name[i]))
			;
		else
			return (0);
	if(!i)
		return(0);
	return (1);
}

static int		check_key_value(char *str, char *envs)
{
	int	i;

	i = 0;
	while (str[i] && envs[i] && (str[i] == envs[i]))
		i++;
	if ((str[i] == '\0'))
		return (1);
	return (0);
}

static int unset_en(char *str, char ***en)
{
	int i;
	int last;

	last = 0;
	while (((*en)[last]))
		last++;
	if (last < 1)
		return (-1);
	i = -1;
	while ((*en)[++i])
		if (check_key_value(str, (*en)[i]))
		{
			free((*en)[i]);
			(*en)[i] = ft_strdup((*en)[last - 1]);
			free((*en)[last - 1]);
			(*en)[last - 1] = NULL;
			return (1);
		}
	return (1);

}

// 이것또한 파이프라인 뒤쪽에 있다면 실행되지 않는다.
int		ft_unset(t_minishell *shell)
{
	int i;
	int status;
	char **buff;

	if (shell->pre_flag)
		return 0;
	i = 0;
	status = 0;
	buff = ft_split(shell->cmd->buff, ' ');
	while (buff[++i])
		status = check_env(buff[i]) && unset_en(buff[i], &g_envp);
	return (status);
}
