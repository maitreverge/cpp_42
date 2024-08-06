#include "iter.hpp"

class Awesome
{
    public:
        Awesome( void ) : _n(42) {return;}
        int get( void ) const {return  this->_n; }

    private:
        int _n;
};

std::ostream &operator<< ( std::ostream &o, Awesome const &rhs){

    o << rhs.get();
    return o;
}

template < typename T >
void my_print( T& x){

    std::cout << x << std::endl;
    return;
}

int main(){

    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter( tab, 5, my_print<const int>); // appel de fonction qui casse la tete
    iter( tab2, 5, my_print<Awesome>);

    return 0;
}