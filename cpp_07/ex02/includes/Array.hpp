/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 12:44:40 by ubuntu           ###   ########.fr       */
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

            // int size = copy.size();

            // this->_mainArray = new T[size];

            // // deep copy instead of list init
            // // which copy the pointer, then kinda links two classes
            for (int i = 0; i < this->_size; i++)
            {
                this->_mainArray[i] = copy._mainArray[i];
            }
            
            // *this = copy;
        }

        class IndexOutOfRange : public exception
        {
            public:
                virtual const char* what() const throw() {

                    return ("Selected index is out of range");
                }
        };

        T &operator[](const int& index){

            if (index > this->_size)
                throw IndexOutOfRange();
            return _mainArray[index];
        }

        // Operator= overload
        Array& operator=(const Array& right_operator){
            
            if (this != &right_operator){
                
                T* tempArray = new T[right_operator._size];
                
                for (int i = 0; i < right_operator._size; i++)
                {
                    tempArray[i] = right_operator._mainArray[i];
                }
                
                delete[] this->_mainArray;
                
                this->_mainArray = tempArray;
                
                this->_size = right_operator._size;
            }
            return *this;           
        }

        int size( void )const{ return this->_size; }

        ~Array( void ){ delete [] _mainArray; }
    
    private:
        T   *_mainArray;
        int _size;
};