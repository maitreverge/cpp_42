/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eee.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:49:35 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 14:08:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::exception;
using std::string;

class Test
{
public:
	Test(/* args */);
	~Test();
	class Test_error : public exception
	{
		public:
			const string hey(void) const { return "Error handled, hehehe"; } ;
	};
};

Test::Test(/* args */)
{
}

Test::~Test()
{
}

// const string& Test::Test_error::hey()const noexcept{ return "Error handled, hehehe"; }

int main(void){

	Test::Test_error t1;

	try
	{
		throw t1;
	}
	catch(Test::Test_error& e)
	{
		std::cerr << e.hey() << '\n';
	}
	
}
