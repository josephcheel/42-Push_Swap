
#include "../inc/push_swap.h"

t_stack	*ft_create_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		i;

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