/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:53 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:55:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		string _name;
		Weapon& _weapon; // use a reference, because HumanA MUST have a Weapon.
	public:
		HumanA(string name, Weapon& starterWeapon);
		~HumanA();
		void	attack( void );
		const string&	getName( void ) const;
};


