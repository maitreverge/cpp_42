/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:44 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 10:14:31 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Animal {
	
public:
    // Public nested class
    class Leg {
    
	private:
        int length;    // Private attribute
        bool hasClaws; // Private attribute
    
	public:
        // Constructor
        Leg(int length, bool hasClaws) : length(length), hasClaws(hasClaws) {}
        
        // Public method
        void showDetails() {
            std::cout << "Length: " << length << " cm, Has claws: " << (hasClaws ? "Yes" : "No") << std::endl;
        }
    };

    // Constructor
    Animal(std::string name) : name(name) {}

    // Method to add legs
    void addLeg(int length, bool hasClaws) {
        legs[numberOfLegs++] = Leg(length, hasClaws);
    }

    // Method to show animal details
    void showDetails() {
        std::cout << "Animal: " << name << std::endl;
        for (int i = 0; i < numberOfLegs; ++i) {
            std::cout << "Leg " << (i + 1) << ": ";
            legs[i].showDetails();
        }
    }

private:
    std::string name;   // Private attribute
    Leg legs[4];        // Array of Leg objects (maximum 4 legs)
    int numberOfLegs = 0; // Private attribute to keep track of the number of legs
};

int main() {
    // Create an Animal object
    Animal dog("Dog");

    // Add legs to the animal
    dog.addLeg(30, true);
    dog.addLeg(30, true);
    dog.addLeg(30, true);
    dog.addLeg(30, true);

    // Show animal details
    dog.showDetails();

    return 0;
}
