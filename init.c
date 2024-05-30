/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:56:57 by tguerran          #+#    #+#             */
/*   Updated: 2024/05/30 18:44:30 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_init(int ac, char **av, int *tab)
{
	char	**numbers;
	int		i;
	int		j;
	int		c;

	i = 1;
	c = 0;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j])
			tab[c++] = ft_atoi(numbers[j++]);
		free_split(numbers);
		i++;
	}
}

void	ft_init_sort(t_stack *s)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->sorted[i] > s->sorted[j])
			{
				temp = s->sorted[i];
				s->sorted[i] = s->sorted[j];
				s->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_sorted(t_stack *s)
{
	t_stacks	*tmp;
	int			i;

	i = 0;
	s->sorted = (int *)malloc(sizeof(int) * s->a_size);
	tmp = s->head_a;
	while (1)
	{
		s->sorted[i++] = tmp->data;
		tmp = tmp->next;
		if (tmp == s->head_a)
			break ;
	}
}

void	ft_init_index(t_stack *s)
{
	int			i;
	t_stacks	*temp;

	temp = s->head_a;
	while (1)
	{
		i = 0;
		while (i < s->a_size)
		{
			if (temp->data == s->sorted[i])
			{
				temp->data = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
		if (temp == s->head_a)
			break ;
	}
}

void	ft_stack_init(t_stack *s, int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;

	s->a_size = 0;
	s->b_size = 0;
	s->head_a = NULL;
	s->head_b = NULL;
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
			ft_push_back(s, numbers[j++]);
		free_split(numbers);
		i++;
	}
	if (ft_is_sorted(s))
		ft_free_init(s);
	ft_init_sorted(s);
	ft_init_sort(s);
	ft_init_index(s);
}
