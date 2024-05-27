/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/27 01:19:55 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack sa;

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
	ft_free(&sa);

	return (0);
}
