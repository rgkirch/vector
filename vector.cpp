#include <iostream>

template <typename T>
class Vector {
	T* elem;
	unsigned int sz;
public:
	Vector() : sz{0}, elem{nullptr} {}
	explicit Vector(int size) : sz{size}, elem{new int[size]} {}
	Vector(std::initializer_list<T> init) : sz{static_cast<unsigned int>(init.size())}
	{
		for( int index = 0; index < sz; ++index )
		{
			elem[index] = init[index];
		}
	}
	T& operator[] (int index) {return elem[index];}
	const T& operator[] (int index) const {return elem[index];}
	int size() {return sz;}
	int* begin() {return elem;}
	int* end() {return elem+sz;}
	void hello();
};

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
