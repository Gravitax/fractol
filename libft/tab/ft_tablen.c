/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:03:11 by maboye            #+#    #+#             */
/*   Updated: 2019/06/20 17:33:16 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_tablen(void **add)
{
	int		i;

	i = 0;
	while (add && add[i])
		++i;
	return (i);
}
