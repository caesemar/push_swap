/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:36 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/26 23:35:04 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//hacer split o un una variable para ver que estamos en el caso de que j sea mayor q 0

static void	ft_error_check(char **argv)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	i = 1;
	while (argv[i])
	{
		sign = 1;
		while (argv[i][j])
		{
			if ((ft_isdigit(argv[i][j])) || argv[i][j] == ' '
						|| ((argv[i][j] == '+' || argv[i][j] == '-') \
						&& (ft_isdigit(argv[i][j + 1]) && sign == 1)))
			{
				j++;
				printf("entre\n");
			}
			else
			{
				ft_putstr_fd("Error: not a digit or space on input\n", 2);
				exit(1);
			}
			if(argv[i][j - 1] == '+' || argv[i][j - 1] == '-')
				sign = 0;
			if (argv[i][j - 1] == ' ')
				sign = 1;
		}
		j = 0;
		i++;
	}
}

static char	*plus_on_input(char *temp1, int *status)
{
	int	i;

	i = 0;
	while (*temp1 == '+' || (*temp1 == '-' && *(temp1 + 1) == '0') || \
		(*temp1 == '0' && *(temp1 + 1) != 0))
	{
		printf("hola\n");
		*status = *status + 1;
		temp1++;
		i++;
	}
	return (temp1);
}

static int	ft_duplicate(char **argv, char *temp, int i, int j)
{
	char	**temp1;
	int		status;

	status = 0;
	while (argv[i])
	{
		temp1 = ft_split(argv[i], ' ');
		while (temp1[j])
		{
			printf("temp1 antes: %s\n",temp1[j]);	
			temp1[j] = plus_on_input(temp1[j], &status);
			printf("temp: %s\n",temp);
			printf("temp 1: %s\n",temp1[j]);
			//temp = ft_temp(temp); 
			if (ft_strncmp(temp, temp1[j], ft_strlen(temp1[j])) == 0)
				return (duplicate_error(temp1, status, j));
			while (status-- != 0)
			{	
				temp1[j]--;
				printf("xd\n");
			}
			j++;
			status = 0;
		}
		ft_free2d(temp1);
		j = 0;
		i++;
	}
	return (0);
}

void	split_input(char **argv, t_lst **a, t_lst *new_node)
{
	int		i;
	char	**temp;
	int		j;
	int		error;

	error = 0;
	j = -1;
	i = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		while (temp[++j])
		{
			error = ft_duplicate(argv, temp[j], i, j + 1);
			if (error == 1)
				break ;
			add_to_end(ft_atoi(temp[j]), a);
		}
		j = -1;
		ft_free2d(temp);
		if (error == 1)
			ft_error(a);
	}
}

void	ft_input_checker(char **argv, t_lst **a, t_lst *new_node)
{
	ft_error_check(argv);
	split_input(argv, a, new_node);
}
