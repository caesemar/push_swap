/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 03:52:00 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/25 19:42:48 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_stack(t_lst **stack)
{
	t_lst	*next_node;	
	t_lst	*current_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*stack = NULL;
}

int	duplicate_error(char **temp1, int status, int j)
{
	ft_putstr_fd("Error: number duplicated on input\n", 2);
	if (status == 1)
		temp1[j]--;
	ft_free2d(temp1);
	return (1);
}

void	ft_error(t_lst **stack_a)
{
	free_stack(stack_a);
	exit (1);
}
