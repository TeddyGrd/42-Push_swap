/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/16 00:40:02 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_error(char *argv[], int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < y)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[y][j] != '\0')
		{
			if (argv[i][j] != argv[y][j])
				break ;
			j++;
		}
		if (argv[i][j] == '\0' && argv[y][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

// int	limit_error(int x, char str)
// {
// 	ft_printf("%d", x);
// 	if (x == INT_MAX && ft_strcmp(&str, "2147483647") != 0) {
//             return (1); // Dépassement de INT_MAX
//         }
// 	return (0);
// }

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
		if (limit_error(x, *str) == 1)
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
		if (number_error(argc, argv, i) == 0
			|| double_error(argv, i) == 0)
		{
			ft_printf("Error \n");
			return (1);
		}
		i++;
	}
	return (0);
}
