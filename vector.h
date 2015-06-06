using namespace std;
#define BASE_LENGTH 8

// default constructor
template <typename T>
Vector<T>::Vector() : size{0}, allocated{BASE_LENGTH}, elem{new T[BASE_LENGTH]}
{}

// you can construct a vector of length 0
template <typename T>
Vector<T>::Vector( int new_size )
{
	assert( new_size >= 0 );
	if( new_size == 0 )
	{
		elem = nullptr;
		size = 0;
		allocated = 0;
	} else {
		elem = new T[new_size];
		size = new_size;
		allocated = 0;
	}
}

// initializer constructor
template <typename T>
Vector<T>::Vector( std::initializer_list<T> init ) : size{static_cast<unsigned int>( init.new_size() )}
{
	this.reserve ( size );
	for( auto& x : init )
	{
		this.push_back( x );
	}
}

// copy constructor
template <typename T>
Vector<T>::Vector( const Vector& operand )
{
	assert( operand.new_size() < size );
	for( int index = 0; index < size; ++index )
	{
		
	}
}

// move constructor
template <typename T>
Vector<T>::Vector( Vector&& operand )
{
	
}

// copy assignment
template <typename T>
Vector& Vector<T>::operand=( const Vector& );
{
	
}

// move assignment
template <typename T>
Vector& Vector<T>::operand=( Vector&& );
{
	
}

template <typename T>
Vector& Vector<T>::reserve( int new_size )
{
}

template <typename T>
Vector& Vector<T>::push_back( T& item )
{
	assert( size <= allocated );
	if( size == allocated )
	{
		Vector
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}
