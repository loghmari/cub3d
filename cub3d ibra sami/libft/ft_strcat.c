/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:12:23 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:16:30 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	src_len;
	size_t	dst_len;

	if (!dst)
		return (ft_strdup(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst = (char *)ft_realloc(dst, src_len + dst_len + 1);
	ft_strcpy(dst + dst_len, src);
	return (dst);
}
