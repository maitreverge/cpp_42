#pragma #once

class Test
{
private:


public:

	Test( void );
	Test( const Test& copy );
	Test& operator=( const Test& right_operator);
	~Test();

};

ostream& operator<<( ostream& output_stream, const Test& input );


// ---------- Functions declarations ---------------


Test::Test( void ){}


Test::Test( const Test& copy ){ *this = copy }


Test::~Test( void ){}


Test&::Testoperator=( const Test$ right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Test& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
