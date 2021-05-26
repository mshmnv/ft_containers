#include "vector.hpp"
#include <vector>

template<class T>
void printVector(std::vector<T> &vect) {
	std::cout << "STD: ";
	for (typename std::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void printVector(ft::vector<T> &vect) {
	std::cout << "FT:  ";
	for (typename ft::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


int main(){
    std::vector<int> vect;
    std::vector<int> vect0(10, 9);
    std::vector<int> vect1(vect0.begin(), vect0.end());
    std::vector<int>::iterator it;
    std::vector<int>::iterator ite;

    ft::vector<int> ft_vect;
    ft::vector<int> ft_vect0(10, 9);
    ft::vector<int> ft_vect1(ft_vect0.begin(), ft_vect0.end());

    std::cout << "-- ITERATORS --" << std::endl;
	ft::vector<int>::iterator ft_it;
	ft::vector<int>::iterator ft_ite;
    std::cout << "STD: ";
    for (it = vect0.begin(), ite = vect0.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << "| ";
    for (it = vect1.begin(), ite = vect1.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl << "FT:  ";
    for (ft_it = ft_vect0.begin(), ft_ite = ft_vect0.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << "| ";
    for (ft_it = ft_vect1.begin(), ft_ite = ft_vect1.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << std::endl << std::endl << std::endl;


//
    std::cout << "-- PUSH_BACK --" << std::endl;
    for (int i = 0; i < 10; i++) {
        vect.push_back(i);
        ft_vect.push_back(i);
    }
	printVector(vect);
	printVector(ft_vect);
	std::cout << std::endl << std::endl;

    std::cout << "-- POP_BACK --" << std::endl;
    vect.pop_back(); vect.pop_back(); vect.pop_back();
    ft_vect.pop_back(); ft_vect.pop_back(); ft_vect.pop_back();
	printVector(vect);
	printVector(ft_vect);
	std::cout << std::endl << std::endl;


    std::cout << "-- SIZE | MAX_SIZE --" << std::endl;
    std::cout << "STD: " << vect.size() << " | " << vect0.size() << " | " << vect1.size() << " | max_size: " << vect.max_size() << std::endl;
    std::cout << "FT:  " << ft_vect.size() << " | " << ft_vect0.size() << " | " << ft_vect1.size() << " | max_size: " << ft_vect.max_size() << std::endl << std::endl << std::endl;


    std::cout << "-- RESIZE --" << std::endl;
    vect.resize(5);
	printVector(vect);
    vect.resize(15, 66);
	printVector(vect);

    ft_vect.resize(5);
	printVector(ft_vect);
    ft_vect.resize(15, 66);
	printVector(ft_vect);
	std::cout << std::endl << std::endl;

	std::vector<int> empt;
	ft::vector<int> ft_empt;

    std::cout << "-- CAPACITY --" << std::endl;
//    std::cout << "STD: " << vect.size() << " | " << vect0.size() << " | " << vect1.size() << std::endl;
    std::cout << "STD: " << vect.capacity() << " | " << vect0.capacity() << " | " << vect1.capacity() << " | " << empt.capacity() << std::endl;
    std::cout << "FT:  " << ft_vect.capacity() << " | " << ft_vect0.capacity() << " | " << ft_vect1.capacity() << " | " << ft_empt.capacity() << std::endl << std::endl;

    std::cout << std::endl << "-- EMPTY --" << std::endl;
    std::cout << std::boolalpha << "STD: " << vect.empty() << " | " << empt.empty() << std::endl;
    std::cout << std::boolalpha << "FT:  " << ft_vect.empty() << " | " << ft_empt.empty() << std::endl << std::endl << std::endl;


    std::cout << "-- RESERVE --" << std::endl;
	std::vector<int> resVect;
	ft::vector<int> ft_resVect;
	resVect.reserve(10);
	ft_resVect.reserve(10);
	std::cout << "STD: " << resVect.capacity() << "|" << resVect.size() << std::endl;
	std::cout << "FT:  " << ft_resVect.capacity() << "|" << ft_resVect.size() << std::endl << std::endl << std::endl;


	std::cout << "-- INSERT --" << std::endl;
	std::vector<int> insVect(10, 5);
	ft::vector<int> ft_insVect(10, 5);
	insVect.insert(++insVect.begin(), 10);
	printVector(insVect);
	ft_insVect.insert(++ft_insVect.begin(), 10);
	printVector(ft_insVect);

	insVect.insert(insVect.end(), 10);
	printVector(insVect);
	ft_insVect.insert(ft_insVect.end(), 10);
	printVector(ft_insVect);

	insVect.insert(insVect.begin(), 10);
	printVector(insVect);
	ft_insVect.insert(ft_insVect.begin(), 10);
	printVector(ft_insVect);

	std::cout << std::endl;

	insVect.insert(insVect.begin(), 5, 99);
	printVector(insVect);
	ft_insVect.insert(ft_insVect.begin(), 5, 99);
	printVector(ft_insVect);

	insVect.insert(++insVect.begin(), 5, 88);
	printVector(insVect);
	ft_insVect.insert(++ft_insVect.begin(), 5, 88);
	printVector(ft_insVect);

	insVect.insert(--insVect.end(), 5, 77);
	printVector(insVect);
	ft_insVect.insert(--ft_insVect.end(), 5, 77);
	printVector(ft_insVect);

//	insVect.insert(--insVect.begin(), 5, 66);
//	printVector(insVect);
//todo
//	ft_insVect.insert(--ft_insVect.begin(), 5, 66);
//	printVector(ft_insVect);

	std::cout << std::endl;

	std::vector<int> toIns(10,1);
	ft::vector<int> ft_toIns(10,1);
	insVect.insert(insVect.end(), toIns.begin(), toIns.end());
	printVector(insVect);
	ft_insVect.insert(ft_insVect.end(), ft_toIns.begin(), ft_toIns.end());
	printVector(ft_insVect);

	std::vector<int> toIns2(2,6); toIns2.push_back(1); toIns2.push_back(2); toIns2.push_back(3);
	insVect.insert(insVect.end(), toIns2.begin(), toIns2.end());
	printVector(insVect);

	ft::vector<int> ft_toIns2(2,6); ft_toIns2.push_back(1); ft_toIns2.push_back(2); ft_toIns2.push_back(3);
	ft_insVect.insert(ft_insVect.end(), ft_toIns2.begin(), ft_toIns2.end());
	printVector(ft_insVect);
	std::cout << std::endl << std::endl;


	std::cout << "-- OPERATOR[] --" << std::endl;
	std::vector<int> atVect(10);
	ft::vector<int> ft_atVect(10);
	for (int i = 0; i < 10; i++) {
		atVect[i] = i;
		ft_atVect[i] = i;
	}
	printVector(atVect);
	printVector(ft_atVect);
	std::cout << std::endl << std::endl;


	std::cout << "-- AT --" << std::endl;
	atVect.at(0) = 100;
	ft_atVect.at(0) = 100;
	atVect.at(9) = 100;
	ft_atVect.at(9) = 100;
	printVector(atVect);
	printVector(ft_atVect);

	try { atVect.at(100); }
	catch (std::out_of_range& out) { std::cout << "Exception: " << out.what() << std::endl; }
	try { ft_atVect.at(100); }
	catch (std::out_of_range& out) { std::cout << "Exception: " << out.what() << std::endl; }
	std::cout << std::endl << std::endl;

	std::cout << "-- BACK - FRONT --" << std::endl;
	std::cout << "STD: " << atVect.front() << " | " << atVect.back() << std::endl;
	std::cout << "FT:  " << ft_atVect.front() << " | " << ft_atVect.back() << std::endl << std::endl << std::endl;

	std::cout << "-- ERASE --" << std::endl;
	std::vector<int> clVect(10, 6); clVect.push_back(1); clVect.insert(clVect.begin(), 9);
	ft::vector<int> ft_clVect(10, 6); ft_clVect.push_back(1); ft_clVect.insert(ft_clVect.begin(), 9);
	std::cout << clVect.size() << "|" << clVect.capacity() << " "; printVector(clVect);
	std::cout << ft_clVect.size() << "|" << ft_clVect.capacity() << " "; printVector(ft_clVect);

	clVect.erase(clVect.begin());
	std::cout << clVect.size() << "|" << clVect.capacity() << " "; printVector(clVect);
	ft_clVect.erase(ft_clVect.begin());
	std::cout << ft_clVect.size() << "|" << ft_clVect.capacity() << " "; printVector(ft_clVect);

	clVect.erase(++clVect.begin(), --clVect.end());
	std::cout << clVect.size() << "|" << clVect.capacity() << " "; printVector(clVect);
	ft_clVect.erase(++ft_clVect.begin(), --ft_clVect.end());
	std::cout << ft_clVect.size() << "|" << ft_clVect.capacity() << " "; printVector(ft_clVect);
	std::cout << std::endl << std::endl;

	std::cout << "-- CLEAR --" << std::endl;
	printVector(clVect);
	printVector(ft_clVect);
	clVect.clear();
	std::cout << clVect.size() << "|" << clVect.capacity() << " "; printVector(clVect);
	ft_clVect.clear();
	std::cout << ft_clVect.size() << "|" << ft_clVect.capacity() << " "; printVector(ft_clVect);
	std::cout << std::endl << std::endl;

	std::cout << "-- ASSIGN --" << std::endl;


//	while(1)
//		;

    return 0;
}
