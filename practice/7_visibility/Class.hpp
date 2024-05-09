/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:36:22 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 10:41:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE
# define SAMPLE

#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLD    "\033[1m"       /* Bold */

class Sample {

public:
int publicFoo;

Sample(void);
~Sample(void);

void publicBar(void) const;

private:
int _privateFoo;
// * It is a good convention to use _smth to name private attributes

void _privateBar(void) const;
};

#endif