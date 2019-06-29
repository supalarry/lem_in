/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 09:52:04 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/04 09:52:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlchr(char *s, char c, size_t len)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}
