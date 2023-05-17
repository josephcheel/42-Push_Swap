/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reposition_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:16:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/17 18:25:32 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reposition_stack(t_stack *head)
{
	int		i;
	int		median;
	t_stack	*temp;

	i = 1;
	temp = head;
	median = ft_listsize(head) / 2;
	while (temp)
	{
		temp->pos = i;
		if (i <= median)
			temp->up = 1;
		else
			temp->up = 0;
		temp = temp->next;
		i++;
	}
}
