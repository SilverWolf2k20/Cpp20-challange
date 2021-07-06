// C++20 Challange
// 
// 1. Sum of naturals divisible by 3 and 5.
// 
// Write a program that calculates and prints the sum of all the natural
// numbers divisible by either 3 or 5, up to a given limit entered by the
// user.

#include <iostream>
#include <format>
#include <limits>

auto getInt() 
{
    auto value{ 0 };
    while (!(std::cin >> value)) {
        std::cerr << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
    } 
    return value;
}

bool isDivisibleBy3or5(auto i) {
    return (i % 3 == 0) || (i % 5 == 0);
}

int main()
{
    std::cout << "Enter the number: ";

    auto limit{ getInt() };

    auto sum{ 0 };

    for (auto i{ 0 }; i < limit; ++i)
        if (isDivisibleBy3or5(i))
            sum += i;

    std::cout << std::format("The sum of numbers divisible by 3 or 5 up to {} is {}", 
                             limit, 
                             sum);
}
