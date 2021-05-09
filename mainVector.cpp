#include "vector.hpp"
#include <vector>


int main(){
    std::vector<int> vect;
    std::vector<int> vect0(10, 9);
    std::vector<int> vect1(vect0.begin(), vect0.end());
    std::vector<int>::iterator it;
    std::vector<int>::iterator ite;

    ft::vector<int> ft_vect;
    ft::vector<int> ft_vect0(10, 9);
    ft::vector<int> ft_vect1(ft_vect0.begin(), ft_vect0.end());
    ft::vector<int>::iterator ft_it;
    ft::vector<int>::iterator ft_ite;



    std::cout << "-- ITERATORS --" << std::endl;
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
    std::cout << std::endl << std::endl;



    std::cout << "-- PUSH_BACK --" << std::endl;
    for (int i = 0; i < 10; i++) {
        vect.push_back(i);
        ft_vect.push_back(i);
    }
    std::cout << "STD: ";
    for (it = vect.begin(), ite = vect.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl << "FT:  ";
    for (ft_it = ft_vect.begin(), ft_ite = ft_vect.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << std::endl << std::endl;



    std::cout << "-- POP_BACK --" << std::endl;
    vect.pop_back(); vect.pop_back(); vect.pop_back();
    ft_vect.pop_back(); ft_vect.pop_back(); ft_vect.pop_back();
    std::cout << "STD: ";
    for (it = vect.begin(), ite = vect.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl << "FT:  ";
    for (ft_it = ft_vect.begin(), ft_ite = ft_vect.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << std::endl << std::endl;



    std::cout << "-- SIZE | MAX_SIZE --" << std::endl;
    std::cout << "STD: " << vect.size() << " | " << vect0.size() << " | " << vect1.size() << " | max_size: " << vect.max_size() << std::endl;
    std::cout << "FT:  " << ft_vect.size() << " | " << ft_vect0.size() << " | " << ft_vect1.size() << " | max_size: " << ft_vect.max_size() << std::endl << std::endl;



    std::cout << "-- RESIZE --" << std::endl;
    vect.resize(5);
    std::cout << "STD: ";
    for (it = vect.begin(), ite = vect.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << "| ";
    vect.resize(15, 66);
    for (it = vect.begin(), ite = vect.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl << "FT:  ";
    ft_vect.resize(5);
    for (ft_it = ft_vect.begin(), ft_ite = ft_vect.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << "| ";
    ft_vect.resize(15, 66);
    for (ft_it = ft_vect.begin(), ft_ite = ft_vect.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << std::endl << std::endl;

    std::vector<int> empt;
    ft::vector<int> ft_empt;

    std::cout << "-- CAPACITY --" << std::endl;
//    std::cout << "STD: " << vect.size() << " | " << vect0.size() << " | " << vect1.size() << std::endl;
    std::cout << "STD: " << vect.capacity() << " | " << vect0.capacity() << " | " << vect1.capacity() << " | " << empt.capacity() << std::endl;
    std::cout << "FT:  " << ft_vect.capacity() << " | " << ft_vect0.capacity() << " | " << ft_vect1.capacity() << " | " << ft_empt.capacity() << std::endl << std::endl;

    std::cout << "-- EMPTY --" << std::endl;

    std::cout << std::boolalpha << "STD: " << vect.empty() << " | " << empt.empty() << std::endl;
    std::cout << std::boolalpha << "FT:  " << ft_vect.empty() << " | " << ft_empt.empty() << std::endl << std::endl;


    std::cout << "-- RESERVE --" << std::endl;


    return 0;
}
