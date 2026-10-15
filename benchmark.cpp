#include <chrono>
#include <iostream>
#include "fib_algorithms.hpp"

unsigned long long fibFromSeries(unsigned int n)
{
    return fibSeries(n).back();            // last value = F(n)
}

// Runs one method many times and returns the average time per call in nanoseconds
double timeMethod(unsigned long long (*method)(unsigned int),
                  int repetitions, unsigned long long& checksum)
{
    volatile unsigned int requestedN = 30; // stops the compiler pre-computing the answer
    const auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        checksum += method(requestedN);
    }
    const std::chrono::duration<double, std::nano> elapsed =
        std::chrono::steady_clock::now() - start;
    return elapsed.count() / repetitions;
}

int main()
{
    if (fibRecursive(30) != 832040ULL || fibFromSeries(30) != 832040ULL ||
        fibTwoVar(30) != 832040ULL) {
        std::cerr << "A method returned a wrong value." << std::endl;
        return 1;
    }

    unsigned long long checksum = 0;       // printed so the work cannot be removed
    std::cout << "Direct recursion:          "
              << timeMethod(fibRecursive, 20, checksum) << " ns per call" << std::endl;
    std::cout << "Iterative array / table:   "
              << timeMethod(fibFromSeries, 200000, checksum) << " ns per call" << std::endl;
    std::cout << "Iterative two variables:   "
              << timeMethod(fibTwoVar, 200000, checksum) << " ns per call" << std::endl;
    std::cout << "Checksum: " << checksum << std::endl;
    return 0;
}
