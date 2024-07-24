/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_specialization.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:42:53 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 14:31:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

// Déclaration de la fonction template générique
template<typename T>
T max(const T& a, const T& b) {
    return (a >= b) ? a : b;
}

// Spécialisation de la fonction template pour les chaînes de caractères de type const char*
template<>
const char* max<const char*>(const char* const& a, const char* const& b) {
    return (std::strcmp(a, b) >= 0) ? a : b;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "max(10, 20): " << max(a, b) << std::endl;

    double x = 15.5;
    double y = 9.2;
    std::cout << "max(15.5, 9.2): " << max(x, y) << std::endl;

    const char* str1 = "apple";
    const char* str2 = "banana";
    std::cout << "max(\"apple\", \"banana\"): " << max(str1, str2) << std::endl;

    return 0;
}
