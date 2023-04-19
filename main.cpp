#include <iostream>

#include "include/list.hpp"

int main() {
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    std::cout << "length: " << list.len() << std::endl;
    for (List<int>::Iter it = list.begin(); it != list.end();it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
