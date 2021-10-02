/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 07:07:16 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/16 07:31:23 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = NULL;
	p = malloc(n * size);
	if (NULL == p)
		return (p);
	ft_bzero(p, n * size);
	return (p);
}
