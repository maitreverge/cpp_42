/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 13:27:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

template < typename T >
class Array
{
    public:
        Array( void ): _mainArray(NULL), _size(0){} // Init a empty array, so init the pointer to NULL

        Array ( unsigned int n ) : _mainArray(new T[n] ), _size(n) {
            
            // deep init each member to 0
            for (size_t i = 0; i < n; i++)
            {
                _mainArray[i] = 0;
            }
        }

        // Copy constructor
        Array (const Array &copy) : _mainArray(new T[copy._size]), _size(copy._size) {

            for (int i = 0; i < this->_size; i++)
            {
                this->_mainArray[i] = copy._mainArray[i];
            }
            
            *this = copy;
        }

        // Custom exception class
        class IndexOutOfRange : public exception
        {
            public:
                virtual const char* what() const throw() {

                    return ("Selected index is out of range");
                }
        };

        // [] operator overload
        T &operator[](const int &index){

            if (index >= this->_size or index < 0)
                throw IndexOutOfRange();
            return _mainArray[index];
        }

        // Operator= overload
        Array& operator=(const Array& right_operator){
            
            if (this != &right_operator){
                
                // Create a temp array in which we are going to deep init each member
                T* tempArray = new T[right_operator._size];
                
                for (int i = 0; i < right_operator._size; i++)
                {
                    tempArray[i] = right_operator._mainArray[i];
                }
                
                /*
                    Then we delete the old array if it does exists
                    !                   IMPORTANT
                    The condition
                    !               if (this->_mainArray)
                    is an unecessary check since deleting a NULL pointer is C++ okay.
                */
                delete[] this->_mainArray;
                
                this->_mainArray = tempArray;
                
                this->_size = right_operator._size;
            }
            return *this;           
        }

        int size( void )const{ return this->_size; }

        ~Array( void ){ delete[] _mainArray; }
    
    private:
        T   *_mainArray;
        int _size;
};