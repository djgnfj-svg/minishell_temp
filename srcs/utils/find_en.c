/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_en.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:44:34 by ysong             #+#    #+#             */
/*   Updated: 2021/09/08 07:45:40 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*find_en(char *key, char **en)
{
	int	i;

	i = -1;
	while (en[++i])
	{
		if (!ft_strncmp(en[i], key, ft_strlen(key)))
			return (en[i] + ft_strlen(key) + 1);
	}
	return (NULL);
}