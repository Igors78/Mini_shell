/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 06:44:47 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/14 07:26:00 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	unsigned char	c;

	c = (unsigned char)(ch);
	if (c < 'A')
		return (0);
	else if ((c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}
