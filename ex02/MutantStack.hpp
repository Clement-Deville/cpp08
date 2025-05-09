/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:25:01 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/09 16:30:46 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

/*================== Class defintion =================*/

/**----------------------------------------------
 * *                   INFO
 * Ici on declare le template ou T est le data type
 * contenu par notre pile, et Container et le type
 * de conteneur sous-jacent utilise par la pile
 * dont la signature est la meme que std::stack
 *
 * Notre classe herite de std::stack publiquement
 * pour avoir acces aux methodes requises,
 * mais aussi pour avoir acces au container sous-jacent 'c'
 * qui est curcial ici.
 *
 * Ainsi nous pouvons utiliser les methodes du container
 * sous jacent 'c' pour retourner un iterateur sur notre stack.
 *
 *---------------------------------------------**/

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator	begin();
	iterator	end();

	const_iterator	begin() const;
	const_iterator	end() const;
};

#include "MutantStack.tpp"
#endif //* MUTANT_STACK_HPP
