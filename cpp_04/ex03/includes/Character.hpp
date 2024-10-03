/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:19:26 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 13:32:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define DUMP_SIZE 1000

class Character : public ICharacter
{

private:

	Character( void );
	string			_name;
	AMateria*		_inventory[4];
	AMateria*		_dump[DUMP_SIZE];
	unsigned int	_dump_index;

public:
	
	Character( const string &nameInput );
	Character( Character& copy );
	Character& operator=( Character& right_operator );
	~Character();

	string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	AMateria* getInventory(const unsigned short i)const;
	AMateria* getDump(unsigned int i)const;
	
};

ostream& operator<<( ostream& output_stream, const Character& input );