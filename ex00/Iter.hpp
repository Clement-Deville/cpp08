/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:24:19 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 16:11:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>

template<typename T, typename F>
void iter(const T &array, size_t lenght, void (f)(F param))
{
	for (size_t i = 0; i < lenght; i++)
		f((F)array[i]);
}

#endif /* !ITER_HPP */
