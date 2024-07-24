/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 20:00:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

template < typename T >
class Array
{
    public:
        Array( void ): mainArray(NULL){} // Init a empty array, so init the pointer to NULL

        Array ( unsigned int n ) : mainArray(new T[n] ){
            
            // deep init each member to 0
            for (size_t i = 0; i < n; i++)
            {
                mainArray[i] = 0;
            }
        }

        // Copy constructor
        Array (const Array &copy) {

            int size = this->size();

            // deep copy instead of list init
            // which copy the pointer, then kinda links two classes
            for (size_t i = 0; i < size; i++)
            {
                this->mainArray[i] = copy.mainArray[i];
            }
        }

        // Operator= overload
        Array& operator=(const Array& right_operator){
            
            int size = this->size();

            // Same, deep copy
            if (this != right_operator){

                for (size_t i = 0; i < size; i++)
                {
                    this->mainArray[i] = right_operator.mainArray[i];
                }
            }
            return *this;            
        }

        // getter
        T &accessArray( const int &index )const{

            try
            {
                return this->mainArray[index];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Out of bounds accessing with accessArray" << endl;
            }
            
        }

        int size( void )const{

            // return sizeof(mainArray);


            int size = 0;

            while(1){

                T test;
                try
                {
                    test = this->mainArray[size++];
                }
                catch(const std::exception& e)
                {
                    break;
                }
                
            }
            return size;
        }
    
    private:
        T *mainArray;
};