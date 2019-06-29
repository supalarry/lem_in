/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:15:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 16:15:13 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Given two dimensional array, free its arrays and pointer itself
** @param char **two_d - two dimensional array
** @return void
*/

void	free_two_d(char **two_d)
{
	int		i;

	i = 0;
	while (two_d[i] != NULL)
	{
		free(two_d[i]);
		i++;
	}
	if (two_d != NULL)
		free(two_d);
}
