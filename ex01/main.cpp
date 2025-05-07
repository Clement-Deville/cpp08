/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/07 13:55:51 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits.h>
#include <vector>

int main( void )
{
	try
	{
		{
			std::cout <<
			"/**========================================================================\n" <<
			"*                           TESTING CONSTRUCTORS\n" <<
			"*========================================================================**/" << std::endl;

			std::cout <<
			"/**=================================\n"
			"* Testing Default/Arg constructors\n"
			"*=================================**/" << std::endl;

			Span empty;
			std::cout << empty << std::endl;
			Span little(10);
			std::cout << little << std::endl;
			Span big(10000);
			std::cout << big << std::endl;
			const Span const_span(1);
			std::cout << const_span << std::endl;
			Span negative(-1);
			std::cout << negative << std::endl;

			std::cout << "OKAY." << std::endl;

			std::cout <<
			"/**=======================\n"
			"* Testing Copy constructor\n"
			"*========================**/" << std::endl;

			Span big_copy(big);
			std::cout << "This should be the same:" << std::endl;
			std::cout << big_copy << std::endl;
			std::cout << big << std::endl;
			std::cout << "==== END ====" << std::endl;

			Span const_copy(const_span);
			std::cout << "This should be the same:" << std::endl;
			std::cout << const_copy << std::endl;
			std::cout << const_span << std::endl;
			std::cout << "==== END ====" << std::endl;

			Span empty_copy(empty);
			std::cout << "This should be the same:" << std::endl;
			std::cout << empty_copy << std::endl;
			std::cout << empty << std::endl;
			std::cout << "==== END ====" << std::endl;

			std::cout << "OKAY." << std::endl;

			std::cout <<
			"/**========================================================================\n" <<
			"*                           TESTING METHODS\n" <<
			"*========================================================================**/" << std::endl;

			std::cout <<
			"/**=======================\n"
			"* Testing addNumber\n"
			"*========================**/" << std::endl;
			little.addNumber(3);
			little.addNumber(-1);
			std::cout << little <<  std::endl;
			std::cout << "==== END ====" << std::endl;

			std::cout << "Testing max int:" << std::endl;
			little.addNumber(INT_MAX);
			std::cout << little << std::endl;
			std::cout << "==== END ====" << std::endl;

			std::cout << "Testing min int with max int to detect possible OVERFLOWS:" << std::endl;
			little.addNumber(INT_MIN);
			std::cout << little <<  std::endl;
			std::cout << "==== END ====" << std::endl;

			std::cout << "Testing with negatives only:" << std::endl;
			big.addNumber(-10);
			big.addNumber(-100);
			std::cout << big <<  std::endl;
			std::cout << "==== END ====" << std::endl;

			try {
				std::cout << "Testing max_size exception:" << std::endl;
				Span very_small(2);
				very_small.addNumber(-10);
				std::cout << very_small <<  std::endl;
				very_small.addNumber(-100);
				std::cout << very_small <<  std::endl;
				very_small.addNumber(-100);
				std::cout << very_small <<  std::endl;
				std::cout << "===>> EXCEPTION IS NOT THROWED" << std::endl;
				std::cout << "==== END ====" << std::endl;
			}
			catch (const std::out_of_range &e)
			{
				std::cout << "===>> EXCEPTION CATCHED" << std::endl;
				std::cout << e.what() << std::endl;
				std::cout << "==== END ====" << std::endl;
			}

			std::cout <<
			"/**=======================\n"
			"* Testing addRange\n"
			"*========================**/" << std::endl;
			std::vector<int>	small_v;
			Span					small_span(2);

			try {
				small_v.push_back(-10);
				small_v.push_back(100);
				small_v.push_back(1000);
				std::cout << "Testing max_size exception:" << std::endl;
				std::cout << "==> Small vector size is " << small_v.size() << std::endl;
				std::cout << "==> Small span max size is " << small_span.get_max_size()
					<< std::endl;
				small_span.addRange(small_v.begin(), small_v.end());
				std::cout << "===>> EXCEPTION IS NOT THROWED" << std::endl;
				std::cout << "==== END ====" << std::endl;
			}
			catch (const std::exception &e) {
				std::cout << "===>> EXCEPTION CATCHED" << std::endl;
				std::cout << e.what() << std::endl;
				std::cout << "==== END ====" << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
