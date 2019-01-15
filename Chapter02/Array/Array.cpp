// 1. 数组 array 内存地址连续 

#include <iostream>

using namespace std;

int main()
{
    // Initialize an array
    int arr[] = { 21, 47, 87, 35, 92 };

    // Access each element
    cout << "Array elements: ";
    // 数组元素数量
    int array_num = sizeof(arr)/sizeof(*arr); // 数组总元素字节数量sizeof(arr)， *arr数组首元素字节数量
    for(int i = 0; i < array_num; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // 使用下标 直接修改 数组元素
    arr[2] = 30;
    arr[3] = 64;

    // 再次 打印 数组元素
    cout << "Array elements: ";
    for(int i = 0; i < array_num; ++i)
        cout << arr[i] << " ";
    
    cout << endl;
}
