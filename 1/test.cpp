#include "bit_vector.hpp"

#include <iostream>

using namespace std;


int
main(void)
{
	/*
	 *  2. How would you implement bit vectors using bitwise logical operations?
	 */

	BitVector<int> bv{0, 1, 2, 3, 4, 5};
	for (auto & i : bv)
		cout << i << '\n';
}
