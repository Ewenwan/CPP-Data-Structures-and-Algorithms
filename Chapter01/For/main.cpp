// 6 for循环结构
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 产生随机数
int GenerateRandomNumber(int min, int max)
{
    // static used for efficiency,
    // so we only calculate this value once
    // 静态数据，只计算一次，将随机数变成 0~1之间
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    // evenly distribute the random number
    // across our range
    return min + static_cast<int>(
        (max - min + 1) * (rand() * fraction));
}

int main()
{
    // set initial seed value to system clock
    // 随机数种子
    srand(static_cast<unsigned int>(time(0)));

    // loop ten times
    for (int i=0; i < 10; ++i) // 循环10次
    {
        cout << GenerateRandomNumber(0, 100) << " ";
    }
    cout << "\n";

    return 0;
}
