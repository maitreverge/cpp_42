/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:43 by flverge           #+#    #+#             */
/*   Updated: 2024/07/02 19:03:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <filesystem>

class ShrubberyCreationForm : public AForm
{

private:

	ShrubberyCreationForm( void ); // done
	string _target;

public:
	
	ShrubberyCreationForm( string targetInput ); // done
	ShrubberyCreationForm( const ShrubberyCreationForm& copy ); // done
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& right_operator );
	~ShrubberyCreationForm();

	const string&	getTarget( void )const;
	void			setTarget( string input );

	const string&	drawAsciiTree( void )const;

	void 			execute( const Bureaucrat& executor )const;

	class FileAlreadyExists : public exception
	{
		public:
			virtual const char* what( void )const throw();
	};


};

ostream& operator<<( ostream& output_stream, const ShrubberyCreationForm& input );


// ---------- Functions declarations ---------------

// AForm base constructor is in protected base class, but infine won't be used because private in the derived class
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(){}


ShrubberyCreationForm::ShrubberyCreationForm( string targetInput ) :
	AForm("Shrub Form", 145, 137),
	_target(targetInput){}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) :
	AForm( this->getName(), this->getRequiredGradeSign(), this->getRequiredGradeExecution()),
	_target(copy._target){}


/**
 * @brief Only the `_isFormSigned` could be reassigned
 * as it is the only non const value.
 * 
 * @param right_operator 
 * @return ShrubberyCreationForm& 
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value
		this->setIsFormSigned(right_operator.getIsFormSigned());
	}
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void ){}


// _target Setter and Getter
const string&	ShrubberyCreationForm::getTarget( void )const{ return this->_target; }
void			ShrubberyCreationForm::setTarget( string input ){ this->_target = input; }


void 			ShrubberyCreationForm::execute( const Bureaucrat& executor )const{

	string fileName = this->getTarget() + "_shrubbery";

	if (std::filesystem::exists(fileName))
		throw FileAlreadyExists();
	else if (!this->getIsFormSigned())
		throw AForm::AFormIsNotSigned();
	else if ( executor.getGrade() > this->getRequiredGradeExecution())
		throw Bureaucrat::GradeTooLowException();
	else {

		fstream file;
		try
		{
			file.open(fileName);
			file << this->drawAsciiTree();
			file.close();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}


const string& ShrubberyCreationForm::drawAsciiTree( void )const{
	
	string tree = "";
	
	tree += "      _-_\n";
	tree += "   /~~   ~~\\\n";
	tree += " /~~         ~~\\\n";
	tree += "{               }\n";
	tree += " \\  _-     -_  /\n";
	tree += "   ~    \\ //  ~\n";
	tree += "_- -   | | _- _\n";
	tree += "  _ -  | |   -_\n";
	tree += "       // \\\n";
	tree += "      //   \\\n";
	tree += "     //     \\\n";
	
	return tree;
}


const char* ShrubberyCreationForm::FileAlreadyExists::what( void )const throw(){ return "File with \"_shrubbery\" already exists."; }


ostream& operator<<( ostream& output_stream, const ShrubberyCreationForm& right_input ){

	output_stream << "ShrubberyCreationForm ";
	output_stream << CYAN << right_input.getName() << RESET;
	output_stream << (right_input.getIsFormSigned() ? BOLD_GREEN : BOLD_RED );
	output_stream << (right_input.getIsFormSigned() ? " is signed, " :  " is not signed, ");
	output_stream << RESET << endl;
	output_stream << "have a required Grade of ";
	output_stream << right_input.getRequiredGradeSign();
	output_stream << " for signing and a required Grade of ";
	output_stream << right_input.getRequiredGradeExecution();
	output_stream << " for being executed.";
	output_stream << endl;

	return output_stream;
}
