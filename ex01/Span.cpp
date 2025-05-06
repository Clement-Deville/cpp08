/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:38:54 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/06 15:12:28 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Span::Span() : _max_size(0)
{
}

Span::Span(const Span &Cpy) : _max_size(Cpy._max_size), _numbers(Cpy._numbers)
{
}

Span::Span(unsigned int N): _max_size(N)
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
    std::cout << "This Span contains: " << B.getSize() << " elements, with " 
        << "a shortestPan of " << B.shortestSpan() << ", and a longestSpan of "
        << B.longestSpan();
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

unsigned int	Span::getSize(void) const
{
    return (this->_max_size);
}

std::multiset<int>	Span::getContainer(void) const
{
    return (this->_numbers);
}

/**------------------------------------------------------------------------
 *                             Methods
 *------------------------------------------------------------------------**/


//* ADD A NUMBER TO THE CLASS CONTAINER

void    Span::addNumber(const int nb_to_add)
{
     if (_numbers.size() == this->_max_size)
         throw std::out_of_range("Span: Out of capacity");
     this->_numbers.insert(nb_to_add);
}

//* USE A RANGE OF ITERATOR TO ADD NUMBERS TO THE CLASS CONTAINER
//! CAN THROW AN ERROR IF THE FINAL SIZE OF THE CONTAINER IS BIGER THAN MAX_SIZE

void    Span::addRange(std::multiset<int>::const_iterator first, 
            std::multiset<int>::const_iterator last)
{
    if (std::distance(first, last) + this->_numbers.size() == this->_max_size)
        throw std::out_of_range("Span: Out of capacity");
    this->_numbers.insert(first, last);
}

//* GIVE THE SMALLEST DISTANCE BETWEEN TWO NUMBERS IN OUR CONTAINER
//* RETURN 0 IF THERE IS LESS THAN TWO NUMBERS 
unsigned int    Span::shortestSpan() const
{
    unsigned int short_span;
    int          last_value;
    
    short_span = 0;
    last_value = 0;
    for (std::multiset<int>::const_iterator ite = this->_numbers.begin();
            ite != this->_numbers.end(); ite++)
    {
        if (ite != this->_numbers.begin() 
            && std::abs(*ite - last_value) > short_span)
            short_span = std::abs(*ite - last_value);
        last_value = *ite;
    }
    return (short_span);
}

//* GIVE THE LONGEST DISTANCE BETWEEN TWO NUMBERS IN OUR CONTAINER
//* RETURN 0 IF THERE IS LESS THAN TWO NUMBERS 

unsigned int    Span::longestSpan() const
{
    if (this->_numbers.size() < 2)
        return (0);
    return (*this->_numbers.begin() - *(--this->_numbers.end()));
}