/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/09 15:59:40 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int argc, char *argv[])
{
	int i;
	int	y;

	i = 1;
	while (i < argc)
	{
		if(argc < 1)
		{
			y = ft_atoi((argv[i]));
            printf("%d \n", y);
			if(ft_isalpha(y) == 0)
			{
				printf("erreur dans les arguments \n");
				return (1);
			}
		}
    	i++;
	}
	return (0);
}
