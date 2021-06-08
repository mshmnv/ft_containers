
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

    std::cout << "FT:  (" << map.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;
}


int main() {
    std::cout << std::endl << std::endl << " --- INSERT ---" << std::endl;
    std::cout << " --- ITERATORS ---" << std::endl;
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

    ft::map<char, int> ft_map1;
    ft_map1.insert(std::pair<char,int>('e',5));
    ft_map1.insert(std::pair<char,int>('e',5));
    ft_map1.insert(std::pair<char,int>('c',3));
    ft_map1.insert(std::pair<char,int>('g',7));
    ft_map1.insert(std::pair<char,int>('f',6));
    ft_map1.insert(std::pair<char,int>('d',4));
    ft_map1.insert(std::pair<char,int>('b',2));
    ft_map1.insert(std::pair<char,int>('a',1));
    printMap(ft_map1);

    std::cout << std::endl << " --- CONST ITERATORS ---" << std::endl;
    ft::map<char, int>::const_iterator it = ft_map1.begin();
    ft::map<char, int>::const_iterator ite = ft_map1.end();
    std::cout << "FT:  (" << ft_map1.size() << ") ";
    for (; it != ite; it++)
        std::cout << it->first << ":" << it->second << " | ";
    std::cout << std::endl;

    std::cout << std::endl << " --- REVERSE ITERATORS ---" << std::endl;
    std::map<char, int>::reverse_iterator std_rit = map1.rbegin();
    std::map<char, int>::reverse_iterator std_rite = map1.rend();
    std::cout << "FT:  (" << ft_map1.size() << ") ";
    for (; std_rit != std_rite; std_rit++)
        std::cout << std_rit->first << ":" << std_rit->second << " | ";
    std::cout << std::endl;

    ft::map<char, int>::reverse_iterator rit = ft_map1.rbegin();
    ft::map<char, int>::reverse_iterator rite = ft_map1.rend();
    std::cout << "FT:  (" << ft_map1.size() << ") ";
    for (; rit != rite; rit++)
        std::cout << rit->first << ":" << rit->second << " | ";
    std::cout << std::endl;

    std::cout << std::endl << " --- CONST REVERSE ITERATORS ---" << std::endl;
    ft::map<char, int>::const_reverse_iterator crit = ft_map1.rbegin();
    ft::map<char, int>::const_reverse_iterator crite = ft_map1.rend();
    std::cout << "FT:  (" << ft_map1.size() << ") ";
    for (; crit != rite; crit++)
        std::cout << crit->first << ":" << crit->second << " | ";
    std::cout << std::endl;

    std::cout << std::endl << std::endl << " --- INSERT W/ ITERATORS ---" << std::endl;
    std::map<char, int> map2(++(++map1.begin()), --map1.end());
    printMap(map2);
    map2.insert(map1.begin(), map1.begin());
    map2.insert(map1.begin(), ++map1.begin());
    map2.insert(--map1.end(), map1.end());
    printMap(map2);

    ft::map<char, int> ft_map2(++(++ft_map1.begin()), --ft_map1.end());
    printMap(ft_map2);
    ft_map2.insert(ft_map1.begin(), ft_map1.begin());
    ft_map2.insert(ft_map1.begin(), ++ft_map1.begin());
    ft_map2.insert(--ft_map1.end(), ft_map1.end());
    printMap(ft_map2);


    std::cout << std::endl << std::endl << " --- ERASE ---" << std::endl;
    map1.erase(map1.begin());
    map1.erase(++(++map1.begin()));
    map1.erase(++map1.begin());
    map1.erase(--map1.end());
    printMap(map1);

    ft_map1.erase(ft_map1.begin());
    ft_map1.erase(++(++ft_map1.begin()));
    ft_map1.erase(++ft_map1.begin());
    ft_map1.erase(--ft_map1.end());
    printMap(ft_map1);


    std::cout << std::endl << std::endl << " --- CLEAR ---" << std::endl;
    map1.clear();
    printMap(map1);

    ft_map1.clear();
    printMap(ft_map1);

    std::cout << std::endl << std::endl << " --- OPERATOR[] ---" << std::endl;
    map1['b'] = 11;
    map1['c'] = 12;
    map1['c'] = 12;
    map1['d'] = 13;
    map1['a'] = 10;
    printMap(map1);

    ft_map1['b'] = 11;
    ft_map1['c'] = 12;
    ft_map1['c'] = 12;
    ft_map1['d'] = 13;
    ft_map1['a'] = 10;
    printMap(ft_map1);

//    std::cout << std::endl << std::endl << " --- SWAP ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- KEY_COMP ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- VALUE_COMP ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- COUNT ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- LOWER_BOUND ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- UPPER_BOUND ---" << std::endl;
//    std::cout << std::endl << std::endl << " --- EQUAL_RANGE ---" << std::endl;


//    while (1) ;
    return 0;
}
