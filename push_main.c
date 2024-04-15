/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:28:08 by tguerran          #+#    #+#             */
/*   Updated: 2024/04/15 13:41:35 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	int		i;

	i = 1;
	if(check_error(argc, argv) == 1)
		return (1);
	stack_a = createStack();
	stack_b = createStack();
	while (i < argc)
	{
		pushdata(stack_a, (ft_atoi((argv[i]))));
		i++;
	}
	ft_printf(" \n b \n");
	printstack(stack_b);
	ft_printf("\n a \n");
	printstack(stack_a);
	pb(stack_b, stack_a);
    pb(stack_b, stack_a);
	ft_printf("\n b \n");
	printstack(stack_b);
	ft_printf(" \n a \n");
	printstack(stack_a);
	ft_printf("fin des instruction \n");
	return (0);
}