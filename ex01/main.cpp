/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/05 22:20:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "vector"
#include "deque"
#include "list"

int main( void )
{
	try
	{
		{
			std::cout <<
			"/**========================================================================\n" <<
			"*                           TESTING VECTOR\n" <<
			"*========================================================================**/" << std::endl;

			std::vector<int> test;

			std::cout << "Vector size is " << test.size() << std::endl;
			for (int i = 0; i < 10; i++)
				test.push_back(i);
			print_first_occurence_index(test, 8);
			print_first_occurence_index(test, 9);
			print_first_occurence_index(test, 10);
			print_first_occurence_index(test, -1);
		}
		{
			std::cout <<
			"/**========================================================================\n" <<
			"*                           TESTING DEQUE\n" <<
			"*========================================================================**/" << std::endl;

			std::deque<int> lol;

			std::cout << "Deque size is " << lol.size() << std::endl;
			for (int i = 0; i < 10; i++)
				lol.push_back(i);
			print_first_occurence_index(lol, 8);
			print_first_occurence_index(lol, 9);
			print_first_occurence_index(lol, 10);
			print_first_occurence_index(lol, -1);
		}
		{
			std::cout <<
			"/**========================================================================\n" <<
			"*                           TESTING LIST\n" <<
			"*========================================================================**/" << std::endl;

			std::list<int> a_list;

			std::cout << "List size is " << a_list.size() << std::endl;
			for (int i = 0; i < 10; i++)
				a_list.push_back(i);
			print_first_occurence_index(a_list, 8);
			print_first_occurence_index(a_list, 9);
			print_first_occurence_index(a_list, 10);
			print_first_occurence_index(a_list, -1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
