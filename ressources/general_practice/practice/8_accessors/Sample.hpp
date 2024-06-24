/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:38:44 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 10:45:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample
{
	public:
		Sample(void);
		~Sample(void);

		/*
		! ces deux fonctions sont des accesseurs
		cad des fonctions "proxy" qui vont me permettre d'acceder et de modifier
		la valeur d'un attribut prive, et sur lequel je vais pouvoir exercer un controle
		*/
		int		getFoo(void) const; // constante car le get va simplement lire le _foo
		void	setFoo(int v);

	private:
		int	_foo;
};

#endif