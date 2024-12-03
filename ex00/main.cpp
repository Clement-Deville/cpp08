/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/02 17:56:29 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include "Array.hpp"

template<typename T>
void	print(T &param)
{
	std::cout << param << std::endl;
}

int main( void )
{
	{
	std::cout <<
	"/**========================================================================\n" <<
	"*               TESTING ARRAY OF INT OF SIZE 8\n" <<
	"*========================================================================**/\n"
		<< std::endl;
	Array<int> int_array(8);

	for (unsigned int i = 0; i < int_array.size(); i++)
		int_array[i] = i;


	::iter(int_array.get_array(), int_array.size(), print<const int>);

	std::cout << "Size of the array is: " << int_array.size() << std::endl;


	std::cout <<
	"/**========================================================================\n" <<
	"*               TESTING COPY CONSTRUCTOR\n" <<
	"*========================================================================**/\n"
		<< std::endl;
	Array<int> int_array_copy(int_array);

	for (unsigned int i = 0; i < int_array_copy.size(); i++)
		int_array_copy[i] = i;

	::iter(int_array_copy.get_array(), int_array_copy.size(), print<const int>);

	std::cout << "Size of the array is: " << int_array_copy.size() << std::endl;

	std::cout <<
	"/**========================================================================\n" <<
	"*               MODIFYING COPY \n" <<
	"*========================================================================**/\n"
		<< std::endl;

	for (unsigned int i = 0; i < int_array_copy.size(); i++)
		int_array_copy[i] = -i;

	std::cout << "Copy: " << std::endl;

	::iter(int_array_copy.get_array(), int_array_copy.size(), print<const int>);

	std::cout << "Original: " << std::endl;

	::iter(int_array.get_array(), int_array.size(), print<const int>);

	std::cout <<
	"/**========================================================================\n" <<
	"*                      TESTING BAD INDEX ACCESS\n" <<
	"*========================================================================**/\n"
		<< std::endl;

	try
	{
		int_array[10] = 1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	}

	{
		std::cout <<
		"/**========================================================================\n" <<
		"*                      TESTING CONST TYPE ALLOC\n" <<
		"*========================================================================**/\n"
			<< std::endl;

		Array<const std::string> const_array(8);
	}
	{
		std::cout <<
		"/**========================================================================\n" <<
		"*                      TESTING EMPTY ARRAY\n" <<
		"*========================================================================**/\n"
			<< std::endl;

		Array<const std::string> empty;

		std::cout << "Empty array size: " << empty.size() << std::endl;
	}
	return (0);
}
