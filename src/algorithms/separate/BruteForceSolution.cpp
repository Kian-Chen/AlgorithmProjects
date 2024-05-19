#include "separate.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

std::pair<std::vector<int>, std::vector<int>> BruteForceSolution::minimizeDifference(std::vector<int> &nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int minDiff = totalSum;
    std::vector<bool> bestPath(n);

    for (int i = 0; i < (1 << n); ++i)
    {
        int subsetSum = 0;
        std::vector<bool> currentPath(n);
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                subsetSum += nums[j];
                currentPath[j] = true;
            }
        }
        int diff = abs(totalSum - 2 * subsetSum);
        if (diff < minDiff)
        {
            minDiff = diff;
            bestPath = currentPath;
        }
    }

    std::vector<int> subset1, subset2;
    int subset1Sum = 0, subset2Sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (bestPath[i])
        {
            subset1.push_back(nums[i]);
            subset1Sum += nums[i];
        }
        else
        {
            subset2.push_back(nums[i]);
            subset2Sum += nums[i];
        }
    }

    return {subset1, subset2};
}
