#include "push_swap.h"

t_node	*lstlast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
        if(tmp->next)
		    tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

