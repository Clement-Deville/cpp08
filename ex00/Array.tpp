/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:13:15 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/02 17:11:11 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#ifndef ARRAY_TPP
# define ARRAY_TPP

template< typename T> Array<T>::Array(): _size(0)
{
	std::cout << "\e[0;32mArray Default constructor called\e[0m" << std::endl;
	this->_my_array = new T[0];
}

template< typename T> Array<T>::Array(const unsigned int N): _size(N)
{
	std::cout << "\e[0;32mArray Size constructor called\e[0m" << std::endl;
	this->_my_array = new T[N];
}

template< typename T> Array<T>::Array(const Array &Cpy)
{
	std::cout << "\e[0;32mArray Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

template< typename T> Array<T> & Array<T>::operator=(const Array &Cpy)
{
	std::cout << "\e[0;32mArray Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_size = Cpy._size;
	this->_my_array = new T[this->_size]();
	for (unsigned int i = 0; i < this->_size; i++)
		this->_my_array[i] = Cpy._my_array[i];
	// verifier que l'initialisation est la bonne
	return (*this);
}

// Destroying object by deleting the array using delete [] operator

template< typename T> Array<T>::~Array()
{
	std::cout << "\e[0;31mArray Destructor called\e[0m" << std::endl;
	delete [] this->_my_array;
}

// Overloading Array subscript operator[], return a reference to the corresponding
// array element or, if index if out of bounds, throw an std::exception

template< typename T> T &Array<T>::operator[](const std::size_t idx)
{
	if (this->_size < idx)
		throw std::out_of_range("Out of range exception");
	return (this->_my_array[idx]);
}

template< typename T> unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template< typename T> T *Array<T>::get_array(void) const
{
	return (this->_my_array);
}

#endif
