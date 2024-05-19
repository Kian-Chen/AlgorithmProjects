#pragma once

#include <vector>
#include <utility> // std::pair in this lib?

class DPSolution
{
public:
    std::pair<std::vector<int>, std::vector<int>> minimizeDifference(std::vector<int> &nums);
};

class BruteForceSolution
{
public:
    std::pair<std::vector<int>, std::vector<int>> minimizeDifference(std::vector<int> &nums);
};
