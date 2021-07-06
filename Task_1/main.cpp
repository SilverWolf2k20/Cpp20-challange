// C++20 Challange
// 
// 1. ����� ����������� �����, ��������� �� 3 � 5.
// 
// �������� ���������, ������� ��������� � ������� ����� ���� ����� �����, 
// ��������� �� 3 ��� 5, �� ������������� �����, ���������� �������������.

#include <iostream>
#include <format>
#include <limits>

auto getInt() 
{
    auto value{ 0 };
    while (!(std::cin >> value)) {
        std::cerr << "�������� ����.\n";
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
    std::cout << "������� �����: ";

    auto limit{ getInt() };

    auto sum{ 0 };

    for (auto i{ 0 }; i < limit; ++i)
        if (isDivisibleBy3or5(i))
            sum += i;

    std::cout << std::format("����� ����� ��������� �� 3 ��� 5 �� {} ����� {}", limit, sum);
}