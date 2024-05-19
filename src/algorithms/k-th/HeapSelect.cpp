#include "k-th.h"
#include <algorithm>
#include <queue>

int HeapSelect::selectKthSmallest(std::vector<int> &nums, int k)
{
    std::priority_queue<int> maxHeap;
    for (int num : nums)
    {
        maxHeap.push(num);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}
