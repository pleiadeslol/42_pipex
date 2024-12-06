/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:07:40 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/05/05 18:16:10 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../get_next_line/get_next_line.h"
#include "../ft_eprintf/ft_eprintf.h"

static char	*find_home_env(char **envp)
{
	char	*p;
	int		i;

	i = 0;
	p = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", 4) == 0)
		{
			p = ft_strchr(envp[i], '=');
			if (p)
				p++;
			break ;
		}
		i++;
	}
	return (p);
}

static void	join_home(char **cmd, int i, char *p)
{
	char	*tmp;

	tmp = ft_strtrim(cmd[i], "~");
	free(cmd[i]);
	cmd[i] = ft_strjoin(p, tmp);
	free(tmp);
}

void	replace_home(t_args *args, char **envp)
{
	char	*p;
	int		i;

	p = find_home_env(envp);
	i = 0;
	while (args->cmd1[i])
	{
		if (ft_strchr(args->cmd1[i], '~'))
			join_home(args->cmd1, i, p);
		i++;
	}
	i = 0;
	while (args->cmd2[i])
	{
		if (ft_strchr(args->cmd2[i], '~'))
			join_home(args->cmd2, i, p);
		i++;
	}
}
