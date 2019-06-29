/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   links_support.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 10:08:19 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/25 10:08:23 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc If information about pipe is encountered while reading
** @desc and storing information about rooms, save this information.
** @desc It also frees two d array items coming from rooms_list().
** @param char * line - stores information about the first pipe
** @return void
*/

char	*save_link(char *line, char **items)
{
	static char	*link;

	if (line != NULL && link == NULL)
	{
		free_two_d(items);
		link = ft_strdup(line);
		free(line);
		return (NULL);
	}
	else
		return (link);
}

/*
** @desc Initialise each pointer in links array to NULL
** @param t_hash **links - array of linked lists where each
** @param linked list stores neighbor of a specific room. This array
** @param is accessed after retrieving link_index of a room via hashtable
** @param int rooms_count - number of rooms in rooms linked list
** @return void
*/

void	links_null(t_link **links, int rooms_count)
{
	int	i;

	i = 0;
	while (i < rooms_count)
	{
		links[i] = NULL;
		i++;
	}
}

/*
** @desc Given a line storing link between two rooms in the form X-Y,
** @desc extract room X
** @param char * line - string storing information about the link
** @return char * as string containing room X
*/

char	*extract_room_1(char *line)
{
	int		i;
	char	*room_1;

	i = 0;
	while (line[i] != '-')
		i++;
	room_1 = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (line[i] != '-')
	{
		room_1[i] = line[i];
		i++;
	}
	room_1[i] = '\0';
	return (room_1);
}

/*
** @desc Given a line storing link between two rooms in the form X-Y,
** @desc extract room Y
** @param char * line - string storing information about the link
** @return char * as string containing room Y
*/

char	*extract_room_2(char *line)
{
	int		i;
	char	*room_2;

	i = 0;
	line = ft_strchr(line, '-') + 1;
	room_2 = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	while (*line != '\0')
	{
		room_2[i] = *line;
		line++;
		i++;
	}
	room_2[i] = '\0';
	return (room_2);
}

/*
** @desc Given arguments, find in which linked list of hashtable
** @desc does the room reside and then find the room in that list
** @desc to finally retrieve it's unique integer to access it's
** @desc neighbors in another array.
** @param int room_hash - index of hashtable that is retrieved
** @param after entering room's name into hashing function
** @param char *room_name - name of the room used to find it
** @param among other rooms that had the same room_hash
** @param t_hash **hashtable - array of linked lists where
** @param linked list at room_hash index stores rooms with equal
** @param hash values.
** @return link_index of a room if it's a valid room, otherwise -1
*/

int		hash_link(int room_hash, char *room_name, t_hash **hashtable)
{
	t_hash	*head;

	head = hashtable[room_hash];
	while (head != NULL && ft_strcmp(head->hash_name, room_name) != 0)
		head = head->next;
	if (head == NULL)
		return (-1);
	return (head->link_index);
}
