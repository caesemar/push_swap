/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:36 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/24 20:25:15 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_error_check(char **argv,	int *space)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((ft_isdigit(argv[i][j]) == 1) || argv[i][j] == ' '
						|| argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (argv[i][j] == ' ')
					*space = 1;
				j++;
			}
			else
			{
				ft_putstr_fd("Error: not a digit or space on input\n", 2);
				exit(1);
			}
		}
		j = 0;
		i++;
	}
}

static void	ft_duplicate(char **argv, char *temp, int i, int j)
{
	char	**temp1;

	j++;
	while (argv[i])
	{
		temp1 = ft_split(argv[i], ' ');
		if (!temp1)
			return ;
		while (temp1[j])
		{
			if (temp1[j][0] == '+' ||
						(temp1 [j][0] == '-' && temp1[j][1] == '0'))
				temp1[j]++;
			if (temp[0] == '+')
				temp++;
			if (ft_strncmp(temp, temp1[j], ft_strlen(temp1[j])) == 0)
			{
				ft_putstr_fd("Error: number duplicated on input\n", 2);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	split_input(char **argv, t_stack **a, t_lst *new_node)
{
	int		i;
	char	**temp;
	int		j;

	j = -1;
	i = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		while (temp[++j])
		{
			ft_duplicate(argv, temp[j], i, j);
			*a = add_to_end(ft_atoi(temp[j]), *a);
		}
		j = -1;
		ft_free2d(temp);
	}
}

void	ft_input_checker(char **argv, t_stack **a, t_lst *new_node)
{
	int	space;

	space = 0;
	ft_error_check(argv, &space);
	//ft_duplicate_check(argv);
	split_input(argv, a, new_node);
}
