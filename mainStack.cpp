#include "stack.hpp"
#include <stack>
#include <deque>


int main() {

    std::stack<int> stack1;
    ft::stack<int> ft_stack1;

    std::cout << std::endl << "  --  EMPTY   --   SIZE   --   TOP   --  " << std::endl;

    std::cout << "STD: " << std::boolalpha << "Empty: " << stack1.empty() << " | Size: " << stack1.size() <<  std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_stack1.empty() << " | Size: " << ft_stack1.size() << std::endl;

    std::deque<int> deque1(10, 9);
    std::stack<int> stack2(deque1);
    ft::stack<int> ft_stack2(deque1);

    std::cout << "STD: " << std::boolalpha << "Empty: " << stack2.empty() << " | Size: " << stack2.size() << " | Top: " << stack2.top() << std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_stack2.empty() << " | Size: " << ft_stack2.size() << " | Top: " << ft_stack2.top() << std::endl;



    std::cout << std::endl << "  --  PUSH  --  " << std::endl;

    stack2.push(1);
    std::cout << "STD: " << std::boolalpha << "Empty: " << stack2.empty() << " | Size: " << stack2.size() << " | Top: " << stack2.top() << std::endl;
    stack2.push(2);
    std::cout << "STD: " << std::boolalpha << "Empty: " << stack2.empty() << " | Size: " << stack2.size() << " | Top: " << stack2.top() << std::endl;
    stack2.push(3);
    std::cout << "STD: " << std::boolalpha << "Empty: " << stack2.empty() << " | Size: " << stack2.size() << " | Top: " << stack2.top() << std::endl << std::endl;

    ft_stack2.push(1);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_stack2.empty() << " | Size: " << ft_stack2.size() << " | Top: " << ft_stack2.top() << std::endl;
    ft_stack2.push(2);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_stack2.empty() << " | Size: " << ft_stack2.size() << " | Top: " << ft_stack2.top() << std::endl;
    ft_stack2.push(3);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_stack2.empty() << " | Size: " << ft_stack2.size() << " | Top: " << ft_stack2.top() << std::endl;


    std::cout << std::endl << "  --  RELATIONAL OPERATORS  ---" << std::endl;

    std::stack<int> a;
    std::stack<int> b;
    std::stack<int> c;
    a.push(1); a.push(2); a.push(3);
    b.push(1); b.push(2); b.push(3);
    c.push(3); c.push(2); c.push(1);

    ft::stack<int> ft_a;
    ft::stack<int> ft_b;
    ft::stack<int> ft_c;
    ft_a.push(1); ft_a.push(2); ft_a.push(3);
    ft_b.push(1); ft_b.push(2); ft_b.push(3);
    ft_c.push(3); ft_c.push(2); ft_c.push(1);

    std::cout << std::boolalpha << "STD " << (a==b) << "\tFT " << (ft_a==ft_b) << std::endl;
    std::cout << std::boolalpha << "STD " << (a!=b) << "\tFT " << (ft_a!=ft_b) << std::endl;
    std::cout << std::boolalpha << "STD " << (b>c) << "\tFT " << (ft_b>ft_c) << std::endl;
    std::cout << std::boolalpha << "STD " << (c>b) << "\tFT " << (ft_c>ft_b) << std::endl;
    std::cout << std::boolalpha << "STD " << (a<=b) << "\tFT " << (ft_a<=ft_b) << std::endl;
    std::cout << std::boolalpha << "STD " << (a>=b) << "\tFT " << (ft_a>=ft_b) << std::endl;

    std::cout << std::endl << "  --  SWAP  ---" << std::endl;

    swap(a,c);
    std::cout << "STD:  " << std::boolalpha << "Empty: " << a.empty() << " | Size: " << a.size() << " | Top: " << a.top() << std::endl;
    std::cout << "STD:  " << std::boolalpha << "Empty: " << c.empty() << " | Size: " << c.size() << " | Top: " << c.top() << std::endl;

    swap(ft_a, ft_c);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_a.empty() << " | Size: " << ft_a.size() << " | Top: " << ft_a.top() << std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_c.empty() << " | Size: " << ft_c.size() << " | Top: " << ft_c.top() << std::endl;

//    while(1) ;
    return 0;
}