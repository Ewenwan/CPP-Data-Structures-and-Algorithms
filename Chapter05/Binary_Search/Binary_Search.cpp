// Project: Binary_Search.cbp
// File   : Binary_Search.cpp 对于有序序列，使用二分搜索，不断缩小搜索空间

#include <iostream>

using namespace std;

int BinarySearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // 对于有序序列，不断缩小搜索空间
    if(startIndex <= endIndex)
    {
        // 子序列 中间位置
        int middleIndex = startIndex + (endIndex - startIndex) / 2;

        // 相等的情况，更少见，适当放在最后一个 判断分支
        if(arr[middleIndex] == val)
        {
            return middleIndex;
        }
        // 中间值大于要找的值，原序列为升序排列，则在左边找 arr[startIndex ... middleIndex - 1]
        else if(arr[middleIndex] > val)
        {
            return BinarySearch(arr, startIndex, middleIndex - 1, val);
        }
        //  在右边找 arr[middleIndex + 1 ... endIndex]
        else
        {
            return BinarySearch(arr, middleIndex + 1, endIndex, val);
        }
    }

    // 没找到-1
    return -1;
}

int main()
{
    cout << "Binary Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Binary Search
    int i = BinarySearch(arr, 0, arrSize - 1, searchedValue);

    // Notify user the result
    // if the return is not -1,
    // the searched value is found
    if(i != -1)
    {
        cout << searchedValue << " is found in index ";
        cout << i << endl;
    }
    else
    {
        cout << "Could not find value " << searchedValue;
        cout << endl;
    }

    return 0;
}
