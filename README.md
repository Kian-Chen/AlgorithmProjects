# 期中大作业项目

## 项目介绍

本项目由2022级数据科学与大数据技术学生**陈麒安**（2250951）完成，分为三个主要部分：

1. 分析快速排序的平均时间复杂度，并且给出其在最坏情况下的时间复杂度分析证明。
2. `k-th` 任务：在数组中查找第 k 小的元素，在下文中某些地方可能会将其简称为 `k-th`任务。
3. `separate` 任务：将一个数组分成两部分，使得这两部分的和尽可能接近，在下文中某些地方可能会将其简称为 `separate`任务。

## 项目结构

项目组织如下：

```shell
Midterm/
├── src/
│   ├── include/
│   │   ├── k-th.h
│   │   ├── separate.h
│   │   └── Timer.h
│   │
│   ├── algorithms/
│   │   ├── k-th/
│   │   │   ├── HeapSelect.cpp
│   │   │   ├── RandomizedSelect.cpp
│   │   │   ├── MedianOfMedians.cpp
│   │   │   └── CMakeLists.txt
│   │   │
│   │   └── separate/
│   │       ├── DPSolution.cpp
│   │       ├── BruteForceSolution.cpp
│   │       └── CMakeLists.txt
│   │
│   ├── timer/
│   │   ├── Timer.cpp
│   │   ├── CMakeLists.txt
│   │   ├── k-th/
│   │   │   ├── generate_data.cpp
│   │   │   ├── time_algorithms.cpp
│   │   │   └── CMakeLists.txt
│   │   │
│   │   └── separate/
│   │       ├── generate_data.cpp
│   │       ├── time_algorithms.cpp
│   │       └── CMakeLists.txt
│   │
│   └── manual/
│       ├── k-th_heap.cpp
│       ├── k-th_random.cpp
│       ├── k-th_median.cpp
│       ├── separate_dp.cpp
│       ├── separate_bruteforce.cpp
│       └── CMakeLists.txt
│
├── docs/
│   ├── proof.md
│   ├── k-th.md
│   └── separate.md
│
├── README.md
└── CMakeLists.txt
```


## 目录说明

- `README.md`: 本文件，包含本项目的说明。
- `docs/proof.md`: 包含快速排序在最坏情况下的时间复杂度分析证明，为本次作业第一题报告文件
- `docs/k-th.md`: 包含 `k-th` 任务的具体分析与说明，为本次作业第二题报告文件
- `docs/separate.md`: 包含 `separate` 任务的具体分析与说明，为本次作业第三题报告文件
- `src/include/`：包含不同任务和计时器的头文件。
- `src/algorithms/k-th/`：包含用于查找第 k 小元素的不同算法。
- `src/algorithms/separate/`：包含用于将数组分成两部分使它们的和尽可能接近的算法。
- `src/timer/`：包含计时器实现以及生成测试数据和自动计时算法的程序。
- `src/manual/`：包含通过手动输入数据的程序。

## 构建项目

### 前置条件

- CMake（版本 3.10 或更高）
- 支持 C++17 的 C++ 编译器

### 构建步骤

1. 如果当前目录下没有 `build` 文件夹，创建构建目录并进入：

```bash
mkdir build
cd build
```

2. 运行 CMake 配置项目：

```bash
cmake ..
```

3. 编译项目：

```bash
cmake --build .
```

### 运行程序

本项目设有多个target可供launch，分别为：

- `k-th_generate_data`：生成`k-th`任务的测试数据
- `k-th_time_algorithms`：自动测试`k-th`任务使用不同算法的运行时间
- `manual_k-th_heap`：手动输入`k-th`任务的测试数据并使用堆排序算法进行计算选择
- `manual_k-th_median`：手动输入`k-th`任务的测试数据并使用中位数选择算法进行计算选择
- `manual_k-th_random`：手动输入`k-th`任务的测试数据并使用随机选择算法进行计算选择
- `separate_generate_data`：生成`separate`任务的测试数据
- `separate_time_algorithms`：自动测试`separate`任务使用不同算法的运行时间
- `manual_separate_dp`：手动输入`separate`任务的测试数据并使用动态规划算法进行计算分割
- `manual_separate_bruteforce`：手动输入`separate`任务的测试数据并使用暴力搜索算法进行计算分割

由于本项目在VSCode中进行开发，全程使用VSCode中的CMake插件进行调试和运行，对于每个target的launch在`bash`环境下的命令不太熟悉，故没有列出相关命令，建议使用VSCode的CMake插件直接对每个不同target进行launch。