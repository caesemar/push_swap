/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:08:56 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/25 19:43:20 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free2d(char	**tofree)
{
	size_t	i;

	i = 0;
	while (tofree[i])
		free (tofree[i++]);
	free (tofree);
}

t_lst	*create_node(int content)
{
	t_lst	*node;

	node = (t_lst *) malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_to_end(int value, t_lst **s)
{
	t_lst	*new_node;
	t_lst	*current_node;

	new_node = create_node(value);
	if (*s == NULL)
		*s = new_node;
	else
	{
		current_node = *s;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}
