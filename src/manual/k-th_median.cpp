#include "k-th.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data;
    int n, k;
    std::cout << "Enter the size of the input array: ";
    std::cin >> n;
    std::cout << "Enter the elements in the input array: ";
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;
        data.push_back(num);
    }
    std::cout << "Enter the value of k to find the k-th smallest element: ";
    std::cin >> k;

    MedianOfMedians medianOfMedians;
    int result = medianOfMedians.selectKthSmallest(data, k);
    std::cout << "The " << k << "-th smallest element is " << result << std::endl;

    return 0;
}
