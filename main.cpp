#include <iostream>
#include <algorithm>

#include "include/list.hpp"

int main() {
    List<int> list;
    list.append(6);
    list.append(5);
    list.append(3);
    list.append(4);
    list.append(2);
    list.append(1);

    std::cout << "length: " << list.len() << std::endl;
    for (List<int>::Iter it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout <<"del: "<< list.pop(1) << std::endl;
    for (List<int>::Iter it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << list << std::endl;
    return 0;
}
