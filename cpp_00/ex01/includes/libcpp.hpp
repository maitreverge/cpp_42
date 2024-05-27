/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcpp.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:03 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 12:08:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBCPP_HPP__
#define __LIBCPP_HPP__

void	print( std::string str );
void	printNoEndl( std::string str );
void	printColor( std::string COLOR, std::string str );
void	printColorNoEndl( std::string COLOR, std::string str );
void	clearScreen( void );
void	definiveExit( void );
bool	validMenuPrompt( std::string prompt );
void	welcomePrinting( std::string message );
void	pleasePrompt( void );


#endif // __LIBCPP_HPP__