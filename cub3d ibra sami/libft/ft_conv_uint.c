/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:05:32 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:56 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_prc_uint(char *s, int len, t_opts opts)
{
	char	*new;

	new = ft_strnew(opts.prc);
	if (opts.prc > len)
	{
		ft_memset(new, '0', opts.prc);
		ft_strncpy(&new[opts.prc - len], s, len);
	}
	free(s);
	return (new);
}

static char	*ft_wdt_uint(char *s, int len, t_opts opts)
{
	char	*new;

	new = ft_strnew(opts.wdt);
	ft_memset(new, ' ', opts.wdt);
	if (opts.flags.zero && !opts.flags.minus && !opts.flags.dot)
		ft_memset(new, '0', opts.wdt);
	if (opts.flags.minus)
		ft_strncpy(new, s, len);
	else
		ft_strncpy(&new[opts.wdt - len], s, len);
	return (new);
}

int	ft_conv_uint(unsigned int n, t_opts opts)
{
	char	*s;
	char	*new;
	int		len;

	s = ft_itoa_unsigned(n);
	if (n == 0 && opts.flags.dot && !opts.prc)
	s[0] = '\0';
	len = ft_strlen_int(s);
	if (opts.prc > len)
	s = ft_prc_uint(s, len, opts);
	len = ft_strlen_int(s);
	if (opts.wdt > len)
	{
		new = ft_wdt_uint(s, len, opts);
		len = ft_putstr_size(new);
		free(new);
	}
	else
		len = ft_putstr_size(s);
	free(s);
	return (len);
}
