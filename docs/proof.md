# 快排算法时间复杂度分析

## 平均时间复杂度

假设待排数组长度为$n$，所选取的基准枢轴元素位于第$i$个位置，则统一递推方程为

$$
T(n) = T(i) + T(n-i-1) + \Theta(n)
$$
根据定义，$\Theta(n)$与$n$同阶，故也可以写成

$$
T(n) = T(i) + T(n-i-1) + c \cdot n
$$
其中$c$为常数。

平均来看，$i$可均匀取遍$0$到$n-1$，故上式可变成

$$
T(n) = \frac{2}{n} \sum_{i=0}^{n-1} T(i) + c \cdot n
$$
将$n$移动到右边，可化为

$$
n \cdot T(n) = 2 \sum_{i=0}^{n-1} T(i) + c \cdot n^2
$$
迭代，有

$$
\left( n-1 \right) \cdot T(n-1) = 2 \sum_{i=0}^{n-2} T(i) + c \cdot \left( n-1 \right) ^2
$$
相减，有

$$
n \cdot T(n) - \left( n-1 \right) \cdot T(n-1) = 2 T \left( n-1 \right) + 2 c \cdot n - c
$$
其中常数c可忽略，可变形为

$$
\frac{T(n)}{n+1} = \frac{T(n-1)}{n} + \frac{2c}{n+1}
$$
累加，有

$$
T(n) = \frac{n+1}{2}T(1) + 2c (n+1)^2 \cdot \sum_{i=2}^{n} \frac{1}{i+1}
$$
由于$\sum_{i=2}^{n}\frac{1}{i+1}$与$\log n$同阶，故T(n)与$n\log n$同阶.

## 最坏时间复杂度

在最坏情况下每次选取的基准枢轴元素都等于最大或最小元素，则每次递归只能对一个元素进行有效排序，假设此命题不成立，观察递归树，可发现$T(n)$可表示为

$$
\begin{aligned}
T(n) &= T(n-1) + cn \\
&= T(n-2) + c(n-1) + cn \\
\end{aligned}
$$
也可使用更加均衡的递归树分解，即

$$
T(n) = T(n-2) + T(1) + cn
$$
可发现二者之差为$c(n-1) - T(1)$，由于$c(n-1)$阶数比$T(1)$高，则很明显第一种划分复杂度比第二种大，类似地，可以证明第一种划分才是最坏情况，原命题成立。

当递归树在每一次都使用最坏情况拓展，则递推方程

$$
T(n) = T(n-1) + cn
$$
可推出

$$
\begin{aligned}
T(n) &= T(n-1) + cn \\
&= T(n-2) + c(n-1) + cn \\
&= T(n-3) + c(n-2) + c(n-1) + cn \\
&\cdots \\
&= T(1) + c(n-1) + \cdots + cn \\
&= \sum_{i=1}^{n} c(n-i) + cn \\
&= c \cdot \frac{n(n-1)}{2} + cn \\
&= O(n^2).
\end{aligned}
$$
