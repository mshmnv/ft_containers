
#include "map.hpp"
#include <map>

template < class Key, class T>
void printMap(std::map<Key, T> map) {
    std::map<char, int>::iterator it = map.begin();
    std::map<char, int>::iterator ite = map.end();

    std::cout << "STD: (" << map.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;
}

template < class Key, class T>
void printMap(ft::map<Key, T> map) {
    ft::map<char, int>::iterator it = map.begin();
    ft::map<char, int>::iterator ite = map.end();

    std::cout << it->first << std::endl;
    std::cout << "FT:  (" << map.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;
}



int main() {
    std::map<char, int> map1;
    map1.insert(std::pair<char,int>('a',100));
    map1.insert(std::pair<char,int>('a',100));
    map1.insert(std::pair<char,int>('b',200));
    printMap(map1);

    ft::map<char, int> ft_map1;
    ft_map1.insert(std::pair<char,int>('a',100));
    ft_map1.insert(std::pair<char,int>('a',200));
    ft_map1.insert(std::pair<char,int>('b',200));

//    printMap(ft_map1); // after operator=

    ft::map<char, int>::iterator it = ft_map1.begin();
    ft::map<char, int>::iterator ite = ft_map1.end();

    std::cout << "FT:  (" << ft_map1.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;

    return 0;
}
