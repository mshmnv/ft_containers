#include "list.hpp"
#include <list>

int main() {

	std::list<int> stdList1;
	std::cout << "STD: " << stdList1.front() << " | " << stdList1.back() << std::endl; // 0
	ft::list<int> list1;
	std::cout << "FT:  " << list1.front() << " | " << list1.back() << std::endl; // seg

	std::cout << std::endl;

	std::list<int> stdList2(1, 10);
	std::cout << "STD: " << stdList2.front() << " | " << stdList2.back() << std::endl;
	ft::list<int> list2(1, 10);
	std::cout << "FT:  " << list2.front() << " | " << list2.back() << std::endl;

	std::cout << std::endl;

	std::list<int> stdList3;
	stdList3.push_back(1);
	stdList3.push_back(2);
	stdList3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	std::cout << "STD: " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ft::list<int> list3;
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	std::cout << "FT:  " << list3.front() << " | " << list3.back() << std::endl;

	std::cout << std::endl;

	std::cout << "STD: " << std::boolalpha << stdList3.empty() << " | " << stdList1.empty() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.empty() << " | " << list1.empty() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "STD: " << std::boolalpha << stdList3.size() << " | " << stdList1.size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.size() << " | " << list1.size() << std::endl;


	std::cout << std::endl;
	
	std::cout << "STD: " << std::boolalpha << stdList3.max_size() << " | " << stdList1.max_size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.max_size() << " | " << list1.max_size() << std::endl;
	
	std::cout << std::endl;

	stdList3.assign(3, 9);	
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	list3.assign(3, 9);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;


	return 0;
}