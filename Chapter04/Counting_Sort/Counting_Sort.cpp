// Project: Counting_Sort.cbp
// File   : Counting_Sort.cpp 计数 Counting 先统计数据 生成 直方图分布 按照直方图生成有序数组

#include <iostream>

using namespace std;

void CountingSort(int arr[], int arrSize)
{
    // 生成 数组数据 的 直方图分布
    
    // 需要假设数据范围，可以先找到 数据的最大值最小值
    int counterSize = 10;
    int * counterArray = new int [counterSize];
    // 直方图统计
    for(int i = 0; i < arrSize; ++i)// 每个数组元素 划分到 对应的 直方图bin中
    {
        ++counterArray[arr[i]]; // 对应元素arr[i] 占据的 直方图bin 计数+1 
    }

    // 按照数据直方图分布生成 有序数组====
    int arrCounter = 0;// 数组index
    for(int i = 0; i < counterSize; ++i)// 所有直方图bin
    {
        while(counterArray[i] > 0)// 该bin 还有计数，原数组中有该bin的值(可能不止一个)
        {
            // 从小到大的直方图 bin 依次放入 有序数组
            arr[arrCounter++] = i;
            // 该bin 计数-1
            --counterArray[i];
        }
    }
}

int main()
{
    cout << "Counting Sort" << endl;

    // Initialize a new array
    int arr[] = {9, 6, 5, 6, 1, 7, 2, 4, 3, 5, 7, 7, 9, 6};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with BubbleSort algorithm
    CountingSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
