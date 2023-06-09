/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 03:52:00 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/27 02:42:40 by jocasado         ###   ########.fr       */
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

int	duplicate_error(char **temp1, int status, int j, int liberar)
{
	if (liberar == 0)
		ft_putstr_fd("Error\n", 2);
	while (status)
	{
		temp1[j]--;
		status--;
	}
	ft_free2d(temp1);
	return (1);
}

void	ft_error(t_lst **stack_a)
{
	free_stack(stack_a);
	exit (1);
}

void	ft_error2(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

char	*ft_temp(char *temp1)
{	
	if ((*temp1 == '-' && *(temp1 + 1) == '0') && *(temp1 + 2))
	{
		while ((*temp1 == '-' || *(temp1) == '0') && *(temp1 + 1))
			temp1++;
		temp1--;
		temp1[0] = '-';
	}
	while (*temp1 == '+' || (*temp1 == '-' && *(temp1 + 1) == '0'
			&& *(temp1 + 2) == 0)
		|| (*temp1 == '0' && *(temp1 + 1) != 0))
		temp1++;
	return (temp1);
}
