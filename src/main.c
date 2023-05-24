/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:17:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/23 19:54:28 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2 && ft_strlen(av[1]) == 0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	else if (ac == 2 &&  !ft_isdigit(av[1][0]) && ft_strlen(av[1]) == 1)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	else if (ft_strnstr(av[1], "--", ft_strlen(av[1])))
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	ft_numarg(ac, av);
	stack_a = ft_create_stack(ac, av);
	ft_checker(stack_a);
	ft_algorithm(&stack_a, &stack_b);
	return (0);
}
