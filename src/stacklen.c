#include "../inc/push_swap.h"

int ft_stacklen(t_stack *head)
{
	t_stack *temp;
	int i;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}