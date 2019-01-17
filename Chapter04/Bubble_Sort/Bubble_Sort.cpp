// Project: Bubble_Sort.cbp
// File   : Bubble_Sort.cpp
// 每次从剩余序列中找出最大值，最大值依次交换到最右端
//  改进1：其中如果未发送交换则序列已经有序，可提前结束
//  改进2：其中每次的变量交换找最大值 只需要遍历到 上次变量中最后一个交换的位置(该部分已经有序)，跳过已经有序的部分
#include <iostream>

using namespace std;

void BubbleSort(int arr[], int arrSize)
{
    // 是否有序标志
    bool isSwapped;
    int SwapIndex;
    // 未排序元素数量
    int unsortedElements = arrSize;
    do
    {
        // 是否发生交换的标志
        isSwapped = false;
        SwapIndex=0;
        // Iterate through the array's element
        for(int i = 0; i < unsortedElements - 1; ++i)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);// 大的放在右边
                isSwapped = true;
                SwapIndex=i+1;// 已经有序的位置
            }
        }

        if(SwapIndex)
            unsortedElements=SwapIndex+1; // 跳过已经有序的部分===================改进=====
        else
            --unsortedElements;
    }
    // 如果未发生交换，则原序列已经 有序了===可提前结束排序过程
    while(isSwapped);
}

int main()
{
    cout << "Bubble Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with BubbleSort algorithm
    BubbleSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
