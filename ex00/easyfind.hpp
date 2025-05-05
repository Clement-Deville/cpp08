/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:59 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/05 22:04:42 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <iterator>

template	<typename T>
typename T::const_iterator	easyfind(const T& container, const int &nb_to_find);

template	<typename T>
void	print_first_occurence_index(const T& container, const int &nb_to_find);

#include "easyfind.tpp"
#endif /* !EASYFIND_HPP */
