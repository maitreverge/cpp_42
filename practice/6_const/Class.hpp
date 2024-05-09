/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:22 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 09:59:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE
# define SAMPLE

#include <iostream>

class Sample {

public:
float const pi;
int			nb;

Sample(float const f);
~Sample(void);

void bar(void) const;
};

#endif