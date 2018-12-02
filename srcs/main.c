/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:09:39 by fhong             #+#    #+#             */
/*   Updated: 2018/11/30 22:53:26 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	check_flag(char **av)
{
	int		i;
	char	*tmp;
	char 	flag[5] = "Rlart";

	while ((*av) && (*av)[0] == '-')
	{
		i = 0;
		while ((*av)[++i] && !ft_isspace((*av)[i]))
		{
			if ((tmp = ft_strchr(flag, (*av)[i])))
				g_flag[tmp - flag] = 1;
			else
				ft_error("Usage: ft_ls[Rlart][file name]\n");
		}
		av++;
	}
}

void	init(void)
{
	ft_memset(g_flag, 0, 5);
}

int		main(int ac, char **av)
{
	(void)ac;
	check_flag(&av[1]);
	for (int i = 0; i < 5; i++)
		ft_printf("%d, ", g_flag[i]);
	return (0);
}
