#pragma once
#include <stdexcept>
#include <vector>

constexpr unsigned int MAX_INDEX = 93;   // largest n whose F(n) fits in 64 bits

// Task 1: recursion
unsigned long long fibRecursive(unsigned int n)
{
    if (n < 2) {
        return n;                         // F(0) = 0 and F(1) = 1
    }
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Tasks 2 and 3: builds F(0) ... F(n) in a vector (bottom-up table)
std::vector<unsigned long long> fibSeries(unsigned int n)
{
    if (n > MAX_INDEX) {
        throw std::invalid_argument("n is too large for 64-bit numbers");
    }
    std::vector<unsigned long long> series(n + 1);
    series[0] = 0;
    if (n >= 1) {
        series[1] = 1;
    }
    for (unsigned int i = 2; i <= n; ++i) {
        series[i] = series[i - 1] + series[i - 2];
    }
    return series;
}

// Extra: one value only, keeping just the last two numbers
unsigned long long fibTwoVar(unsigned int n)
{
    if (n == 0) {
        return 0;
    }
    unsigned long long previous = 0;      // F(0)
    unsigned long long current = 1;       // F(1)
    for (unsigned int i = 2; i <= n; ++i) {
        unsigned long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}
