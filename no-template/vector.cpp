#include "vector.hpp"
#define BASE_LENGTH 8

// default constructor
//Vector::Vector() : size{0}, allocated{BASE_LENGTH}, elem{new int[BASE_LENGTH]}
Vector::Vector()
{
	size = 0;
	allocated = BASE_LENGTH;
	elem = new int[BASE_LENGTH];
}

// you can construct a vector of length 0
Vector::Vector( int new_size )
{
	assert( new_size >= 0 );
	if( new_size == 0 )
	{
		elem = nullptr;
		size = 0;
		allocated = 0;
	} else {
		elem = new int[new_size];
		size = new_size;
		allocated = 0;
	}
}

// initializer constructor
Vector::Vector( std::initializer_list<int> init ) : size{static_cast<unsigned int>( init.new_size() )}
{
	this.reserve ( size );
	for( auto& x : init )
	{
		this.push_back( x );
	}
}

// copy constructor
Vector::Vector( const Vector& operand )
{
	assert( operand.new_size() < size );
	for( int index = 0; index < size; ++index )
	{
		
	}
}

// move constructor
Vector::Vector( Vector&& operand )
{
	
}

// copy assignment
Vector& Vector::operand=( const Vector& );
{
	
}

// move assignment
Vector& Vector::operand=( Vector&& );
{
	
}

Vector& Vector::reserve( int new_size )
{
}

Vector& Vector::push_back( int& item )
{
	assert( size <= allocated );
	if( size == allocated )
	{
		Vector
	}
}

Vector::~Vector()
{
	delete[] elem;
}
