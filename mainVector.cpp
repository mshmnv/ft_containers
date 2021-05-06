#include "vector.hpp"
#include <vector>

int main(){
    std::vector<int> vect;
    std::vector<int> vect0(10, 9);
//    std::vector<int> vect1(vect0.begin(), vect0.end());
    std::vector<int>::iterator it;
    std::vector<int>::iterator ite;

    ft::vector<int> ft_vect;
    ft::vector<int> ft_vect0(10, 9);
//    ft::vector<int> ft_vect1(ft_vect0.begin(), ft_vect0.end());
    ft::vector<int>::iterator ft_it;
    ft::vector<int>::iterator ft_ite;


    std::cout << "-- ITERATORS --" << std::endl;
    std::cout << "STD: ";
    for (it = vect0.begin(), ite = vect0.end(); it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl << "FT:  ";
    for (ft_it = ft_vect0.begin(), ft_ite = ft_vect0.end(); ft_it != ft_ite; ft_it++)
        std::cout << *ft_it << " ";
    std::cout << std::endl << std::endl;
    std::cout << "{" << *ft_it << "|" << *ft_ite << "}" << std::endl;


    std::cout << "-- SIZE | MAX_SIZE --" << std::endl;
    std::cout << "-- RESIZE --" << std::endl;
    std::cout << "-- CAPACITY --" << std::endl;
    std::cout << "-- EMPTY --" << std::endl;
    std::cout << "-- RESERVE --" << std::endl;
    return 0;
}
