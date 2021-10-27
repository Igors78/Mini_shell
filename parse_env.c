/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:47:11 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/27 11:14:20 by ioleinik         ###   ########.fr       */
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
		{
			d->buf = ft_straddchar(d->buf, s[(d->i)++]);
			printf("DEBUG %s\n", d->buf);
		}
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

void	handle_buck(t_data *d, char *s)
{
	if (s[d->i + 1] && s[d->i + 1] == '?')
	{
		d->i = d->i + 2;
		d->buf = ft_strjoin(d->buf, ft_itoa(d->exit_status));
		return ;
	}
}

char	*parse_env(t_data *d, char *s)
{
	if (d->buf)
		free(d->buf);
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
	return (d->buf);
}
