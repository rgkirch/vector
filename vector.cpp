#include <iostream>
// template <typename T>
class Vector {
	// T* elem;
	int* elem;
	int sz;
public:
	Vector() : sz{0}, elem{nullptr} {}
	//****************
	Vector(int size) : sz{size}, elem{new int[size]} {}
	//explicit Vector(int size) : sz{size}, elem{new int[size]} {}
	//****************
	int& operator[] (int index) {return elem[index];}
	int size() {return sz;}
};

int main( int argc, char* argv[] )
{
	// Vector vec = 100;
	//****************
	Vector vec = 100;
	// Vector vec(100);
	//****************
	std::cout << vec.size() << std::endl;
	std::cout << vec[0] << std::endl;
	vec[0] = 9;
	std::cout << vec[0] << std::endl;
	return 0;
}
