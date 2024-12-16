/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:23:14 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/16 16:53:13 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template	<typename T>
int	*easyfind(T container, int nb_to_find)
{
	for (int i = 0; i < T.size(); i++)
	{
		if (container[i] == nb_to_find)
			return (&container[i]);
	}
	return (NULL);
}
