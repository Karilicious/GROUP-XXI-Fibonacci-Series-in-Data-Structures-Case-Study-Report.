#include <iostream>
#include "fib_algorithms.hpp"

int main()
{
    const unsigned int n = 10;
    std::cout << "Recursive F(10): " << fibRecursive(n) << std::endl;
    std::cout << "Series: ";
    for (unsigned long long value : fibSeries(n)) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
    return 0;
}
