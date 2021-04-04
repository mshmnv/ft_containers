#include "list.hpp"
#include <list>

int main() {
	std::list<int>::iterator ite;
	std::list<int>::iterator it;
	ft::list<int>::iterator ft_ite;
	ft::list<int>::iterator ft_it;
	std::list<int> stdList1;
	ft::list<int> list1;
	std::list<int> stdList3;
	ft::list<int> list3;
	std::list<int> stdList4;
	ft::list<int> list4;

	std::cout << "STD: " << stdList1.front() << " | " << stdList1.back() << std::endl;
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
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	list3.push_back(4);
	list3.push_back(5);
	std::cout << "FT:  " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	std::cout << std::endl << " -- EMPTY -- " << std::endl << std::endl;

	std::cout << "STD: " << std::boolalpha << stdList3.empty() << " | " << stdList1.empty() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.empty() << " | " << list1.empty() << std::endl << std::endl;

	std::cout << std::endl << " -- SIZE -- " << std::endl << std::endl;
	std::cout << "STD: " << std::boolalpha << stdList3.size() << " | " << stdList1.size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.size() << " | " << list1.size() << std::endl << std::endl;

	std::cout << std::endl << " -- MAX_SIZE -- " << std::endl << std::endl;
	std::cout << "STD: " << std::boolalpha << stdList3.max_size() << " | " << stdList1.max_size() << std::endl;
	std::cout << "FT:  " << std::boolalpha << list3.max_size() << " | " << list1.max_size() << std::endl << std::endl;

	std::cout << std::endl << " -- ASSIGN -- " << std::endl << std::endl;

	stdList3.assign(3, 9);	
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.assign(3, 9);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;



	std::cout << std::endl << " -- PUSH_BACK -- " << std::endl << std::endl;

	stdList3.clear();
	stdList3.push_back(1);
	stdList3.push_back(2);
	stdList3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	std::cout << "STD: ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	list3.clear();
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	list3.push_back(4);
	list3.push_back(5);
	std::cout << std::endl << "FT:  " << list3 << std::endl;


	std::cout << std::endl << " -- POP_FRONT -- " << std::endl << std::endl;


	stdList3.pop_front();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_front();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	std::cout << std::endl << " -- POP_BACK -- " << std::endl << std::endl;

	stdList3.pop_back();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_back();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;

	std::cout << std::endl << " -- PUSH_FRONT -- " << std::endl << std::endl;

	stdList3.push_front(100);
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << std::endl;
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.push_front(100);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << std::endl;
	std::cout << list3 << std::endl;
	

	std::cout << std::endl << " -- ITERATORS -- " << std::endl << std::endl;

	std::cout << "STD: ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft_ite = list3.end();
	for (ft_it = list3.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	std::cout << "STD: ";
	std::list<int>::const_iterator c_ite;
	std::list<int>::const_iterator c_it;
	c_ite = stdList3.end();
	for (c_it = stdList3.begin(); c_it != c_ite; c_it++)
		std::cout << *c_it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int>::const_iterator ft_c_ite;
	ft::list<int>::const_iterator ft_c_it;
	ft_c_ite = list3.end();
	for (ft_c_it = list3.begin(); ft_c_it != ft_c_ite; ft_c_it++)
		std::cout << *ft_c_it << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << "STD: ";
	std::list<int>::reverse_iterator r_ite;
	std::list<int>::reverse_iterator r_it;
	r_ite = stdList3.rend();
	for (r_it = stdList3.rbegin(); r_it != r_ite; r_it++)
		std::cout << *r_it << " ";
	std::cout << std::endl << "FT:  ";
	ft::list<int>::reverse_iterator ft_r_ite;
	ft::list<int>::reverse_iterator ft_r_it;
	ft_r_ite = list3.rend();
	for (ft_r_it = list3.rbegin(); ft_r_it != ft_r_ite; ft_r_it++)
		std::cout << *ft_r_it << " ";
	std::cout << std::endl << std::endl;;

	std::cout << "STD: ";
	std::list<int>::const_reverse_iterator cr_ite;
	std::list<int>::const_reverse_iterator cr_it;
	cr_ite = stdList3.rend();
	for (cr_it = stdList3.rbegin(); cr_it != cr_ite; cr_it++)
		std::cout << *cr_it << " ";
	std::cout << std::endl << "FT:  ";
	ft::list<int>::const_reverse_iterator ft_cr_ite;
	ft::list<int>::const_reverse_iterator ft_cr_it;
	ft_cr_ite = list3.rend();
	for (ft_cr_it = list3.rbegin(); ft_cr_it != ft_cr_ite; ft_cr_it++)
		std::cout << *ft_cr_it << " ";
	std::cout << std::endl << std::endl;

	std::cout << std::endl << " -- INSERT -- " << std::endl << std::endl;



	stdList4.insert(stdList4.begin(), 4);
	stdList4.insert(stdList4.begin(), 3);
	stdList4.insert(stdList4.begin(), 1);
	stdList4.insert(stdList4.end(), 5);
	ite = stdList4.begin();
	ite++;
	stdList4.insert(ite, 2);
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	
	list4.insert(list4.begin(), 4);
	list4.insert(list4.begin(), 3);
	list4.insert(list4.begin(), 1);
	list4.insert(list4.end(), 5);
	ft_ite = list4.begin();
	ft_ite++;
	list4.insert(ft_ite, 2);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	ite = stdList4.begin();
	ite++;
	ite++;
	stdList4.insert(ite, 10, 9);
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ft_ite = list4.begin();
	ft_ite++;
	ft_ite++;
	list4.insert(ft_ite, 10, 9);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;


	// ite = stdList4.begin();
	// stdList4.insert(ite, 10, 9);
	// std::cout << "STD: ";
	// ite = stdList4.end();
	// for (it = stdList4.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << "FT:  ";
	// ft_ite = list4.begin();
	// list4.insert(ft_ite, 10, 9);
	// ft_ite = list4.end();
	// for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl;


	// ite = stdList4.end();
	// stdList4.insert(ite, 10, 9);
	// std::cout << "STD: ";
	// ite = stdList4.end();
	// for (it = stdList4.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << "FT:  ";
	// ft_ite = list4.end();
	// list4.insert(ft_ite, 10, 9);
	// ft_ite = list4.end();
	// for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl;


	std::cout << std::endl << " -- INSERT W/ ITERATORS -- " << std::endl << std::endl;

	it = stdList4.begin();
	it++;
	it++;
	std::list<int> newStdList;
	std::cout << "STD: ";
	for (int i = 10; i < 20; i++)
		newStdList.push_back(i);
	ite = stdList4.end();
	stdList4.insert(it, newStdList.begin(), newStdList.end());
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft_it = list4.begin();
	ft_it++;
	ft_it++;
	ft::list<int> newList;
	for (int i = 10; i < 20; i++)
		newList.push_back(i);
	ft_ite = list4.end();

	list4.insert(ft_it, newList.begin(), newList.end());
	std::cout << list4 << std::endl;
	// for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl;

	// std::cout << std::endl << " -- SWAP -- " << std::endl << std::endl;

	// std::list<int> first(5, 100);
	// std::list<int> second(4, 200);
	// first.swap(second);
	// std::cout << "STD: ";
	// ite = first.end();
	// for (it = first.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << "| ";
	// ite = second.end();
	// for (it = second.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << "FT:  ";
	
	// ft::list<int> ft_first(5, 100);
	// ft::list<int> ft_second(4, 200);
	// ft_first.swap(ft_second);

	// ft_ite = ft_first.end();
	// for (ft_it = ft_first.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << "| ";
	// ft_ite = ft_second.end();
	// for (ft_it = ft_second.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl << std::endl;

	// std::list<int> third;
	// first.swap(third);
	// std::cout << "STD: ";
	// ite = first.end();
	// for (it = first.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << "| ";
	// ite = third.end();
	// for (it = third.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << "FT:  ";

	// ft::list<int> ft_third;
	// ft_first.swap(ft_third);
	// ft_ite = ft_first.end();
	// for (ft_it = ft_first.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << "| ";
	// ft_ite = ft_third.end();
	// for (ft_it = ft_third.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl << std::endl;

	// std::cout << std::endl << " -- RESIZE -- " << std::endl << std::endl;

	// std::list<int> list5;
	// for (int i = 0; i < 10; i++)
	// 	list5.push_back(i);
	// list5.resize(5, 100);
	// list5.resize(15, 100);
	// // list5.resize(1, 100);
	// std::cout << "STD: ";
	// ite = list5.end();
	// for (it = list5.begin(); it != ite; it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << "FT:  ";

	// ft::list<int> stdList5;
	// for (int i = 0; i < 10; i++) {
	// 	stdList5.push_back(i);
	// }
	// stdList5.resize(5, 100);
	// stdList5.resize(15, 100);
	// // stdList5.resize(1, 100);
	// ft_ite = stdList5.end();
	// for (ft_it = stdList5.begin(); ft_it != ft_ite; ft_it++)
	// 	std::cout << *ft_it << " ";
	// std::cout << std::endl << std::endl;


	return 0;
}
