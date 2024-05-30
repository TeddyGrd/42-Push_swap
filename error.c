/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:30:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/31 00:55:57 by tguerran         ###   ########.fr       */
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

int	is_an_int(const char *av)
{
	long long	value;
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(av);
	if (len > 11)
		return (1);
	while (i < len)
	{
		if (i == 0 && (av[i] == '-' || av[i] == '+'))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	value = ft_atoi(av);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *str)
{
	return (ft_strtoll(str, NULL));
}

int	number_error(char *argv[], int i)
{
	long long	x;
	char		*str;

	str = argv[i];
	if (is_an_int(str))
		return (0);
	x = ft_strtoll(str, NULL);
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	return (1);
}

int	check_error(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		return (1);
	}
	while (i < argc)
	{
		if (number_error(argv, i) == 0 || double_error(argv, i) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
