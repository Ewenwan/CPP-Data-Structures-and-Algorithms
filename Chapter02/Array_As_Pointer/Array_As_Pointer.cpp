// 2. 数组 指针 访问 

#include <iostream>

using namespace std;

int main()
{
    // Initialize tee array length
    int arrLength = 5;

    // 使用 new 分配数组内存空间 并返回首地址指针
    int * ptr = new int[arrLength] { 21, 47, 87, 35, 92 };
    
    // 二维数组初始化 
    // int multiArray[][] = new int[3][5];
    
    // 使用 *解引用 来获取制造地址处的 值
    cout << "Using pointer increment" << endl;
    cout << "Value\tAddress" << endl;
    while(*ptr) // 不安全，数组后内地址一版存储的值为 0======
    {
        cout << *ptr << "\t"; // 解引用，获取地址处存储的值
        cout << ptr << endl;  // 打印地址
        ptr++;
    }
    cout << endl;

    // 上面的处理指针向后移动了 数组元素数量 个 存储单位
    ptr = ptr - 5;// 恢复 数组首地址的值

    // 按照数组方式 使用[] 下标索引 获取数组元素
    cout << "Using pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for(int i = 0; i < arrLength; ++i)
    {
        cout << ptr[i] << "\t";  // 使用[] 下标索引 获取数组元素
        cout << &ptr[i] << endl; // & 获取 元素 的存储地址===
    }
    
    delete ptr;// 释放 动态申请的内存

    return 0;
}
