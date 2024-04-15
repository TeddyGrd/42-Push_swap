/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 16:11:26 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int double_error(int argc, char *argv[], int i)
// {
	
// }

int	limit_error(int x)
{
	ft_printf("%d", x);
	if (x > INT_MAX || x < INT_MIN)
		return (1);
	return (0);
}

int	number_error(int argc, char *argv[], int i)
{
	char	*str;
	int		x;

	str = argv[i];
	if (argc >= 1)
	{
		x = 0;
		x = ft_atoi(str);
		while (*str)
		{
			if (*str == '-')
				str++;
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		if (limit_error(x) == 1)
			return (0);
	}
	return (1);
}

int	check_error(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (number_error(argc, argv, i) == 0) 
			// && double_error(argc, argv, i) == 1)
		{
			ft_printf("Error \n");
			return (1);
		}
		i++;
	}
	return (0);
}
