/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:10:08 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 11:00:16 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	while (i < length && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		return (&(((char *)s)[i]));
	}
	return (NULL);
}
