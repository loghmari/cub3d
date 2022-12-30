/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:04:45 by sloghmar          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:56 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv_char(int c, t_opts opts)
{
	int	len;

	len = 1;
	while (opts.wdt > 1 && !opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	ft_putchar(c);
	while (opts.wdt > 1 && opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	return (len);
}
