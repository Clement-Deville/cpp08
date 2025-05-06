/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:01 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/06 15:05:09 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>

class Span 
{
private:
    const unsigned int _max_size;
    std::multiset<int> _numbers;
    
public:
    Span();
	Span(const Span &Cpy);
	Span(unsigned int N);
    virtual ~Span();

	Span &operator=(const Span &Cpy);
    
    unsigned int    getSize(void) const;
    std::multiset<int>	getContainer(void) const;

    void            addNumber(const int nb_to_add);
    unsigned int    shortestSpan() const;
    unsigned int    longestSpan() const;
    void            addRange(std::multiset<int>::const_iterator first, 
        std::multiset<int>::const_iterator last); 
};

#endif //* SPAN_HPP
