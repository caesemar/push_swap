/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/27 04:37:19 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_input_checker(argv, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

void	sort_stack(t_lst **a, t_lst **b)
{
	if (stack_size(a) <= 3)
		three_elem(a);
	else if (stack_size(a) <= 10)
		less_than_ten_elem(a, b);
	else if (stack_size(a) == 100)
		sort_long_stack(a, b, stack_size(a) / 7);
	else if (stack_size(a) == 500)
		sort_long_stack(a, b, stack_size(a) / 15);
	else
		sort_long_stack(a, b, stack_size(a) / 7);
}
