#include <iostream>
#include "vector.cpp"
using namespace std;

int main( int argc, char* argv[] )
{
	Vector<int> vec(5);
	vec.reserve(8);
	vec[0] = 1;
	int a = 3;
	vec.push_back( a );
	//Vector<int> vec{1,2};
	cout << vec[0] << endl;
	return 0;
}
