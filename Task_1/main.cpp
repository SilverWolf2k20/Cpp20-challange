// C++20 Challange
// 
// 1. Сумма натуральных чисел, делящаяся на 3 и 5.
// 
// Напишите программу, которая вычисляет и выводит сумму всех целых чисел, 
// делящиеся на 3 или 5, до определенного числа, введенного пользователем.

#include <iostream>
#include <format>
#include <limits>

auto getInt() 
{
    auto value{ 0 };
    while (!(std::cin >> value)) {
        std::cerr << "Неверный ввод.\n";
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
    setlocale(LC_ALL, "ru");
    std::cout << "Введите число: ";

    auto limit{ getInt() };

    auto sum{ 0 };

    for (auto i{ 0 }; i < limit; ++i)
        if (isDivisibleBy3or5(i))
            sum += i;

    std::cout << std::format("Сумма чисел делящихся на 3 или 5 до {} равна {}", limit, sum);
}