/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:05:11 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:05:14 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wdt_ptr(char *s, int len, t_opts opts)
{
	char	*new;

	new = ft_strnew(opts.wdt);
	ft_memset(new, ' ', opts.wdt);
	if (opts.flags.minus)
		ft_strncpy(new, s, len);
	else
		ft_strncpy(&new[opts.wdt - len], s, len);
	free(s);
	return (new);
}

int	ft_conv_ptr(unsigned long n, t_opts opts)
{
	char	*s;
	int		len;

	s = ft_itoa_ptr(n);
	s = ft_insert_str(s, "0x", 0);
	len = ft_strlen_int(s);
	if (opts.wdt > len)
		s = ft_wdt_ptr(s, len, opts);
	len = ft_strlen_int(s);
	ft_putstr(s);
	free(s);
	return (len);
}
