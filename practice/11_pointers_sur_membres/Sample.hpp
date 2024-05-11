/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:38:44 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:51:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample
{
	public:
		int foo;
		
		Sample(void);
		~Sample(void);

		void bar(void) const;
};

#endif