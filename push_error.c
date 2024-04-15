/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 12:21:00 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int argc, char *argv[])
{
	int		i;
	int		y;

	i = 1;
	while (i < argc)
	{
		if (argc < 1)
		{
			y = ft_atoi((argv[i]));
			ft_printf("%d \n", y);
			if (ft_isalpha(y) == 0)
			{
				ft_printf("erreur dans les arguments \n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
