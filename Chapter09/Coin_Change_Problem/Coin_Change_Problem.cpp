// Project: Coin_Change_Problem.cbp
// File   : Coin_Change_Problem.cpp  找零问题，反向遍历可找零币值列表，尽量使用 大币值 找零，剩余找零小于 最小币值 时 结束

#include <iostream>
#include <vector>

using namespace std;

void MinimalChangeCoin(double changingNominal)
{
    // 所有美元币值 数组
    double denom[] =
        {0.01, 0.05, 0.10, 0.25, 1, 2, 5, 10, 20, 50, 100};
    // 数组元素数量
    int totalDenom = sizeof(denom) / sizeof(denom[0]);

    // 初始化一个结果
    vector<double> result;

    // 反向遍历可找零币值列表
    for (int i = totalDenom - 1; i >= 0; --i)
    {
        // 尽量使用 大币值 找零
        while (changingNominal >= denom[i])
        {
           changingNominal -= denom[i];// 使用 denom[i]币
           result.push_back(denom[i]); // 记录使用
        }
        // 剩余找零小于 最小币值 则 结束
        if (changingNominal < denom[0])
            break;
    }

    // 打印找零钱币列表
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Coin Change Problem" << endl;

    // 总找零钱数
    float change = 17.61;

    // Getting the minimal
    cout << "Minimal number of change for ";
    cout << change << " is " << endl;
    MinimalChangeCoin(change);

    return 0;
}
