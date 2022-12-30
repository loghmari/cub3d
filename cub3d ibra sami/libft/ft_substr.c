/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:27 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:16:30 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_s(char const *s, size_t len_max)
{
	size_t	len_s;

	if (!len_max)
		return (0);
	len_s = 0;
	while (s[len_s] && len_s < len_max)
		len_s++;
	return (len_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_len_s(s, start + len);
	if (len_s <= start)
		len_s = start;
	len_s = len_s - start;
	new_str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s + start, len_s);
	new_str[len_s] = '\0';
	return (new_str);
}
