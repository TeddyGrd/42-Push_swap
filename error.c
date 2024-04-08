/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/08 09:20:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(int argc, char *argv[])
{
    int i;
    i = 0;
    if(argc == 1 || argc == 2 && !argv[1][0])
    	return (1);
    while(i < argc)
    {
		ft_printf("%s", argv[i]);
		i++;
		// j = 0;
		// ft_printf("%s", argv[j]);
        // while(j < argv)
		// {
		// 	j++;
		// }
        i++;
    }
    return (0);
}
