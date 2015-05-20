#include <iostream>

template <typename T>
class Vector {
	T* elem;
	unsigned int sz;
public:
	Vector();
	explicit Vector( int );
	Vector( std::initializer_list<T> );
	T& operator[] ( int index ) { return elem[index]; }
	const T& operator[] ( int index ) const { return elem[index]; }
	int size() { return sz; }
	int* begin() { return elem; }
	int* end() { return elem+sz; }
	void hello();
};

template <typename T>
Vector<T>::Vector() : sz{0}, elem{nullptr}
{}

template <typename T>
Vector<T>::Vector( int size ) : sz{size}, elem{new T[size]}
{}

template <typename T>
Vector<T>::Vector( std::initializer_list<T> init ) : sz{static_cast<unsigned int>( init.size() )}
{
	for( int index = 0; index < sz; ++index )
	{
		elem[index] = init[index];
	}
}

template <typename T>
void Vector<T>::hello()
{
	std::cout << "hello" << std::endl;
}

int main( int argc, char* argv[] )
{
	using namespace std;
	Vector<int> vec(10);
	vec.hello();
	cout << vec[0] << endl;
	return 0;
}
