/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heritage.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:30:03 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 11:52:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


using std::string;
using std::cin;
using std::cout;
using std::endl;

class Animal
{
private:
	string _name;
public:
	Animal(){std::cout << "Animal constructor called" << std::endl;};
	~Animal(){std::cout << "Animal destructor called" << std::endl;};
	void run( void )const{ cout << "\n\ncoucou\n\n" << endl;}
};

class Dog : public Animal
{
	private:
		string _name;
	
	public:
		Dog(){std::cout << "Dog constructor called" << std::endl;};
		~Dog(){std::cout << "Dog destructor called" << std::endl;};
};

//////////////////////

/*
! FINAL KEYWORD :

Sometimes, we create a class that is not designed to ever have a child class.
To clarify that intent, and have the compiler enforce it, we can add the final specifier to the class heading:
*/

class Actor {
public:
  void Render(){}
};

class Character : public Actor {
public:
  void Move(){}
  void Attack(){}
  void DropLoot(){}
};

class Goblin : public Character {
public:
  void Enrage(){}
};

class Dragon : public Character {
public:
  void Fly(){}
};

class Demon final {};

// Combining final with a base class
class Vampire final : public Character {};