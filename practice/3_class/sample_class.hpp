/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:59:06 by flverge           #+#    #+#             */
/*   Updated: 2024/05/08 20:25:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

// CamelCase for class, snake_case for variables and functions

class Sample {

public:
int nb; // In a class, we can use variables
Sample(void);
~Sample(void);

// And we can also use function within a class

void ft_hello(void);
}; // DO NOT FORGET TO ; AT THE END OF THE CLASS


#endif