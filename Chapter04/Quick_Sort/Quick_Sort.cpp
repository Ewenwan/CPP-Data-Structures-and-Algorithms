// Project: Quick_Sort.cbp
// File   : Quick_Sort.cpp 按照参考元素，将大的元素放在一边，小的放在另一边，找到分区中枢 索引

#include <iostream>

using namespace std;

// 按照参考元素，将大的元素放在一边，小的放在另一边，找到分区中枢 索引
int Partition(
    int arr[],
    int startIndex,
    int endIndex)
{
    // 子区间第一个元素 作为 参考元素
    int pivot = arr[startIndex];

    // 
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {   
        // 单个指针 遍历，可以使用双指针版
        if (arr[i] < pivot)
        {
            ++middleIndex;// 左边小元素序列 尾id
            // 小元素放在左边
            swap(arr[i], arr[middleIndex]);
        }
    }

    // 参考元素放在 中枢的位置
    swap(arr[startIndex], arr[middleIndex]);

    // 中枢 索引
    return middleIndex;
}

void QuickSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // 
    if (startIndex < endIndex)
    {
        // 将数组分开，小的放左边，大的放右边，返回中枢索引
        int pivotIndex = Partition(arr, startIndex, endIndex);

        // 快排左边 arr[startIndex ... pivotIndex - 1]
        QuickSort(arr, startIndex, pivotIndex - 1);

        // 快排右边  arr[pivotIndex + 1 ... endIndex]
        QuickSort(arr, pivotIndex + 1, endIndex);
    }
}

int main()
{
    cout << "Quick Sort" << endl;

    // Initialize a new array
    int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with QuickSort algorithm
    QuickSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
