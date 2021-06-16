//#include "../vector.hpp"
//#include "../list.hpp"
//#include "../stack.hpp"
//#include "../queue.hpp"
//#include "../map.hpp"

#include <iostream>
void test_vector();
void test_list();
void test_stack();
void test_queue();
void test_map();

int main() {
    std::cout << std::endl << std::endl << "\t\tV E C T O R" << std::endl;
    std::cout << "\t\tV E C T O R" << std::endl;
    std::cout << "\t\tV E C T O R" << std::endl << std::endl;
    test_vector();

    std::cout << std::endl << std::endl << "\t\tL I S T" << std::endl;
    std::cout << "\t\tL I S T" << std::endl;
    std::cout << "\t\tL I S T" << std::endl << std::endl;
    test_list();


    std::cout << std::endl << std::endl << "\t\tS T A C K" << std::endl;
    std::cout << "\t\tS T A C K" << std::endl;
    std::cout << "\t\tS T A C K" << std::endl << std::endl;
    test_stack();

    std::cout << std::endl << std::endl << "\t\tQ U E U E" << std::endl;
    std::cout << "\t\tQ U E U E" << std::endl;
    std::cout << "\t\tQ U E U E" << std::endl << std::endl;
    test_queue();

    std::cout << std::endl << std::endl << "\t\tM A P" << std::endl;
    std::cout << "\t\tM A P" << std::endl;
    std::cout << "\t\tM A P" << std::endl << std::endl;
    test_map();

//     while (1) ;
    return 0;
}