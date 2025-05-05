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

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template	<typename T> 
typename T::const_iterator easyfind(const T& container, const int &nb_to_find)
{
	for (typename T::const_iterator ite = container.begin(); ite != container.end(); ite++)
	{
		if (*ite == nb_to_find)
			return (ite);
	}
	throw std::out_of_range("Easyfind: No occurence find");
	return container.end();
}

#endif /* !EASYFIND_HPP */