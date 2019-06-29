/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_support.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 14:11:43 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/15 14:11:47 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Initializes print_hub() functions variables
** @param int *i - address of integer storing current combination
** @param t_steps ***steps_array - address of array storing steps
** @param int steps - number of steps aka sizeof steps array
** @param int *a - address of variable storing index of first ant
** @return void
*/

void	print_hub_initialize(int *i, t_steps ***steps_array, int steps, int *a)
{
	*i = 0;
	*steps_array = create_steps_array(steps);
	*a = 1;
}
