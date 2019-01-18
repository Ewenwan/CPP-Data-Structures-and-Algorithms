// Project: Selection_Sort.cbp
// File   : Selection_Sort.cpp 冒泡改进，选择排序，找到最小的与指定位置交换，只交换一次

#include <iostream>

using namespace std;

void SelectionSort(int arr[], int arrSize)
{
    // 最小元素索引
    int minIndex;

    // 总共遍历 n-1次
    for(int i = 0; i < arrSize - 1; ++i)
    {
        // 每次剩余序列中的最小值
        minIndex = i;
        // 在后面无序序列中寻找最小值
        for(int j = i + 1; j < arrSize; ++j)
        {
            // 更新最小元素 索引
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // 将最小元素放入有序序列的末尾
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Selection Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with SelectionSort algorithm
    SelectionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
