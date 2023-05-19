/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:44 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/19 01:03:21 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_numarg(int ac, char **av)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		while (av[i][nbr])
		{
			if (!(ft_isdigit(av[i][nbr]) || av[i][0] == '-'))
			{
				write(2, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			nbr++;
		}
		nbr = 0;
		i++;
	}
}

void	ft_is_doubled(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	temp2 = stack_a;
	while (temp)
	{
		temp2 = temp2->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
			{
				ft_delete_stack(&stack_a);
				write(2, "Error\n", 7);
				exit(EXIT_FAILURE);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = temp;
	}
}

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	temp2 = stack_a;
	while (temp2->next)
	{
		temp2 = temp->next;
		if (temp->value > temp2->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_checker(t_stack *stack_a)
{
	if (ft_is_sorted(stack_a))
	{
		ft_delete_stack(&stack_a);
		exit(EXIT_SUCCESS);
	}
	ft_is_doubled(stack_a);
}
