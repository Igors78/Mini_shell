/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:47:11 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/29 16:28:09 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_q(t_data *d, char *s)
{
	if (d->q)
	{
		d->i++;
		d->q = 0;
		return ;
	}
	else if (s[d->i + 1] && ft_strchr(&s[d->i + 1], '\''))
	{
		d->i++;
		d->q = 1;
		if (s[d->i] == '\'')
		{
			d->i++;
			d->q = 0;
			return ;
		}
		while (s[d->i] != '\'')
			d->buf = ft_straddchar(d->buf, s[(d->i)++]);
		return ;
	}
	d->buf = ft_straddchar(d->buf, s[(d->i)++]);
}

void	handle_qq(t_data *d, char *s)
{
	if (d->qq)
	{
		d->i++;
		d->qq = 0;
		return ;
	}
	else if (s[d->i + 1] && ft_strchr(&s[d->i + 1], '\"'))
	{
		d->i++;
		d->qq = 1;
		if (s[d->i] == '\"')
		{
			d->i++;
			d->qq = 0;
			return ;
		}
		return ;
	}
	d->buf = ft_straddchar(d->buf, s[(d->i)++]);
}

char	*parse_env(t_data *d, char *s)
{
	//if (d->buf)
	//	free(d->buf);
	d->buf = ft_strnew(0);
	while (s[d->i])
	{
		if (s[d->i] == '\'')
			handle_q(d, s);
		else if (s[d->i] == '\"')
			handle_qq(d, s);
		else if (s[d->i] == '$')
			handle_buck(d, s);
		else
			d->buf = ft_straddchar(d->buf, s[(d->i)++]);
	}
	d->i = 0;
	d->q = 0;
	d->qq = 0;
	free(s);
	return (d->buf);
}
