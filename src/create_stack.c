/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/17 18:49:35 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_create_new_node(int value)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	result->value = value;
	result->next = NULL;
	return (result);
}

t_stack	*ft_insert_at_head(t_stack **head, t_stack *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return (node_to_insert);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*temp;

	i = ac;
	stack_a = NULL;
	while (0 < i)
	{
		if (av[i])
		{
			temp = ft_create_new_node(ft_atoi(av[i]));
			ft_insert_at_head(&stack_a, temp);
		}
		i--;
	}
	return (stack_a);
}
