#include "k-th.h"
#include <algorithm>
#include <vector>

int partition(std::vector<int> &nums, int left, int right, int pivotIndex)
{
    int pivotValue = nums[pivotIndex];
    std::swap(nums[pivotIndex], nums[right]);
    int storeIndex = left;
    for (int i = left; i < right; ++i)
    {
        if (nums[i] < pivotValue)
        {
            std::swap(nums[storeIndex], nums[i]);
            ++storeIndex;
        }
    }
    std::swap(nums[right], nums[storeIndex]);
    return storeIndex;
}

int selectPivotIndex(std::vector<int> &nums, int left, int right)
{
    if (right - left < 5)
    {
        std::sort(nums.begin() + left, nums.begin() + right + 1);
        return (left + right) / 2;
    }

    for (int i = left; i <= right; i += 5)
    {
        int subRight = std::min(i + 4, right);
        std::sort(nums.begin() + i, nums.begin() + subRight + 1);
        int medianIndex = (i + subRight) / 2;
        std::swap(nums[medianIndex], nums[left + (i - left) / 5]);
    }

    int mid = (right - left) / 10 + left + 1;
    return selectPivotIndex(nums, left, left + (right - left) / 5);
}

int medianOfMediansSelect(std::vector<int> &nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }

    int pivotIndex = selectPivotIndex(nums, left, right);
    pivotIndex = partition(nums, left, right, pivotIndex);

    int length = pivotIndex - left + 1;
    if (k == length)
    {
        return nums[pivotIndex];
    }
    else if (k < length)
    {
        return medianOfMediansSelect(nums, left, pivotIndex - 1, k);
    }
    else
    {
        return medianOfMediansSelect(nums, pivotIndex + 1, right, k - length);
    }
}

int MedianOfMedians::selectKthSmallest(std::vector<int> &nums, int k)
{
    return medianOfMediansSelect(nums, 0, nums.size() - 1, k);
}
