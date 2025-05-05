/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/12/16 17:01:11 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "vector"

int main( void )
{
	try
	{
		std::vector<int> test;
		for (int i = 0; i < 10; i++)
			test.push_back(i);
	
		std::cout << *easyfind(test, 8) << std::endl;
		std::cout << *easyfind(test, 10) << std::endl;
		std::cout << "TEST" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
