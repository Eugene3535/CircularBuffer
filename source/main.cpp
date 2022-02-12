#include "CircularBuffer.hpp"

#include <iostream>

int main()
{
	// The required minimum by example
	// 
	//Buffer<int> buffer({ 1,2,3,4 })
	// 
    //buffer.push_back(4);  // result must be 1234
    //buffer.push_front(0); // result must be 0123
    //buffer.push_back(5);  // result must be 1235
    //buffer.pop_front();   // result must be 235 
	// 
    //// Iterator`s supporting 
    //for (auto& value : buffer)
    //    std::cout << value;
	// 
    //buffer.size();    // result  3
    //buffer.max_size() // result  4
    //buffer.clear();   // void

	// case 1
	CircularBuffer<int> buffer { 1, 2, 3, 4 };
	
	std::cout << "Buffer initialized. Expected result : 1234 -> ";
	for (auto& value : buffer) 
		std::cout << value << ' ';
	std::cout << '\n';

	// case 2
	buffer.push_back(4);
	
	std::cout << "\nbuffer.push_back(4); Expected result : 1234 -> ";
	for (auto& value : buffer)
		std::cout << value << ' ';
	std::cout << '\n';

	// case 3
	buffer.push_front(0);

	std::cout << "\nbuffer.push_front(0); Expected result : 0123 -> ";
	for (auto& value : buffer)
		std::cout << value << ' ';
	std::cout << '\n';

	// case 4
	buffer.push_back(5);
	
	std::cout << "\nbuffer.push_back(5); Expected result : 1235 -> ";
	for (auto& value : buffer)
		std::cout << value << ' ';
	std::cout << '\n';

	// case 5
	buffer.pop_front();
	
	std::cout << "\nbuffer.pop_front(); Expected result : 235 -> ";
	for (auto& value : buffer)
		std::cout << value << ' ';
	std::cout << '\n';

	// case 6
	std::cout << "\nbuffer.size(); Expected result : 3 -> " << buffer.size() << '\n';

	// case 7
	std::cout << "\nbuffer.max_size(); Expected result : 4 -> " << buffer.max_size() << '\n';

	// case 8
	buffer.clear();

	std::cout << "\nbuffer.clear(); Expected result : -> ";
	for (auto& value : buffer)
		std::cout << value << ' ';
	std::cout << '\n';
	
	system("pause");

	return EXIT_SUCCESS;
}