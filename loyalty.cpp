#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "fib_algorithms.hpp"

int main()
{
    int years = 0;
    std::cout << "Enter the number of loyal years (1-93): ";
    if (!(std::cin >> years)) {
        std::cout << "Error: please enter a whole number." << std::endl;
        return 1;
    }
    if (years < 1 || years > 93) {
        std::cout << "Error: years must be between 1 and 93." << std::endl;
        return 1;
    }

    std::vector<unsigned long long> rewards = fibSeries(years);

    std::cout << std::endl << std::left << std::setw(6) << "Year"
              << std::right << std::setw(16) << "Reward points" << std::endl;
    std::cout << std::string(22, '-') << std::endl;
    for (int year = 1; year <= years; ++year) {
        std::cout << std::left << std::setw(6) << year
                  << std::right << std::setw(16) << rewards[year] << std::endl;
    }
    return 0;
}
