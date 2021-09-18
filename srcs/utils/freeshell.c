/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:29:07 by ysong             #+#    #+#             */
/*   Updated: 2021/09/18 12:46:23 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void freeshell(t_minishell **shell)
{
    t_minishell *temp;

	list_rewind(shell);
    while(*shell)
    {
        temp = (*shell)->next;
        free((*shell)->cmd);
        free(*shell);
        *shell = temp;
    }
    *shell = NULL;
}