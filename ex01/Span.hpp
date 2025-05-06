/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:01 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/06 17:38:18 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <cstdlib>

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
    void            addRange(std::multiset<int>::const_iterator first, 
        std::multiset<int>::const_iterator last); 
};

std::ostream & operator<<(std::ostream &out, const Span &B);

#endif //* SPAN_HPP
