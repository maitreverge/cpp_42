/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:38:44 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:11:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample
{
	public:
		Sample(int v);
		~Sample(void);

		int		getFoo(void) const; // constante car le get va simplement lire le _foo
		int compare(Sample * other) const;

	private:
		int	_foo;
};

#endif