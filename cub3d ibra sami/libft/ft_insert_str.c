/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:06:05 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:56 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_str(char *s, char *ins, int pos)
{
	char	*new;
	char	*swap;
	int		len;

	swap = ft_strnew(ft_strlen(s));
	ft_strncpy(swap, s, pos);
	len = ft_strlen(swap);
	ft_strcpy(swap + len, ins);
	len += ft_strlen(ins);
	ft_strcpy(swap + len, s + pos);
	new = ft_strcpy (s, swap);
	free (swap);
	return (new);
}
