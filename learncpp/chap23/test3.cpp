#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include "intArray.h"
#include "../../utils.h"

int main (){

    IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getlength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getlength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

    return 0;
}