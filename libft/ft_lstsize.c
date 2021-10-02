/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:21:31 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/20 20:28:52 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		l;

	p = lst;
	l = 0;
	while (p != NULL)
	{
		l += 1;
		p = p -> next;
	}
	return (l);
}
