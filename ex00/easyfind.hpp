/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:08:59 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/16 16:55:35 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>

template	<typename T>
int	*easyfind(T container, int nb_to_find);

#include "easyfind.tpp"
#endif /* !EASYFIND_HPP */
