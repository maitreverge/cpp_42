/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:52 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:57:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		string _name;
		
		// Use a pointer, because HumanB may have no Weapon, and this attribute needs to be set at NULL.
		Weapon* _weapon;
	public:
		HumanB( string inputName);
		~HumanB();
		void setWeapon( Weapon& inputWeapon ); // takes the reference to the given Weapon.
		void attack( void )const;
};


