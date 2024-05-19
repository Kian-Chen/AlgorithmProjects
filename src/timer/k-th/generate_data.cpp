#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>

std::vector<int> generateRandomVector(int size)
{
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = rand();
    }
    return vec;
}

void generateTestData()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> sizes = {100, 1000, 10000, 100000};
    for (int size : sizes)
    {
        std::vector<int> data = generateRandomVector(size);
        std::ofstream outFile("k-th_data_" + std::to_string(size) + ".txt");
        for (int num : data)
        {
            outFile << num << " ";
        }
        outFile.close();
    }
}

int main()
{
    generateTestData();
    return 0;
}
