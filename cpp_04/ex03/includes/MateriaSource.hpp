/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:04:31 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:24:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{

private:

	AMateria* _inventory[INVENTORY_SIZE];

public:

	MateriaSource( void );
	MateriaSource( MateriaSource& copy );
	MateriaSource& operator=( MateriaSource& right_operator );
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(const string& type);

	AMateria* getInventory(const unsigned short i);


};

