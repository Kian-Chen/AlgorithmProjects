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
        vec[i] = rand() % 100;
    }
    return vec;
}

void generateTestData()
{
    std::srand(std::time(0));
    std::vector<int> sizes = {10, 20, 30, 40};
    for (int size : sizes)
    {
        std::vector<int> data = generateRandomVector(size);
        std::ofstream outFile("separate_data_" + std::to_string(size) + ".txt");
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
