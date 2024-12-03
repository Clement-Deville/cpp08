/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:12:07 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/02 17:04:26 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <string>

template<typename T>
class Array
{
private:
	T	*_my_array;
	unsigned int _size;
public:
	Array();
	Array(const Array &Cpy);
	Array(unsigned int N);

	virtual ~Array();

	Array &operator=(const Array &Cpy);
	T &operator[](const std::size_t idx);
	unsigned int size(void) const;
	T *get_array(void) const;
};

# include "Array.tpp"

#endif
