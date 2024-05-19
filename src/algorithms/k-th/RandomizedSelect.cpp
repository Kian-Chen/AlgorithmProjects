#include "k-th.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; ++j)
    {
        if (nums[j] <= pivot)
        {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[right]);
    return i;
}

int randomizedPartition(std::vector<int> &nums, int left, int right)
{
    int i = left + static_cast<int>(rand() % (right - left + 1));
    std::swap(nums[i], nums[right]);
    return partition(nums, left, right);
}

int randomizedSelect(std::vector<int> &nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }
    int q = randomizedPartition(nums, left, right);
    int length = q - left + 1;
    if (k == length)
    {
        return nums[q];
    }
    else if (k < length)
    {
        return randomizedSelect(nums, left, q - 1, k);
    }
    else
    {
        return randomizedSelect(nums, q + 1, right, k - length);
    }
}

int RandomizedSelect::selectKthSmallest(std::vector<int> &nums, int k)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    return randomizedSelect(nums, 0, nums.size() - 1, k);
}
