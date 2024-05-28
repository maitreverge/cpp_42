/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:38:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


class HumanA
{
	private:
		std::string _name;
		Weapon _weapon;
	public:
		HumanA(/* args */);
		~HumanA();
		void	attack( void );
		const std::string&	getName( void ) const;
		void			setName( std::string input );
};


