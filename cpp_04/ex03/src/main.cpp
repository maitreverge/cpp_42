/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:38:07 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 18:12:48 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main( void ){

	// Creating a new character
	ICharacter* me = new Character("me");

	// Creating a new Materia Source
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printColor(BOLD_BLUE, "Attempt to add a 5th Materia");
	
	// This will not add another Materia, because MateriaSource is full
	src->learnMateria(new Cure());

	// Creating a AMateria ptr

	AMateria* tmp;

	extraLine();
	
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	
	extraLine();
	
	
	tmp = src->createMateria("cure");
	extraLine();
	me->equip(tmp); // Equip index [1]
	me->equip(tmp); // Equip index [2]
	me->equip(tmp); // Equip index [3]
	
	printColor(BOLD_BLUE, "Attempt to equip character a 5th Materia");
	me->equip(tmp); // Equip index at full index, which will fails.
	
	// Creating another character
	ICharacter* bob = new Character("bob");
	
	extraLine();
	
	// Me using his index[0]  ob bob
	me->use(0, *bob);
	me->use(1, *bob);

	extraLine();
	
	// Bob trying to use his first index Materia on me, but will fail
	// Because bob has not Materia equiped yet.
	bob->use(0, *me);
	
	// Let's unequip INDEX 1, and try to use it straight afterwards
	me->unequip(1);
	me->use(1, *bob);// no surprise, this will fail

	/*
		Those next lines are made for testing the dump_size
		As the subject explicitely tells not to delete the unequiped Materia,
		I decided to store them in a `vector` like array, which has a limited size of 1000

		The following commented test target specifically this limit by throwing an error
	*/

	/*
	try
	{
		for (size_t i = 0; i < DUMP_SIZE + 1; ++i) // + 1 will raise an error
		{
			me->unequip(0);
			me->equip(tmp);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	*/
	
	delete bob;
	delete me;
	delete src;
	delete tmp;
	return 0;
}