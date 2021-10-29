/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:54:31 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/29 20:19:27 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Nuke the last string of array into orbit. */
void	ft_split_delete_last(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	free(args[i]);
	free(args[i - 1]);
	args[i - 1] = NULL;
}

/* Send pos'th arg to all the way back of the array.
 Return the total movement steps in the array. */
int		ft_split_move_to_back(char **args, int pos)
{
	char	*tmp;
	int		pos_org;

	pos_org = pos;
	while (args[pos + 1])
	{
		tmp = args[pos + 1];
		args[pos + 1] = args[pos];
		args[pos] = tmp;
		pos++;
	}
	return (pos - pos_org);
}
