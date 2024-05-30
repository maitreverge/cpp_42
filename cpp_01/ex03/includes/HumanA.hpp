/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/30 11:47:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		const string _name;
		Weapon _weapon;
	public:
		HumanA(string const name, Weapon starterWeapon);
		~HumanA();
		void	attack( void );
		// const string&	getName( void ) const;
};


