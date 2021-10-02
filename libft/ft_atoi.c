/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:15:45 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/14 17:21:16 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483648 || res < -2147483649)
			return (0);
		i++;
	}
	return (((int)res * sign));
}
