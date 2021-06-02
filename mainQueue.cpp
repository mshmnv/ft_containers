#include "queue.hpp"
#include <queue>
#include <deque>


int main() {
    std::queue<int> queue1;
    ft::queue<int> ft_queue1;

    std::cout << std::endl << "  --  EMPTY   --   SIZE   --   FRONT   --   FRONT   ---" << std::endl;

    std::cout << "STD: " << std::boolalpha << "Empty: " << queue1.empty() << " | Size: " << queue1.size() <<  std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue1.empty() << " | Size: " << ft_queue1.size() << std::endl;

    std::deque<int> deque1(10, 9);
    std::queue<int> queue2(deque1);
    ft::queue<int> ft_queue2(deque1);

    std::cout << "STD: " << std::boolalpha << "Empty: " << queue2.empty() << " | Size: " << queue2.size() << " | Front: " << queue2.front() << " | Back: " << queue2.back() << std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue2.empty() << " | Size: " << ft_queue2.size() << " | Front: " << ft_queue2.front() << " | Back: " << queue2.back() << std::endl;


    std::cout << std::endl << "  --  PUSH  --  POP  ---" << std::endl;
    std::queue<int> queue3;
    ft::queue<int> ft_queue3;

    queue3.push(1);
    std::cout << "STD: " << std::boolalpha << "Empty: " << queue3.empty() << " | Size: " << queue3.size() << " | Front: " << queue3.front() << " | Back: " << queue3.back() << std::endl;
    queue3.push(2);
    std::cout << "STD: " << std::boolalpha << "Empty: " << queue3.empty() << " | Size: " << queue3.size() << " | Front: " << queue3.front() << " | Back: " << queue3.back() << std::endl;
    queue3.push(3);
    std::cout << "STD: " << std::boolalpha << "Empty: " << queue3.empty() << " | Size: " << queue3.size() << " | Front: " << queue3.front() << " | Back: " << queue3.back() << std::endl;
    queue3.pop();
    std::cout << "STD: " << std::boolalpha << "Empty: " << queue3.empty() << " | Size: " << queue3.size() << " | Front: " << queue3.front() << " | Back: " << queue3.back() << std::endl << std::endl;

    ft_queue3.push(1);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue3.empty() << " | Size: " << ft_queue3.size() << " | Front: " << ft_queue3.front() << " | Back: " << ft_queue3.back() << std::endl;
    ft_queue3.push(2);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue3.empty() << " | Size: " << ft_queue3.size() << " | Front: " << ft_queue3.front() << " | Back: " << ft_queue3.back() << std::endl;
    ft_queue3.push(3);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue3.empty() << " | Size: " << ft_queue3.size() << " | Front: " << ft_queue3.front() << " | Back: " << ft_queue3.back() << std::endl;
    ft_queue3.pop();
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_queue3.empty() << " | Size: " << ft_queue3.size() << " | Front: " << ft_queue3.front() << " | Back: " << ft_queue3.back() << std::endl;



    std::cout << std::endl << "  --  RELATIONAL OPERATORS  ---" << std::endl;

    std::queue<int> a;
    std::queue<int> b;
    std::queue<int> c;
    a.push(1); a.push(2); a.push(3);
    b.push(1); b.push(2); b.push(3);
    c.push(3); c.push(2); c.push(1);

    ft::queue<int> ft_a;
    ft::queue<int> ft_b;
    ft::queue<int> ft_c;
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
    std::cout << "STD:  " << std::boolalpha << "Empty: " << a.empty() << " | Size: " << a.size() << " | Front: " << a.front() << " | Back: " << a.back() << std::endl;
    std::cout << "STD:  " << std::boolalpha << "Empty: " << c.empty() << " | Size: " << c.size() << " | Front: " << c.front() << " | Back: " << c.back() << std::endl;

    swap(ft_a, ft_c);
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_a.empty() << " | Size: " << ft_a.size() << " | Front: " << ft_a.front() << " | Back: " << ft_a.back() << std::endl;
    std::cout << "FT:  " << std::boolalpha << "Empty: " << ft_c.empty() << " | Size: " << ft_c.size() << " | Front: " << ft_c.front() << " | Back: " << ft_c.back() << std::endl;

    return 0;
}