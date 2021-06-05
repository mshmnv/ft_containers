
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
    std::cout << std::endl << std::endl;
    std::cout << " --- INSERT ---" << std::endl;
    std::map<char, int> map1;
    map1.insert(std::pair<char,int>('e',5));
    map1.insert(std::pair<char,int>('e',5));
    map1.insert(std::pair<char,int>('c',3));
    map1.insert(std::pair<char,int>('g',7));
    map1.insert(std::pair<char,int>('f',6));
    map1.insert(std::pair<char,int>('d',4));
    map1.insert(std::pair<char,int>('b',2));
    map1.insert(std::pair<char,int>('a',1));
    printMap(map1);
//    std::cout << map1.count('e') << std::endl;

    ft::map<char, int> ft_map1;
    ft_map1.insert(std::pair<char,int>('e',5));
    ft_map1.insert(std::pair<char,int>('e',5));
    ft_map1.insert(std::pair<char,int>('c',3));
    ft_map1.insert(std::pair<char,int>('g',7));
    ft_map1.insert(std::pair<char,int>('f',6));
    ft_map1.insert(std::pair<char,int>('d',4));
    ft_map1.insert(std::pair<char,int>('b',2));
    ft_map1.insert(std::pair<char,int>('a',1));

//    std::cout << std::endl << "FT:  (" << ft_map1.size() << ") ";
//    inorderPrinting(ft_map1._root);


//    printMap(ft_map1); // after operator=
    ft::map<char, int>::iterator it = ft_map1.begin();
    ft::map<char, int>::iterator ite = ft_map1.end();

    std::cout << std::endl << "FT:  (" << ft_map1.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
//    std::cout << it->first << ":" << it->second << " | ";
//    it++;
//    std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;


//    std::cout << std::endl << std::endl;
//    std::cout << " --- ERASE ---" << std::endl;
//    map1.erase(++(++map1.begin()));
////    map1.erase(++map1.begin());
////    map1.erase(--map1.end());
//    printMap(map1);
//
//    ft_map1.erase(++(++ft_map1.begin()));
////    ft_map1.erase(++ft_map1.begin());
////    ft_map1.erase(--ft_map1.end());
//    std::cout << "FT:  (" << ft_map1.size() << ") ";
//    inorderPrinting(ft_map1._root);
//    std::cout << std::endl;

//    while (1) ;
    return 0;
}
