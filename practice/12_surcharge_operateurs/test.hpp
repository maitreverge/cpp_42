#pragma #once

class 
{
private:


public:

	( void );
	( const & copy );
	& operator=( const & right_operator);
	~();

};

ostream& operator<<( ostream& output_stream, const & input );


// ---------- Functions declarations ---------------


::( void ){}


::( const & copy ){ *this = copy }


::~( void ){}


&::operator=( const $ right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const & right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
