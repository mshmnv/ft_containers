#include "list.hpp"
#include <list>

int main() {
	std::list<int>::iterator ite;
	std::list<int>::iterator it;

	std::list<int> stdList1;
	std::cout << "STD: " << stdList1.front() << " | " << stdList1.back() << std::endl;
	ft::list<int> list1;
	std::cout << "FT:  " << list1.front() << " | " << list1.back() << std::endl << std::endl;

	std::list<int> stdList2(1, 10);
	std::cout << "STD: " << stdList2.front() << " | " << stdList2.back() << std::endl;
	ite = stdList2.end();
	for (it = stdList2.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	ft::list<int> list2(1, 10);
	std::cout << "FT:  " << list2.front() << " | " << list2.back() << std::endl;
	std::cout << list2 << std::endl;;

	std::list<int> stdList3;
	stdList3.push_back(1);
	stdList3.push_back(2);
	stdList3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	std::cout << "STD: " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	ft::list<int> list3;
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	list3.push_back(4);
	list3.push_back(5);
	std::cout << "FT:  " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	std::cout << "STD: " << std::boolalpha << stdList3.empty() << " | " << stdList1.empty() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.empty() << " | " << list1.empty() << std::endl << std::endl;
	
	std::cout << "STD: " << std::boolalpha << stdList3.size() << " | " << stdList1.size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.size() << " | " << list1.size() << std::endl;


	std::cout << std::endl;
	
	std::cout << "STD: " << std::boolalpha << stdList3.max_size() << " | " << stdList1.max_size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.max_size() << " | " << list1.max_size() << std::endl;

	std::cout << std::endl;

	stdList3.assign(3, 9);	
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.assign(3, 9);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	stdList3.clear();
	stdList3.push_back(1);
	stdList3.push_back(2);
	stdList3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	list3.clear();
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	list3.push_back(4);
	list3.push_back(5);

	stdList3.pop_front();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_front();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	stdList3.pop_back();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_back();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	stdList3.push_front(100);
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.push_front(100);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;
	
	std::cout << "STD: ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int>::iterator ft_ite;
	ft::list<int>::iterator ft_it;
	ft_ite = list3.end();
	for (ft_it = list3.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	// ft::list<int>::const_iterator ft_c_ite;
	// ft::list<int>::const_iterator ft_c_it;
	// ft_c_ite = list3.end();
	// for (ft_c_it = list3.begin(); ft_c_it != ft_c_ite; ft_c_it++)
	// 	std::cout << *ft_c_it << " ";
	// std::cout << std::endl;
	
	ft::list<int>::reverse_iterator ft_r_ite;
	ft::list<int>::reverse_iterator ft_r_it;
	ft_r_ite = list3.rend();
	for (ft_r_it = list3.rbegin(); ft_r_it != ft_r_ite; ft_r_it++)
		std::cout << *ft_r_it << " ";
	std::cout << std::endl;

	ft::list<int>::const_reverse_iterator ft_cr_ite;
	ft::list<int>::const_reverse_iterator ft_cr_it;
	ft_cr_ite = list3.rend();
	for (ft_cr_it = list3.rbegin(); ft_cr_it != ft_cr_ite; ft_cr_it++)
		std::cout << *ft_cr_it << " ";
	std::cout << std::endl;	

	return 0;
}