/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/22 05:44:48 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_lst	*new_node;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	ft_input_checker(argv, &stack_a, new_node);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}

//controlar numeros mayores de int?
