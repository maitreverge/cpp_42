/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:52 by flverge           #+#    #+#             */
/*   Updated: 2024/05/29 09:58:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Weapon;

class HumanB
{
	private:
		const std::string _name;
		Weapon _weapon;
	public:
		HumanB( const std::string inputName );
		~HumanB();
		void setWeapon( Weapon inputWeapon );
		void attack( void )const;
};


