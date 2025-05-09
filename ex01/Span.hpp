/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:01 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/09 12:31:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <cstdlib>

/*================== Class defintion =================*/

class Span
{
private:
    const unsigned int _max_size;
    std::multiset<int> _numbers_set;

public:
    Span();
	Span(const Span &Cpy);
	Span(const unsigned int N);
    virtual ~Span();

	Span &operator=(const Span &Cpy);

    unsigned int    get_max_size(void) const;
    std::multiset<int>	get_numbers_set(void) const;

    unsigned int    get_size(void) const;
    void            addNumber(const int nb_to_add);
    unsigned long    shortestSpan() const;
    unsigned long    longestSpan() const;
	template<typename Iterator>
    void            addRange(Iterator first, Iterator last);
};

std::ostream & operator<<(std::ostream &out, const Span &B);


/*================== Template Method =================*/

//* USE A RANGE OF ITERATOR TO ADD NUMBERS TO THE CLASS CONTAINER
//! CAN THROW AN ERROR IF THE FINAL SIZE OF THE CONTAINER IS BIGER THAN MAX_SIZE
//* USING ABSOLUTE ON DISTANCE CAUSE IT COULD BE NEGATIVE

template<typename Iterator>
void	Span::addRange(Iterator first, Iterator last)
{
	unsigned int	actual_max_size;

	actual_max_size = this->_max_size < this->_numbers_set.max_size() ?
		this->_max_size : this->_numbers_set.max_size();
    if (std::abs(std::distance(first, last)) + this->_numbers_set.size() > actual_max_size)
        throw std::out_of_range("Span: Out of capacity");
    this->_numbers_set.insert(first, last);
}

/*================== End Template Method =================*/

#endif //* SPAN_HPP
