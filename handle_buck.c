/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:43:02 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/29 15:18:25 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspecsymbol(int ch)
{
	unsigned char	c;

	c = (unsigned char)(ch);
	if (c == ',' || c == '%' || c == '.' || c == '/' || c == ':' || c == '='
		|| c == '^' || c == ']' || c == '~' || c == '}')
		return (1);
	return (0);
}

int	check_single_par(t_data *d, char *s)
{
	if (s[d->i + 1] && (s[d->i + 1] == '?' || s[d->i + 1] == '#'))
	{
		d->i = d->i + 2;
		d->buf = ft_strjoin(d->buf, ft_itoa(d->exit_status));
		return (1);
	}
	if (s[d->i + 1] && (s[d->i + 1] == '$'))
	{
		d->i = d->i + 2;
		d->buf = ft_strjoin(d->buf, ft_itoa(8596));
		return (1);
	}
	if (s[d->i + 1] && ft_isdigit(s[d->i + 1]))
	{
		d->i = d->i + 2;
		return (1);
	}
	if (!s[d->i + 1] || (s[d->i + 1] && ft_isspecsymbol(s[d->i + 1]))
		|| ((s[d->i + 1] && !ft_isalnum(s[d->i + 1])) && d->qq))
	{
		d->buf = ft_straddchar(d->buf, s[(d->i)++]);
		return (1);
	}
	return (0);
}

int	check_var_avail(t_data *d, char *s)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	i = d->i + 1;
	tmp = ft_strnew(0);
	while ((s[i] && ft_isalnum(s[i])) || (s[i] && s[i] == '_'))
		tmp = ft_straddchar(tmp, s[i++]);
	if (!ft_getenv(d, tmp))
	{
		d->i = i;
		free(tmp);
		return (1);
	}
	else
	{
		d->i = i;
		tmp1 = d->buf;
		d->buf = ft_strjoin(tmp1, ft_getenv(d, tmp));
		free(tmp1);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void	handle_buck(t_data *d, char *s)
{
	if (check_single_par(d, s))
		return ;
	if (check_var_avail(d, s))
		return ;
}
