//-----------------------------------------------------------------------------
// C++20 Challange
// 
// 2. Greatest common divisor.
// 
// Write a program that, given two positive integers, will calculate and
// print the greatest common divisor of the two.
//-----------------------------------------------------------------------------

#include <iostream>
#include <limits>

// Gets the number that the user enters.
template<typename T = int>
T getNumber()
{
    T value{ T{} };
    while (!(std::cin >> value)) {
        std::cerr << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Gets a positive number that the user enters.
auto getPositiveInteger()
{
    while (true) {
        auto number = getNumber();
        if(number > 0)
            return number;
        std::cerr << "This number is not positive.\n";
    }
}

// The Euclidean algorithm for computing the greatest common divisor of 
// two integers.
template<typename T>
T algorithmEuclidean(T first, T last) {
    while (first != 0 && last != 0) {
        if (first > last)
            first %= last;
        else
            last %= first;
    }
    return first + last;
}

int main()
{
    std::cout << "Enter the first positive integers.\n";
    auto first = getPositiveInteger();
    std::cout << "Enter the second positive integers.\n";
    auto last  = getPositiveInteger();
    std::cout << "Greatest common divisor: " 
              << algorithmEuclidean(first, last);
}