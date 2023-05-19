/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:36:22 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/19 02:20:49 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

void	ft_printlist(t_stack *head, char *id)
{
	t_stack *temporary;
	temporary = head;
	printf("%s: ", id);
	  fflush( stdout );
	while(temporary != NULL)
	{
		printf("%d - ",temporary->value);
		  fflush( stdout );

		temporary = temporary->next;
	}
	printf("\n");
}


void	ft_movement(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa\n", 2))
		ft_sa(stack_a, 0);
	else if (!ft_strncmp(line, "sb\n", 2))
		ft_sb(stack_b, 0);
	else if (!ft_strncmp(line, "ss\n", 2))
		ft_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pa\n", 2))
		ft_pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pb\n", 2))
		ft_pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "ra\n", 2))
		ft_ra(stack_a, 0);
	else if (!ft_strncmp(line, "rb\n", 2))
		ft_rb(stack_b, 0);
	else if (!ft_strncmp(line, "rr\n", 2))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "rra\n", 3))
		ft_rra(stack_a, 0);
	else if (!ft_strncmp(line, "rrb\n", 2))
		ft_rrb(stack_b, 0);
	else if (!ft_strncmp(line, "rrr\n", 3))
		ft_rrr(stack_a, stack_b, 0);
	else
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
}


int	main(int ac, char **av)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	ft_numarg(ac, av);
	stack_a = ft_create_stack(ac, av);
	ft_checker(stack_a);
	// int i = 0;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, "\n", 1) == 0)
			break ;
		ft_movement(line, &stack_a, &stack_b);
		if ((ft_is_sorted(stack_a) && !stack_b))
			break ;
	}
	if (ft_is_sorted(stack_a))
	{
		write(1, "OK", 2);
	}
	else
		write(1, "KO", 2);
	return (0);
}