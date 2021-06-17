
#include "../map.hpp"
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


void test_map() {
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

    std::cout << std::endl << std::endl << " --- SWAP ---" << std::endl;
    std::cout << " ... before swap ... " << std::endl;
    std::map<char, int> map3;
    map3['x'] = 100;
    map3['y'] = 200;
    printMap(map3);
    printMap(map1);

    ft::map<char, int> ft_map3;
    ft_map3['x'] = 100;
    ft_map3['y'] = 200;
    printMap(ft_map3);
    printMap(ft_map1);
    std::cout << std::endl << " ... after swap ... " << std::endl;

    map1.swap(map3);
    printMap(map3);
    printMap(map1);

    ft_map1.swap(ft_map3);
    printMap(ft_map3);
    printMap(ft_map1);

    std::cout << std::endl << std::endl << " --- KEY_COMP --- VALUE_COMP ---" << std::endl;
    std::map<char,int> map4;
    map4['a'] = 100;
    map4['b'] = 101;
    map4['x'] = 1001;
    map4['y'] = 2002;
    map4['z'] = 3003;
    std::pair<char, int> value1 = *map4.rbegin(); // last element
    std::pair<char, int> value2 = *map4.begin();  // first element
    std::cout << "STD: " << std::boolalpha << map4.value_comp()(value1, value2) << " | " << map4.value_comp()(value2, value1) << std::endl;
    std::cout << "STD: " << std::boolalpha << map4.key_comp()(value1.first, value2.first) << " | " << map4.key_comp()(value2.first, value1.first) << std::endl;


    ft::map<char,int> ft_map4;
    ft_map4['a'] = 100;
    ft_map4['b'] = 101;
    ft_map4['x'] = 1001;
    ft_map4['y'] = 2002;
    ft_map4['z'] = 3003;
    std::pair<char, int> ft_value1 = *ft_map4.rbegin(); // last element
    std::pair<char, int> ft_value2 = *ft_map4.begin();  // first element
    std::cout << "FT:  " << std::boolalpha << ft_map4.value_comp()(ft_value1, ft_value2) << " | " << ft_map4.value_comp()(ft_value2, ft_value1) << std::endl;
    std::cout << "FT:  " << std::boolalpha << ft_map4.key_comp()(ft_value1.first, ft_value2.first) << " | " << ft_map4.key_comp()(ft_value2.first, ft_value1.first) << std::endl;


    std::cout << std::endl << std::endl << " --- COUNT ---" << std::endl;
    printMap(map4);
    std::cout << "Count 'a': " << map4.count('a') << " | Count 'f': " << map4.count('f') << std::endl;
    printMap(ft_map4);
    std::cout << "Count 'a': " << ft_map4.count('a') << " | Count 'f': " << ft_map4.count('f') << std::endl;


    std::cout << std::endl << std::endl << " --- LOWER_BOUND ---" << std::endl;
    std::map<char,int>::iterator itlow = map4.lower_bound('a');
    printMap(map4);
    std::cout << "Lower_bound 'a': " << itlow->first << ":" << itlow->second << std::endl;
    itlow = map4.lower_bound('x');
    std::cout << "Lower_bound 'x': " << itlow->first << ":" << itlow->second << std::endl;
    itlow = map4.lower_bound('f');
    std::cout << "Lower_bound 'f': " << itlow->first << ":" << itlow->second << std::endl;

    ft::map<char,int>::iterator ft_itlow = ft_map4.lower_bound('a');
    printMap(ft_map4);
    std::cout << "Lower_bound 'a': " << ft_itlow->first << ":" << ft_itlow->second << std::endl;
    ft_itlow = ft_map4.lower_bound('x');
    std::cout << "Lower_bound 'x': " << ft_itlow->first << ":" << ft_itlow->second << std::endl;
    ft_itlow = ft_map4.lower_bound('f');
    std::cout << "Lower_bound 'f': " << ft_itlow->first << ":" << ft_itlow->second << std::endl;


    std::cout << std::endl << std::endl << " --- UPPER_BOUND ---" << std::endl;
    printMap(map4);
    std::map<char,int>::iterator itup = map4.upper_bound('a');
    std::cout << "Upper_bound 'a': " << itup->first << ":" << itup->second << std::endl;
    itup = map4.upper_bound('x');
    std::cout << "Upper_bound 'x': " << itup->first << ":" << itup->second << std::endl;
    itup = map4.upper_bound('f');
    std::cout << "Upper_bound 'f': " << itup->first << ":" << itup->second << std::endl;

    printMap(ft_map4);
    ft::map<char,int>::iterator ft_itup = ft_map4.upper_bound('a');
    std::cout << "Upper_bound 'a': " << ft_itup->first << ":" << ft_itup->second << std::endl;
    ft_itup = ft_map4.upper_bound('x');
    std::cout << "Upper_bound 'x': " << ft_itup->first << ":" << ft_itup->second << std::endl;
    ft_itup = ft_map4.upper_bound('f');
    std::cout << "Upper_bound 'f': " << ft_itup->first << ":" << ft_itup->second << std::endl;


    std::cout << std::endl << std::endl << " --- EQUAL_RANGE ---" << std::endl;
    printMap(map4);
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret = map4.equal_range('b');
    std::cout << "Equal_range'b': " << ret.first->first << ":" << ret.first->second << " => " << ret.second->first << ":" << ret.second->second << '\n';
    ret = map4.equal_range('f');
    std::cout << "Equal_range'f': " << ret.first->first << ":" << ret.first->second << " => " << ret.second->first << ":" << ret.second->second << '\n';


    printMap(ft_map4);
    std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret = ft_map4.equal_range('b');
    std::cout << "Equal_range'b': " << ft_ret.first->first << ":" << ft_ret.first->second << " => " << ft_ret.second->first << ":" << ft_ret.second->second << '\n';
    ft_ret = ft_map4.equal_range('f');
    std::cout << "Equal_range'f': " << ft_ret.first->first << ":" << ft_ret.first->second << " => " << ft_ret.second->first << ":" << ft_ret.second->second << '\n';

    std::cout << std::endl << std::endl << " --- just a big map ---" << std::endl;
    std::map<char, int> map5;
    map5.insert(std::pair<char,int>('a',1));
    map5.insert(std::pair<char,int>('y',25));
    map5.insert(std::pair<char,int>('q',17));
    map5.insert(std::pair<char,int>('l',12));
    map5.insert(std::pair<char,int>('e',5));
    map5.insert(std::pair<char,int>('e',5));
    map5.insert(std::pair<char,int>('s',19));
    map5.insert(std::pair<char,int>('n',14));
    map5.insert(std::pair<char,int>('t',20));
    map5.insert(std::pair<char,int>('u',21));
    map5.insert(std::pair<char,int>('v',22));
    map5.insert(std::pair<char,int>('w',23));
    map5.insert(std::pair<char,int>('x',24));
    map5.insert(std::pair<char,int>('z',26));
    map5.insert(std::pair<char,int>('c',3));
    map5.insert(std::pair<char,int>('g',7));
    map5.insert(std::pair<char,int>('f',6));
    map5.insert(std::pair<char,int>('d',4));
    map5.insert(std::pair<char,int>('b',2));
    map5.insert(std::pair<char,int>('h',8));
    map5.insert(std::pair<char,int>('i',9));
    map5.insert(std::pair<char,int>('j',10));
    map5.insert(std::pair<char,int>('k',11));
    map5.insert(std::pair<char,int>('m',13));
    map5.insert(std::pair<char,int>('o',15));
    map5.insert(std::pair<char,int>('p',16));
    map5.insert(std::pair<char,int>('r',18));

    printMap(map5);

    ft::map<char, int> ft_map5;
    ft_map5.insert(std::pair<char,int>('a',1));
    ft_map5.insert(std::pair<char,int>('y',25));
    ft_map5.insert(std::pair<char,int>('q',17));
    ft_map5.insert(std::pair<char,int>('l',12));
    ft_map5.insert(std::pair<char,int>('e',5));
    ft_map5.insert(std::pair<char,int>('e',5));
    ft_map5.insert(std::pair<char,int>('s',19));
    ft_map5.insert(std::pair<char,int>('n',14));
    ft_map5.insert(std::pair<char,int>('t',20));
    ft_map5.insert(std::pair<char,int>('v',22));
    ft_map5.insert(std::pair<char,int>('u',21));
    ft_map5.insert(std::pair<char,int>('w',23));
    ft_map5.insert(std::pair<char,int>('x',24));
    ft_map5.insert(std::pair<char,int>('z',26));
    ft_map5.insert(std::pair<char,int>('c',3));
    ft_map5.insert(std::pair<char,int>('g',7));
    ft_map5.insert(std::pair<char,int>('f',6));
    ft_map5.insert(std::pair<char,int>('d',4));
    ft_map5.insert(std::pair<char,int>('b',2));
    ft_map5.insert(std::pair<char,int>('h',8));
    ft_map5.insert(std::pair<char,int>('i',9));
    ft_map5.insert(std::pair<char,int>('j',10));
    ft_map5.insert(std::pair<char,int>('k',11));
    ft_map5.insert(std::pair<char,int>('m',13));
    ft_map5.insert(std::pair<char,int>('o',15));
    ft_map5.insert(std::pair<char,int>('p',16));
    ft_map5.insert(std::pair<char,int>('r',18));

    printMap(ft_map5);
}
