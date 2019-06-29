/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_support.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 09:44:25 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/25 09:44:30 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Count rooms in rooms linked list
** @param t_room *head - start of linked list storing rooms
** @return int as rooms from the input file
*/

int		count_rooms(t_room *head)
{
	static int	count;

	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

/*
** @desc After encountering "##start" while reading input file,
** @desc save next line's first item as a string. It can later
** @desc be retrieved by passing NULL to this function as argument.
** @param char *room - starting room to be saved
** @return NULL when start room is passed and start room when NULL is passed
*/

char	*save_start(char *room)
{
	static char	*start;

	if (room != NULL && start == NULL)
	{
		start = ft_strdup(room);
		return (NULL);
	}
	else
		return (start);
}

/*
** @desc After encountering "##end" while reading input file,
** @desc save next line's first item as a string. It can later
** @desc be retrieved by passing NULL to this function as argument.
** @param char *room - end room to be saved
** @return NULL when end room is passed and end room when NULL is passed
*/

char	*save_end(char *room)
{
	static char	*end;

	if (room != NULL && end == NULL)
	{
		end = ft_strdup(room);
		return (NULL);
	}
	else
		return (end);
}

/*
** @desc Print ERROR and exit(1)
** @param void
** @return void
*/

void	quit(void)
{
	ft_printf("ERROR\n");
	exit(1);
}
