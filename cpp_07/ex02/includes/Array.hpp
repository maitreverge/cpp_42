/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 10:54:12 by ubuntu           ###   ########.fr       */
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
        Array (const Array &copy) {

            int size = this->size();

            // deep copy instead of list init
            // which copy the pointer, then kinda links two classes
            for (int i = 0; i < size; i++)
            {
                this->_mainArray[i] = copy._mainArray[i];
            }
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
            
            int size = this->size();

            // Same, deep copy
            if (this != right_operator){

                for (size_t i = 0; i < size; i++)
                {
                    this->_mainArray[i] = right_operator._mainArray[i];
                }
            }
            return *this;            
        }

        int size( void )const{ return this->_size; }
    
    private:
        T   *_mainArray;
        int _size;
};