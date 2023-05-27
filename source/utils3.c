/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:30:32 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/27 02:43:20 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_overflow(char *temp1, char *temp, int *error)
{
	if (ft_strncmp(temp1, temp, ft_strlen(temp)))
	{
		ft_putstr_fd("Error\n", 2);
		free (temp1);
		*error = *error + 1;
	}
}

void	input_overflow(char **argv, int i, int j, int error)
{
	char	**temp;
	char	*temp1;
	int		status;

	status = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		while (temp[++j])
		{
			temp1 = ft_itoa(ft_atoi(temp[j]));
			temp[j] = plus_on_input(temp[j], &status);
			ft_overflow(temp1, temp[j], &error);
			while (status-- != 0)
				temp[j]--;
			status = 0;
			if (error == 1)
				break ;
			free (temp1);
		}
		j = -1;
		ft_free2d(temp);
		if (error == 1)
			exit (1);
	}
}

void	index_assign(t_lst **a)
{
	t_lst	*temp;
	t_lst	*temp1;

	temp = *a;
	temp1 = temp;
	while (temp)
	{
		if (temp->index == 0)
		{
			while (temp1)
			{
				if (temp->content > temp1->content)
					temp->index++;
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
		temp1 = *a;
	}
}
