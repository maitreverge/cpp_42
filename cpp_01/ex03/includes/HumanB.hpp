/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:52 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:46:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		string _name;
		Weapon* _weapon;
	public:
		HumanB( string inputName);
		~HumanB();
		void setWeapon( Weapon inputWeapon );
		void attack( void )const;
};


