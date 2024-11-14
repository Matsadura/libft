#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	t_list *head;
	int	value = 9;

	head = NULL;
	head = ft_lstnew(&value);
	printf("%d\n", *(int*)head->content);
	return (0);
}
