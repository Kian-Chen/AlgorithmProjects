#include "k-th.h"
#include "Timer.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

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

void timeAlgorithm(HeapSelect &algorithm, const std::vector<int> &data, int k)
{
    std::vector<int> copy = data;
    Timer timer;
    timer.start();
    int result = algorithm.selectKthSmallest(copy, k);
    timer.stop();
    std::cout << "HeapSelect: n = " << data.size() << ", k = " << k << ", Result: " << result << ", Time: " << timer.elapsedMilliseconds() << " ms\n";
}

void timeAlgorithm(RandomizedSelect &algorithm, const std::vector<int> &data, int k)
{
    std::vector<int> copy = data;
    Timer timer;
    timer.start();
    int result = algorithm.selectKthSmallest(copy, k);
    timer.stop();
    std::cout << "RandomizedSelect: n = " << data.size() << ", k = " << k << ", Result: " << result << ", Time: " << timer.elapsedMilliseconds() << " ms\n";
}

void timeAlgorithm(MedianOfMedians &algorithm, const std::vector<int> &data, int k)
{
    std::vector<int> copy = data;
    Timer timer;
    timer.start();
    int result = algorithm.selectKthSmallest(copy, k);
    timer.stop();
    std::cout << "MedianOfMedians: n = " << data.size() << ", k = " << k << ", Result: " << result << ", Time: " << timer.elapsedMilliseconds() << " ms\n";
}

int main()
{
    std::vector<int> sizes = {100, 1000, 10000, 100000};
    std::vector<int> ks = {1, 10, 100, 500};
    for (int size : sizes)
    {
        std::vector<int> data;
        loadTestData("k-th_data_" + std::to_string(size) + ".txt", data);
        for (int k : ks)
        {
            if (k > size)
                continue;
            HeapSelect heapSelect;
            RandomizedSelect randomizedSelect;
            MedianOfMedians medianOfMedians;
            timeAlgorithm(heapSelect, data, k);
            timeAlgorithm(randomizedSelect, data, k);
            timeAlgorithm(medianOfMedians, data, k);
        }
    }
    return 0;
}
