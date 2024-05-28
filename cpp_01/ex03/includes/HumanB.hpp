/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:52 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:37:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class HumanB
{
	private:
		std::string _name;
		Weapon _weapon;
	public:
		HumanB(/* args */);
		~HumanB();
		const std::string&	getName( void ) const;
		void			setName( std::string input );
};


