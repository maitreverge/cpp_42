/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:25:27 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 09:53:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void){

    // Declaring a Base class pointer
    Base *baseClass;

    // baseClass got either a base A, B or C base on ramdom value.
    baseClass = generate();

    Base &refBaseClass = *baseClass;

    identify(baseClass);

    identify(refBaseClass);

    delete baseClass;
}