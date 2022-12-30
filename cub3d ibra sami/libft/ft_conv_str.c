/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:05:20 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:56 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wdt_str(char *s, int len, t_opts opts)
{
	char	*new;

	new = ft_strnew(opts.wdt);
	ft_memset(new, ' ', opts.wdt);
	if (opts.flags.minus)
		ft_strncpy(new, s, len);
	else
		ft_strncpy(&new[opts.wdt - len], s, len);
	free (s);
	return (new);
}

static char	*ft_prc_str(char *s, t_opts opts)
{
	char	*new;

	new = ft_substr(s, 0, opts.prc);
	free (s);
	return (new);
}

int	ft_conv_str(char *s, t_opts opts)
{
	char	*new;
	int		len;

	if (!s)
		s = "(null)";
	new = ft_strdup(s);
	len = ft_strlen_int(new);
	if (opts.prc <= len && opts.prc)
		new = ft_prc_str(new, opts);
	len = ft_strlen_int(new);
	if (opts.wdt > len)
		new = ft_wdt_str(new, len, opts);
	if (opts.flags.dot && !opts.prc)
		ft_memset(new, ' ', len);
	if (opts.flags.dot && !opts.prc)
		len = 0;
	else
		len = ft_putstr_size(new);
	free(new);
	return (len);
}
