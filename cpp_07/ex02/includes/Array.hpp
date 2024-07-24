/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:56:30 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/24 19:44:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
class Array
{
    public:
        Array( void ): mainArray(NULL){} // Init a empty array, so ini the pointer to NULL

        Array ( unsigned int n ) : mainArray(new T[n] ){
                
            for (size_t i = 0; i < n; i++)
            {
                mainArray[i] = 0;
            }
        }

        // constructeur de copie
        Array (const Array &copy) : {

            int size = this->size();

            // deep copy instead of list init
            // which copy the pointer, then kinda links two classes
            for (size_t i = 0; i < size; i++)
            {
                this->mainArray[i] = copy.mainArray[i]
            }
        }

        // surcharge operateur =
        Array& operator=(const Array& right_operator){
            
            int size = this->size();

            // Same, deep copy
            if (this != right_operator){

                for (size_t i = 0; i < size; i++)
                {
                    this->mainArray[i] = right_operator.mainArray[i]
                }
            }
            return *this;            
        }

        T &accessArray( const int &index ){

            try
            {
                return mainArray[i];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Out of bounds accessing with accessArray" << endl;
            }
            
        }

        int size( void )const{

            int size = 0;

            T test;

            while(1){

                try
                {
                    test = mainArray[size++];
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