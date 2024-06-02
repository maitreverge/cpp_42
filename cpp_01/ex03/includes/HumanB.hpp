/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:52 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:05:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class HumanB
{
	private:
		const string _name;
		Weapon* _weapon;
	public:
		HumanB( const string inputName, Weapon* inputWeapon=nullptr );
		~HumanB();
		void setWeapon( Weapon* inputWeapon );
		void attack( void )const;
};


