/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/17 23:18:42 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*new;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	while (argv[i] != NULL)
	{
		new = ft_lstnew((int *)ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		printf("%p", stack_a[i++]->content);
	}
	return (0);
}
