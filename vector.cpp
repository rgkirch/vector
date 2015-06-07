// algo for copy
#include <algorithm>
// assert for assert
#include <assert.h>
#include "vector.hpp"
#define BASE_LENGTH 8

// default constructor
template <typename T>
//Vector<T>::Vector() : full{0}, allocated{BASE_LENGTH}, elem{new T[BASE_LENGTH]}
Vector<T>::Vector()
{
	full = 0;
	allocated = BASE_LENGTH;
	elem = new T[BASE_LENGTH];
}

// you can construct a vector of length 0
template <typename T>
Vector<T>::Vector( int new_full )
{
	assert( new_full >= 0 );
	if( new_full == 0 )
	{
		elem = nullptr;
		full = 0;
		allocated = 0;
	} else {
		elem = new T[new_full];
		full = 0;
		allocated = new_full;
	}
}

/*
// initializer constructor
template <typename T>
Vector<T>::Vector( std::initializer_list<T> init )
//Vector<T>::Vector( std::initializer_list<T> init ) : full{static_cast<unsigned int>( init.size() )}
{
	full = init.size();
	this.reserve ( full );
	for( auto& x : init )
	{
		this.push_back( x );
	}
}
*/

// copy constructor
template <typename T>
Vector<T>::Vector( const Vector<T>& other )
{
	Vector copy( other.size() );
	std::copy( other.begin(), other.end(), copy.begin() );
	/*
	for( int iter = 0; iter < copy.size(); ++iter )
	{
		copy[iter] = other[iter];
	}
	*/
	// I want to call the move assignment so that the object
	// constructed by this constructor call has the values
	// of other. Copy should be destructed at the end of
	// the scope of the constructor.
	this = std::move( copy );
}

// move constructor
template <typename T>
Vector<T>::Vector( Vector<T>&& other )
{
	elem = other.elem;
	full = other.full;
	allocated = other.allocated;
	other.elem = nullptr;
	other.full = 0;
	other.allocated = 0;
}

// copy assignment
template <typename T>
Vector<T>& Vector<T>::operator=( const Vector<T>& other )
{
	this->reserve( other.size() );
	std::copy( other.begin(), other.end(), this->begin() );
	/*
	for( int iter = 0; iter < full; ++iter )
	{
		// could say other[iter] and then each would be a function
		// call to the subscript operator
		elem[iter] = other.elem[iter]
	}
	*/
	full = other.full;
	allocated = other.allocated;
	return *this;
}

// move assignment
template <typename T>
Vector<T>& Vector<T>::operator=( Vector<T>&& other )
{
	elem = other.elem;
	full = other.full;
	allocated = other.allocated;
	other.elem = nullptr;
	other.full = 0;
	other.allocated = 0;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::reserve( int new_allocated )
{
	// must reserve larger should review this later, TODO
	assert( new_allocated > allocated );
	/* for every new, there must be a delete, maintain RAII */
	// reserve the new space
	T* new_elem = new T[ new_allocated ];
	// copy the values over to the new space
	std::copy( this->begin(), this->end(), new_elem );
	// free the old space
	delete[] elem;
	// save the new space into the object
	elem = new_elem;
	// update the max allocation
	allocated = new_allocated;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::push_back( T& item )
{
	assert( full <= allocated );
	if( full == allocated )
	{
		this->reserve( 2*allocated );
	}
	elem[full] = item;
	++full;
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}
