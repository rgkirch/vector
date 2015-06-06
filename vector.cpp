#include <iostream>
#include "vector.h"

template <typename T>
class Vector {
	T* elem;
	// number of full spots
	unsigned int size;
	// number of total spots
	unsigned int allocated;
public:
	Vector();
	explicit Vector( int );
	// initializer constructor (copies)
	Vector( std::initializer_list<T> );
	// copy constructor
	Vector( const Vector& );
	// move constructor
	Vector( Vector&& );
	// copy assignment
	Vector& operator=( const Vector& );
	// move assignment
	Vector& operator=( Vector&& );
	// destructor
	~Vector();
	// subscript - implemented here
	T& operator[] ( int index ) { return elem[index]; }
	// subscript - implemented here
	const T& operator[] ( int index ) const { return elem[index]; }
	// allocate that much space
	Vector& reserve( int );
	// append element to the end
	Vector& push_back( T& );
	// return number of full spots
	int size() { return size; }
	// begin and end allow the for each iterator to work
	// return pointer to array
	int* begin() { return elem; }
	// return pointer to one after end
	int* end() { return elem+size; }
};
