/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/06/05 13:36:25 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	sa;

	if (argc < 2)
		return (1);
	if (check_error(argc, argv) == 1)
		return (1);
	ft_stack_init(&sa, argc, argv);
	if (sa.a_size == 3)
		tiny_sort(&sa);
	else if (sa.a_size == 4)
		four_sort(&sa);
	else if (sa.a_size == 5)
		five_sort(&sa);
	else
		radix_sort(&sa);
	ft_free_init(&sa);
	return (0);
}
