#include "separate.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

struct Node
{
    int value;
    std::vector<bool> path;
};

std::pair<std::vector<int>, std::vector<int>> DPSolution::minimizeDifference(std::vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int mid = totalSum / 2;

    std::vector<std::vector<Node>> dp(n + 1, std::vector<Node>(mid + 1, {0, {}}));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= mid; ++w)
        {
            if (nums[i - 1] <= w)
            {
                if (dp[i - 1][w].value > dp[i - 1][w - nums[i - 1]].value + nums[i - 1])
                {
                    dp[i][w].value = dp[i - 1][w].value;
                    dp[i][w].path = dp[i - 1][w].path;
                    dp[i][w].path.push_back(false);
                }
                else
                {
                    dp[i][w].value = dp[i - 1][w - nums[i - 1]].value + nums[i - 1];
                    dp[i][w].path = dp[i - 1][w - nums[i - 1]].path;
                    dp[i][w].path.push_back(true);
                }
            }
            else
            {
                dp[i][w].value = dp[i - 1][w].value;
                dp[i][w].path = dp[i - 1][w].path;
                dp[i][w].path.push_back(false);
            }
        }
    }

    Node ans = dp[n][mid];

    std::vector<int> subset1, subset2;
    int subset1Sum = 0, subset2Sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans.path[i])
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
