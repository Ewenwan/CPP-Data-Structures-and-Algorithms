#include <iostream>
#include <vector>  
// 斐波那契数列  递归实现  动态规划实现

using namespace std;

// 斐波那契数列  递归实现
long long fib(int n)
{
    if (n <= 1)
        return 1; // 递归结束条件
    
    else
        // fn = fn-1 + fn-2 前两项之和
        return fib(n - 1) + fib(n - 2);
}

// 斐波那契数列 动态规划实现 更新记录前两项，当前项 = 前一项 + 前前一项
long long fib2(int n)
{
    if(n <= 1)
        return 1;

    long long last = 1;      // 前一项
    long long nextToLast = 1;// 前前一项
    long long answer = 1;    // 当前项

    for(int i = 2; i <=n; ++i)
    {
        answer = last + nextToLast;// 当前项 = 前一项 + 前前一项
        
        // 更新 记录前两项
        nextToLast = last;// 前前一项
        last = answer;// 前一项
    }

    return answer;
}

int main()
{
    cout << "Fibonacci" << endl;

    cout << fib2(10) << endl;
    return 0;
}
