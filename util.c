/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:50:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/23 17:17:01 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*chk_sing_quo(t_data *d, char *s)
{
	int		i;
	char	**spl;
	char	*tmp;

	i = 0;
	spl = ft_split(s, ' ');
	while (spl[i])
	{
		spl[i] = parse_env(d, spl[i]);
		i++;
	}
	s = stick_back(spl);
	tmp = ft_strjoin("\"", s);
	free(s);
	s = ft_strjoin(tmp, "\"");
	free(tmp);
	return (s);
}

char	*chk_exp(t_data *d, char *s)
{
	(void)d;
	(void)s;
	return (NULL);
}

void	free_memory(t_data *d)
{
	if (d->envv)
		ft_split_free(d->envv);
	if (d->cmd)
		ft_split_free(d->cmd);
	if (d->line)
		free(d->line);
	if (d->path)
		free(d->path);
}

void	put_strarr(char **arr)
{
	int	i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

char	*trim_quot(char *s)
{
	char	*tmp;

	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s[ft_strlen(s) - 1] = '\0';
		tmp = ft_strdup(&s[1]);
		free(s);
		return (tmp);
	}
	else if (s[0] == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		s[ft_strlen(s) - 1] = '\0';
		tmp = ft_strdup(&s[1]);
		free(s);
		return (tmp);
	}
	return (s);
}
