/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:27:51 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/09 16:21:19 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
	MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator
	MutantStack<T, Container>::end()
{

	return this->c.end();
}
template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
	MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
	MutantStack<T, Container>::end() const
{
	return this->c.end();
}

#endif //* MUTANT_STACK_TPP
