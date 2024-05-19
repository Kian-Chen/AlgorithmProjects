#include "separate.h"
#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> data;
    int num;
    std::cout << "Enter the input worth of cards: ";
    while (std::cin >> num)
    {
        data.push_back(num);
    }

    DPSolution dpSolution;
    auto result = dpSolution.minimizeDifference(data);

    int sum1 = std::accumulate(result.first.begin(), result.first.end(), 0);
    int sum2 = std::accumulate(result.second.begin(), result.second.end(), 0);

    std::cout << "Abe's total worth of cards: " << sum1 << "\n";
    std::cout << "Abe's worth of cards: ";
    for (int num : result.first)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Bob's total worth of cards: " << sum2 << "\n";
    std::cout << "Bob's worth of cards: ";
    for (int num : result.second)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
