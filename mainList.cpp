#include "list.hpp"
#include <list>
#include <cmath>

// FOR REMOVE_IF
bool single_digit(const int& value) { return (value<10); }
struct is_odd { bool operator()(const int& value) { return (value%2)==1; } };

// FOR UNIQUE
bool same_integral_part(double first, double second) { return ( int(first)==int(second) ); }
struct is_near{ bool operator()(double first, double second) { return (fabs(first-second)<5.0); } };

// FOR MERGE
bool mycomparison(double first, double second) { return ( int(first)<int(second) ); }

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

	std::cout << std::endl << " -- FRONT -- BACK -- " << std::endl << std::endl;

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
	ft_it = list2.begin();
	for (ft_ite = list2.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	stdList3.push_back(1);
	stdList3.push_back(2);
	stdList3.push_back(3);
	stdList3.push_back(4);
	stdList3.push_back(5);
	std::cout << "STD: " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.push_back(1);
	list3.push_back(2);
	list3.push_back(3);
	list3.push_back(4);
	list3.push_back(5);
	std::cout << "FT:  " << list3.front() << " | " << list3.back() << " | ";
	ft_it = list3.begin();
	for (ft_ite = list3.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::list<int> stdOne(stdList3.begin(), stdList3.end());
	std::cout << "STD: " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdOne.end();
	for (it = stdOne.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	ft::list<int> ftOne(list3.begin(), list3.end());
	std::cout << "FT:  " << list3.front() << " | " << list3.back() << " | ";
	ft_ite = ftOne.end();
	for (ft_it = ftOne.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

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
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.assign(3, 9);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << " | ";
	ft_ite = list3.end();
	for (ft_it = list3.begin(); ft_it != ft_ite; ft_it++ )
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;
	std::list<int> stdNew;
	for (int i = 0; i < 15; i++)
		stdNew.push_back(i);
	stdList3.assign(stdNew.begin(), stdNew.end());
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::list<int> ftNew;
	for (int i = 0; i < 15; i++)
		ftNew.push_back(i);
	list3.assign(ftNew.begin(), ftNew.end());
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << " | ";
	ft_ite = list3.end();
	for (ft_it = list3.begin(); ft_it != ft_ite; ft_it++ )
		std::cout << *ft_it << " ";
	std::cout << std::endl;


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
	std::cout << std::endl << "FT:  ";
	ft_it = list3.begin();
	for (ft_ite = list3.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;


	std::cout << std::endl << " -- POP_FRONT -- " << std::endl << std::endl;


	stdList3.pop_front();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_front();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << " | ";
	ft_it = list3.begin();
	for (ft_ite = list3.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- POP_BACK -- " << std::endl << std::endl;

	stdList3.pop_back();
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.pop_back();
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << " | ";
	ft_it = list3.begin();
	for (ft_ite = list3.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;


	std::cout << std::endl << " -- PUSH_FRONT -- " << std::endl << std::endl;

	stdList3.push_front(100);
	std::cout << "STD: " << stdList3.size() << " | " << stdList3.front() << " | " << stdList3.back() << " | ";
	ite = stdList3.end();
	for (it = stdList3.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	list3.push_front(100);
	std::cout << "FT:  " << list3.size() << " | " << list3.front() << " | " << list3.back() << " | ";
	ft_it = list3.begin();
	for (ft_ite = list3.end(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;
	

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
	stdList4.insert(stdList4.end(), 6);
	stdList4.insert(stdList4.end(), 7);
	stdList4.insert(stdList4.end(), 8);

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
	list4.insert(list4.end(), 6);
	list4.insert(list4.end(), 7);
	list4.insert(list4.end(), 8);
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
	stdList4.insert(ite, 10, 0);
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ft_ite = list4.begin();
	ft_ite++;
	ft_ite++;
	list4.insert(ft_ite, 10, 0);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	std::list<int> n;
	for (int i = 0; i < 10; i++)
		n.push_back(i);
	n.insert(n.begin(), n.begin(), n.end());
	std::cout << "STD: ";
	ite = n.end();
	for (it = n.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> m;
	for (int i = 0; i < 10; i++)
		m.push_back(i);
	m.insert(m.begin(), m.begin(), m.end());
	ft_ite = m.end();
	for (ft_it = m.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	ite = stdList4.begin();
	stdList4.insert(ite, 10, 9);
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ft_ite = list4.begin();
	list4.insert(ft_ite, 10, 9);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	ite = stdList4.end();
	stdList4.insert(ite, 10, 9);
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ft_ite = list4.end();
	list4.insert(ft_ite, 10, 9);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;


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
	// stdList4.insert(stdList4.end(), newStdList.begin(), newStdList.end());

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
	// list4.insert(list4.end(), newList.begin(), newList.end());

	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- SWAP -- " << std::endl << std::endl;

	std::list<int> first(5, 100);
	std::list<int> second(4, 200);
	first.swap(second);
	std::cout << "STD: ";
	ite = first.end();
	for (it = first.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = second.end();
	for (it = second.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> ft_first(5, 100);
	ft::list<int> ft_second(4, 200);
	ft_first.swap(ft_second);

	ft_ite = ft_first.end();
	for (ft_it = ft_first.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ft_second.end();
	for (ft_it = ft_second.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	std::list<int> third;
	first.swap(third);
	std::cout << "STD: ";
	ite = first.end();
	for (it = first.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = third.end();
	for (it = third.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> ft_third;
	ft_first.swap(ft_third);
	ft_ite = ft_first.end();
	for (ft_it = ft_first.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ft_third.end();
	for (ft_it = ft_third.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	std::cout << std::endl << " -- RESIZE -- " << std::endl << std::endl;

	std::list<int> stdList5;
	for (int i = 0; i < 10; i++)
		stdList5.push_back(i);
	stdList5.resize(5, 100);
	stdList5.resize(15, 100);
	// stdList5.resize(1, 100);
	std::cout << "STD: ";
	ite = stdList5.end();
	for (it = stdList5.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> list5;
	for (int i = 0; i < 10; i++)
		list5.push_back(i);
	list5.resize(5, 100);
	list5.resize(15, 100);
	// list5.resize(1, 100);
	ft_ite = list5.end();
	for (ft_it = list5.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;

	std::cout << std::endl << " -- ERASE -- " << std::endl << std::endl;


	stdList4.erase(++stdList4.begin());
	stdList4.erase(stdList4.begin());
	stdList4.erase(--stdList4.end());
	std::cout << "STD: ";
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	it = stdList4.begin();
	ite = stdList4.begin();
	ite++;
	ite++;
	ite++;
	stdList4.erase(it, ite);
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	stdList4.erase(stdList4.begin(), stdList4.end());
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "|" << std::endl << "FT:  ";


	list4.erase(++list4.begin());
	list4.erase(list4.begin());
	list4.erase(--list4.end());
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_it = list4.begin();
	ft_ite = list4.begin();
	ft_ite++;
	ft_ite++;
	ft_ite++;
	list4.erase(ft_it, ft_ite);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++) {
		std::cout << *ft_it << " ";
	}
	std::cout << "| ";
	list4.erase(list4.begin(), list4.end());
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++) {
		std::cout << *ft_it << " ";
	}
	std::cout << "| " << std::endl;

	std::cout << std::endl << " -- SPLICE -- " << std::endl << std::endl;

	std::list<int> stdSecond;
	for (int i = 10; i < 20; i++)
		stdSecond.push_back(i);
	for (int i = 0; i < 5; i++)
		stdList4.push_back(i);
	std::cout << "STD: ";
	it = stdList4.begin(); it++; it++;
	stdList4.splice(it, stdSecond);
	// stdList4.splice(stdList4.end(), stdSecond);
	// stdList4.splice(--stdList4.end(), stdSecond);
	// stdList4.splice(stdList4.begin(), stdSecond);

	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdSecond.end();
	for (it = stdSecond.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	for (int i = 0; i < 10; i++)
		stdSecond.push_back(99);
	it = stdList4.begin();
	it++;
	it++;
	stdList4.splice(stdList4.begin(), stdSecond);
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";

	std::cout << std::endl << "FT:  ";

	ft::list<int> ftSecond;
	for (int i = 10; i < 20; i++)
		ftSecond.push_back(i);
	for (int i = 0; i < 5; i++)
		list4.push_back(i);
	ft_it = list4.begin(); ft_it++; ft_it++;
	list4.splice(ft_it, ftSecond);
	// list4.splice(list4.end(), ftSecond);
	// list4.splice(--list4.end(), ftSecond);
	// list4.splice(list4.begin(), ftSecond);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftSecond.end();
	for (ft_it = ftSecond.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	for (int i = 0; i < 10; i++)
		ftSecond.push_back(99);
	ft_it = list4.begin();
	ft_it++;
	ft_it++;
	list4.splice(list4.begin(), ftSecond);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;


	std::list<int> stdNew1;
	for (int i = 0; i < 5; i++)
		stdNew1.push_back(i);
	stdSecond.splice(stdSecond.begin(), stdNew1);
	std::cout << "STD: ";
	ite = stdSecond.end();
	for (it = stdSecond.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> ftNew1;
	for (int i = 0; i < 5; i++)
		ftNew1.push_back(i);
	ftSecond.splice(ftSecond.begin(), ftNew1);
	ft_ite = ftSecond.end();
	for (ft_it = ftSecond.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::list<int>	stdFirst;
	for (int i = 10; i < 20; i++)
		stdFirst.push_back(i);
	ite = stdFirst.end(); ite--; ite--;
	stdSecond.splice(stdSecond.begin(), stdFirst, ite);
	ite = --stdFirst.end();
	stdSecond.splice(++stdSecond.begin(), stdFirst, ite);
	ite = stdFirst.begin();
	stdSecond.splice(stdSecond.end(), stdFirst, ite);
	stdSecond.splice(stdSecond.end(), stdFirst, --ite);
	std::cout << "STD: ";
	ite = stdFirst.end();
	for (it = stdFirst.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdSecond.end();
	for (it = stdSecond.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ft::list<int>	ftFirst;
	for (int i = 10; i < 20; i++)
		ftFirst.push_back(i);
	ft_ite = ftFirst.end(); ft_ite--; ft_ite--;
	ftSecond.splice(ftSecond.begin(), ftFirst, ft_ite);
	ft_ite = --ftFirst.end();
	ftSecond.splice(++ftSecond.begin(), ftFirst, ft_ite);
	ft_ite = ftFirst.begin();
	ftSecond.splice(ftSecond.end(), ftFirst, ft_ite);
	ftSecond.splice(ftSecond.end(), ftFirst, --ft_ite);
	ft_ite = ftFirst.end();
	for (ft_it = ftFirst.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftSecond.end();
	for (ft_it = ftSecond.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	stdSecond.splice(++stdSecond.begin(), stdFirst, ++stdFirst.begin(), --stdFirst.end());
	// stdSecond.splice(++stdSecond.begin(), stdFirst, stdFirst.begin(), stdFirst.end());
	// stdSecond.splice(--stdSecond.end(), stdFirst, ++stdFirst.begin(), --stdFirst.end());
	// stdSecond.splice(stdSecond.end(), stdFirst, ++stdFirst.begin(), --stdFirst.end());
	// stdSecond.splice(stdSecond.end(), stdFirst, stdFirst.begin(), stdFirst.end());
	std::cout << "STD: ";
	ite = stdFirst.end();
	for (it = stdFirst.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdSecond.end();
	for (it = stdSecond.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ftSecond.splice(++ftSecond.begin(), ftFirst, ++ftFirst.begin(), --ftFirst.end());
	// ftSecond.splice(++ftSecond.begin(), ftFirst, ftFirst.begin(), ftFirst.end());
	// ftSecond.splice(--ftSecond.end(), ftFirst, ++ftFirst.begin(), --ftFirst.end());
	// ftSecond.splice(ftSecond.end(), ftFirst, ++ftFirst.begin(), --ftFirst.end());
	// ftSecond.splice(ftSecond.end(), ftFirst, ftFirst.begin(), ftFirst.end());
	ft_ite = ftFirst.end();
	for (ft_it = ftFirst.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftSecond.end();
	for (ft_it = ftSecond.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::list<int> stdEmpty;
	stdSecond.splice(++stdSecond.begin(), stdEmpty, stdEmpty.begin(), stdEmpty.end());
	stdEmpty.splice(++stdEmpty.begin(), stdSecond, stdSecond.begin(), stdSecond.end());

	std::cout << "STD: ";
	ite = stdEmpty.end();
	for (it = stdEmpty.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdSecond.end();
	for (it = stdSecond.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<int> ftEmpty;
	ftSecond.splice(++ftSecond.begin(), ftEmpty, ftEmpty.begin(), ftEmpty.end());
	ftEmpty.splice(++ftEmpty.begin(), ftSecond, ftSecond.begin(), ftSecond.end());
	ft_ite = ftEmpty.end();
	for (ft_it = ftEmpty.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftSecond.end();
	for (ft_it = ftSecond.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- REMOVE -- " << std::endl << std::endl;

	stdEmpty.push_back(1);
	stdEmpty.push_front(1);
	stdEmpty.push_back(1);
	stdEmpty.remove(1);
	stdEmpty.remove(0);
	std::cout << "STD: ";
	ite = stdEmpty.end();
	for (it = stdEmpty.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";
	ftEmpty.push_back(1);
	ftEmpty.push_front(1);
	ftEmpty.push_back(1);
	ftEmpty.remove(1);
	ftEmpty.remove(0);
	ft_ite = ftEmpty.end();
	for (ft_it = ftEmpty.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- REMOVE_IF -- " << std::endl << std::endl;
	std::cout << "STD: ";
	stdList4.remove_if(is_odd());
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	stdList4.remove_if(single_digit);
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	list4.remove_if(is_odd());
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	list4.remove_if(single_digit);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- UNIQUE -- " << std::endl << std::endl;

	std::cout << "STD: ";
	stdList4.insert(++stdList4.begin(), 10); stdList4.push_back(1); stdList4.push_back(1); stdList4.push_back(1); stdList4.push_front(1);
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	stdList4.unique();
	ite = stdList4.end();
	for (it = stdList4.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	list4.insert(++list4.begin(), 10); list4.push_back(1); list4.push_back(1); list4.push_back(1); list4.push_front(1);
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	list4.unique();
	ft_ite = list4.end();
	for (ft_it = list4.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl << std::endl;


	std::list<double> stdDouble;
	std::list<double>::iterator dit;
	std::list<double>::iterator dite;
	stdDouble.push_back(2.72);
	stdDouble.push_back(3.14);
	stdDouble.push_back(12.15);
	stdDouble.push_back(12.77);
	stdDouble.push_back(12.77);
	stdDouble.push_back(15.3);
	stdDouble.push_back(72.25);
	stdDouble.push_back(72.25);
	stdDouble.push_back(73.0);
	stdDouble.push_back(73.35);

	std::cout << "STD: ";
	dite = stdDouble.end();
	for (dit = stdDouble.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	stdDouble.unique();
	dite = stdDouble.end();
	for (dit = stdDouble.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	stdDouble.unique(same_integral_part);
	dite = stdDouble.end();
	for (dit = stdDouble.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	stdDouble.unique(is_near());
	dite = stdDouble.end();
	for (dit = stdDouble.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<double> ftDouble;
	ft::list<double>::iterator ft_dit;
	ft::list<double>::iterator ft_dite;
	ftDouble.push_back(2.72);
	ftDouble.push_back(3.14);
	ftDouble.push_back(12.15);
	ftDouble.push_back(12.77);
	ftDouble.push_back(12.77);
	ftDouble.push_back(15.3);
	ftDouble.push_back(72.25);
	ftDouble.push_back(72.25);
	ftDouble.push_back(73.0);
	ftDouble.push_back(73.35);
	ft_dite = ftDouble.end();
	for (ft_dit = ftDouble.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";

	ftDouble.unique();
	ft_dite = ftDouble.end();
	for (ft_dit = ftDouble.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";

	ftDouble.unique(same_integral_part);
	ft_dite = ftDouble.end();
	for (ft_dit = ftDouble.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";
	ftDouble.unique(is_near());
	ft_dite = ftDouble.end();
	for (ft_dit = ftDouble.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << std::endl << std::endl;

	std::cout << std::endl << " -- MERGE -- " << std::endl << std::endl;
	std::list<int> stdMerge1;
	std::list<int> stdMerge2;
	ft::list<int> ftMerge1;
	ft::list<int> ftMerge2;
	for (int i = 0; i < 10; i += 2) {
		if (i % 2) {
			stdMerge1.push_back(i);
			stdMerge2.push_back(i + 1);
			ftMerge1.push_back(i);
			ftMerge2.push_back(i + 1);
		}
		else {
			stdMerge1.push_back(i + 1);
			stdMerge2.push_back(i);
			ftMerge1.push_back(i + 1);
			ftMerge2.push_back(i);
		}
	}
	std::cout << "STD: ";
	ite = stdMerge1.end();
	for (it = stdMerge1.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdMerge2.end();
	for (it = stdMerge2.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	stdMerge1.merge(stdMerge2);
	ite = stdMerge1.end();
	for (it = stdMerge1.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| ";
	ite = stdMerge2.end();
	for (it = stdMerge2.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "| " << std::endl;

	std::cout << "FT:  ";
	ft_ite = ftMerge1.end();
	for (ft_it = ftMerge1.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftMerge2.end();
	for (ft_it = ftMerge2.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ftMerge1.merge(ftMerge2);
	ft_ite = ftMerge1.end();
	for (ft_it = ftMerge1.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| ";
	ft_ite = ftMerge2.end();
	for (ft_it = ftMerge2.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "| " << std::endl;

	std::list<double> stdDMerge1;
	std::list<double> stdDMerge2;
	stdDMerge1.push_back(1.1);
	stdDMerge1.push_back(4.1);
	stdDMerge1.push_back(6.5);
	stdDMerge2.push_back(2.5);
	stdDMerge2.push_back(10.5);
	stdDMerge2.push_back(8.9);
	ft::list<double> ftDMerge1;
	ft::list<double> ftDMerge2;
	ftDMerge1.push_back(1.1);
	ftDMerge1.push_back(4.1);
	ftDMerge1.push_back(6.5);
	ftDMerge2.push_back(2.5);
	ftDMerge2.push_back(10.5);
	ftDMerge2.push_back(8.9);
	std::cout << "STD: ";
	dite = stdDMerge1.end();
	for (dit = stdDMerge1.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	dite = stdDMerge2.end();
	for (dit = stdDMerge2.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	stdDMerge1.merge(stdDMerge2, mycomparison);
	// stdDMerge1.merge(stdDMerge2);
	dite = stdDMerge1.end();
	for (dit = stdDMerge1.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	dite = stdDMerge2.end();
	for (dit = stdDMerge2.begin(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| " << std::endl;

	std::cout << "FT:  ";
	ft_dite = ftDMerge1.end();
	for (ft_dit = ftDMerge1.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";
	ft_dite = ftDMerge2.end();
	for (ft_dit = ftDMerge2.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";
	ftDMerge1.merge(ftDMerge2, mycomparison);
	// ftDMerge1.merge(ftDMerge2);
	ft_dite = ftDMerge1.end();
	for (ft_dit = ftDMerge1.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";
	ft_dite = ftDMerge2.end();
	for (ft_dit = ftDMerge2.begin(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| " << std::endl;

	std::cout << std::endl << " -- REVERSE -- " << std::endl << std::endl;
	stdEmpty.push_back(1);
	stdEmpty.push_back(2);
	stdEmpty.push_back(3);
	stdEmpty.reverse();
	std::cout << "STD: ";
	ite = stdEmpty.end();
	for (it = stdEmpty.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << "|";
	stdEmpty.reverse();
	ite = stdEmpty.end();
	for (it = stdEmpty.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl << "FT:  ";

	ftEmpty.push_back(1);
	ftEmpty.push_back(2);
	ftEmpty.push_back(3);
	ftEmpty.reverse();
	ft_ite = ftEmpty.end();
	for (ft_it = ftEmpty.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << "|";
	ftEmpty.reverse();
	ft_ite = ftEmpty.end();
	for (ft_it = ftEmpty.begin(); ft_it != ft_ite; ft_it++)
		std::cout << *ft_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << " -- SORT -- " << std::endl << std::endl;

	std::list<double> stdDouble2;
	stdDouble2.push_back(3.1);
	stdDouble2.push_back(13.1);
	stdDouble2.push_back(2.2);
	stdDouble2.push_back(2.9);
	stdDouble2.push_back(2.91);

	std::cout << "STD: ";
	dit = stdDouble2.begin();
	for (dite = stdDouble2.end(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << "| ";
	stdDouble2.sort();
	dit = stdDouble2.begin();
	for (dite = stdDouble2.end(); dit != dite; dit++)
		std::cout << *dit << " ";
	std::cout << std::endl << "FT:  ";

	ft::list<double> ftDouble2;
	ftDouble2.push_back(3.1);
	ftDouble2.push_back(13.1);
	ftDouble2.push_back(2.2);
	ftDouble2.push_back(2.9);
	ftDouble2.push_back(2.91);
	ft_dit = ftDouble2.begin();
	for (ft_dite = ftDouble2.end(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << "| ";
	ftDouble2.sort();
	ft_dit = ftDouble2.begin();
	for (ft_dite = ftDouble2.end(); ft_dit != ft_dite; ft_dit++)
		std::cout << *ft_dit << " ";
	std::cout << std::endl;
	return 0;
}
