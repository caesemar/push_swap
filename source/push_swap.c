/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/26 01:41:27 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*new_node;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_input_checker(argv, &stack_a, new_node);
	print_stack(stack_a);
	/*
	printf("###SWAP####\n");
	swap(&stack_a);
	print_stack(stack_a);
	printf("###REVERSE_ROTATE####\n");
	reverse_rotate(&stack_a);
	print_stack(stack_a);
	printf("###ROTATE####\n");
	rotate(&stack_a);
	print_stack(stack_a);
	*/
	min_index(&stack_a);
	max_index(&stack_a);
	printf("###BEFORE####\n");
	print_stack(stack_a);
	printf("###AFTER####\n");
	//while (sorted(&stack_a) == 1)
		sort_long_stack(&stack_a, &stack_b, 25);
	print_stack(stack_a);
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
	else if (stack_size(a) > 10 && stack_size(a) < 300)
	{
		while (sorted(a) == 1)
			sort_long_stack(a, b, stack_size(a) / 4);
	}
	else
	{	
		while (sorted(a) == 1)
			sort_long_stack(a, b, stack_size(a) / 8);
	}
}
