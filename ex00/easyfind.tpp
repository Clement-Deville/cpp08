/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:23:14 by cdeville          #+#    #+#             */
/*   Updated: 2025/05/05 22:04:38 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

//* Ce modele de fonction traverse le conteneur grace a un iterateur explicite
//* et retourne la premiere occurence de nb_to_find dans la sequence, ou,
//* a defaut, retourne container.end().

template	<typename T>
typename T::const_iterator easyfind(const T& container, const int &nb_to_find)
{
	for (typename T::const_iterator ite = container.begin(); ite != container.end(); ite++)
	{
		if (*ite == nb_to_find)
			return (ite);
	}
	return container.end();
}

//* Ce modele de fonction affiche le resultat de easyfind

template	<typename T>
void	print_first_occurence_index(const T& container, const int &nb_to_find)
{
	typename T::const_iterator ite;

	ite = easyfind(container, nb_to_find);
	if (ite == container.end())
		std::cout << "The number " << nb_to_find << " is not present in this container." << std::endl;
	else
		std::cout << "The number " << nb_to_find << " is present first at index " << std::distance(container.begin(), ite) << std::endl;
}

#endif /* !EASYFIND_HPP */
