/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/15 22:56:48 by jocasado         ###   ########.fr       */
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
	printf("###SWAP####\n");
	swap(&stack_a);
	print_stack(stack_a);
	printf("###REVERSE_ROTATE####\n");
	reverse_rotate(&stack_a);
	print_stack(stack_a);
	printf("###ROTATE####\n");
	rotate(&stack_a);
	print_stack(stack_a);
	min_index(&stack_a);
	max_index(&stack_a);
	printf("###BEFORE####\n");
	print_stack(stack_a);
	printf("###AFTER####\n");
	three_elem(&stack_a);	
	print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
