/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:21:23 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 18:33:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) { *this = cpy; }

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &right_operator)
{
	if (this != &right_operator)
		std::stack<T>::operator=(right_operator);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return (std::stack<T>::c.begin()); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return (std::stack<T>::c.end()); }