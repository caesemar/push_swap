/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 03:52:00 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/22 03:57:12 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_lst	*node;
	t_lst	*next_node;
	t_stack	*next_stack;

	while (stack != NULL)
	{
		node = stack->first;
		while (node != NULL)
		{
			next_node = node->next;
			free(node);
			node = next_node;
		}
		next_stack = stack->next;
		free(stack);
		stack = next_stack;
	}
}
