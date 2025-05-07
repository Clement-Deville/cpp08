/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:38:54 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:01 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Span::Span() : _max_size(0)
{
}

Span::Span(const Span &Cpy) : _max_size(Cpy._max_size), _numbers_set(Cpy._numbers_set)
{
}

Span::Span(const unsigned int N): _max_size(N)
{
}

Span::~Span()
{
}

/**------------------------------------------------------------------------
 *                             Operators
 *------------------------------------------------------------------------**/

std::ostream & operator<<(std::ostream &out, const Span &B)
{
    std::cout << "This Span contains: " << B.get_size() << " elements, has a maximum"
        << " size of " << B.get_max_size() << ", with a shortestPan of " << B.shortestSpan()
        << ", and a longestSpan of " << B.longestSpan();
    return (out);
}

Span & Span::operator=(const Span &Cpy)
{
    if (this == &Cpy)
        return *this;
    return (*this);
};

/**------------------------------------------------------------------------
 *                             Geters/Seters
 *------------------------------------------------------------------------**/

unsigned int	Span::get_max_size(void) const
{
    return (this->_max_size < this->_numbers_set.max_size() ?
		this->_max_size : this->_numbers_set.max_size());
}

std::multiset<int>	Span::get_numbers_set(void) const
{
    return (this->_numbers_set);
}

/**------------------------------------------------------------------------
 *                             Methods
 *------------------------------------------------------------------------**/

//* RETURN THE SIZE OF THE MULTISET OF NUMBERS

unsigned int	Span::get_size(void) const
{
    return (this->_numbers_set.size());
}

//* ADD A NUMBER TO THE CLASS CONTAINER

void    Span::addNumber(const int nb_to_add)
{
     if (_numbers_set.size() == this->_max_size)
         throw std::out_of_range("Span: Out of capacity");
     this->_numbers_set.insert(nb_to_add);
}

//* USE A RANGE OF ITERATOR TO ADD NUMBERS TO THE CLASS CONTAINER
//! CAN THROW AN ERROR IF THE FINAL SIZE OF THE CONTAINER IS BIGER THAN MAX_SIZE
//* USING ABSOLUTE ON DISTANCE CAUSE IT COULD BE NEGATIVE

void    Span::addRange(std::multiset<int>::const_iterator first,
            std::multiset<int>::const_iterator last)
{
    if (std::abs(std::distance(first, last)) + this->_numbers_set.size() == this->_max_size)
        throw std::out_of_range("Span: Out of capacity");
    this->_numbers_set.insert(first, last);
}

//* GIVE THE SMALLEST DISTANCE BETWEEN TWO NUMBERS IN OUR CONTAINER
//* RETURN 0 IF THERE IS LESS THAN TWO NUMBERS

unsigned long    Span::shortestSpan() const
{
    long short_span;
    long last_value;

    if (this->_numbers_set.size() < 2)
        return (0);
    short_span = std::abs(static_cast<long>(*(++(this->_numbers_set.begin())))
        - *this->_numbers_set.begin());
    last_value = 0;
    for (std::multiset<int>::const_iterator ite = this->_numbers_set.begin();
            ite != this->_numbers_set.end(); ite++)
    {
        if (ite != this->_numbers_set.begin()
            && std::abs(static_cast<long>(*ite) - last_value) < (long)short_span)
            short_span = std::abs(static_cast<long>(*ite) - last_value);
        last_value = *ite;
    }
    return (short_span);
}

//* GIVE THE LONGEST DISTANCE BETWEEN TWO NUMBERS IN OUR CONTAINER
//* RETURN 0 IF THERE IS LESS THAN TWO NUMBERS

unsigned long    Span::longestSpan() const
{
    if (this->_numbers_set.size() < 2)
        return (0);
    return (std::abs(static_cast<long>(*(--this->_numbers_set.end())) - *this->_numbers_set.begin()));
}
