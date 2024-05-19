#include "separate.h"
#include "Timer.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>

void loadTestData(const std::string &filename, std::vector<int> &data)
{
    std::ifstream inFile(filename);
    int num;
    while (inFile >> num)
    {
        data.push_back(num);
    }
    inFile.close();
}

void timeAlgorithm(DPSolution &algorithm, const std::vector<int> &data)
{
    std::vector<int> copy = data;
    Timer timer;
    timer.start();
    auto result = algorithm.minimizeDifference(copy);
    timer.stop();
    std::cout << "DPSolution: " << timer.elapsedMilliseconds() << " ms\n";
}

void timeAlgorithm(BruteForceSolution &algorithm, const std::vector<int> &data)
{
    std::vector<int> copy = data;
    Timer timer;
    timer.start();
    auto result = algorithm.minimizeDifference(copy);
    timer.stop();
    std::cout << "BruteForceSolution: " << timer.elapsedMilliseconds() << " ms\n";
}

int main()
{
    std::vector<int> sizes = {10, 20, 30, 40};
    for (int size : sizes)
    {
        std::vector<int> data;
        loadTestData("separate_data_" + std::to_string(size) + ".txt", data);
        DPSolution dpSolution;
        BruteForceSolution bruteForceSolution;
        timeAlgorithm(dpSolution, data);
        timeAlgorithm(bruteForceSolution, data);
    }
    return 0;
}
