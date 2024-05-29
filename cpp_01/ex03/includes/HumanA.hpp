/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/29 18:19:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Weapon;

class HumanA
{
	private:
		const std::string _name;
		Weapon _weapon;
	public:
		HumanA(std::string const name, Weapon starterWeapon);
		~HumanA();
		void	attack( void );
		// const std::string&	getName( void ) const;
};


