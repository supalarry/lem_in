/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 10:19:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/14 10:19:39 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Iterate through steps array, where nth index stores a linked list
** @desc where each link consists of nth move within each path.
** @param t_steps **steps_array - array consisting linked list of moves
** @param int steps - number of steps that it takes to get all ants across
** @return void
*/

void	finally_print(t_steps **steps_array, int steps)
{
	int		i;
	t_steps	*current;
	t_steps	*copy;

	i = 0;
	ft_printf(copy_input(NULL));
	free(copy_input(NULL));
	ft_printf("\n");
	while (i < steps)
	{
		current = steps_array[i];
		while (current)
		{
			copy = current->next;
			ft_printf("%s", current->steps_line);
			free(current->steps_line);
			free(current);
			current = copy;
		}
		ft_printf("\n");
		i++;
	}
	free(steps_array);
	free(save_start(NULL));
	free(save_end(NULL));
}
