// Project: Ternary_Search.cbp
// File   : Ternary_Search.cpp 三分查找，有序区间三分，依次检查，迭代三个区间中的不同区间

#include <iostream>

using namespace std;

int TernarySearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // 不断搜小搜索空间
    if(startIndex <= endIndex)
    {
        // 三分左边第一个点
        int middleLeftIndex = startIndex + (endIndex - startIndex) / 3;

        // 三分左边第二个点
        int middleRightIndex =
            middleLeftIndex + (endIndex - startIndex) / 3;

        // 检查 第一个点值
        if(arr[middleLeftIndex] == val)
        {
            return middleLeftIndex;
        }
        // 检查第二个点值
        else if(arr[middleRightIndex] == val)
        {
            return middleRightIndex;
        }
        // 迭代三分中的第一个区间 arr[startIndex ... middleLeftIndex - 1]
        else if(arr[middleLeftIndex] > val)
        {
            return TernarySearch(
                arr,
                startIndex,
                middleLeftIndex - 1,
                val);
        }
        // 迭代三分中的第三个区间arr[middleRightIndex + 1 ... endIndex]
        else if(arr[middleRightIndex] < val)
        {
            return TernarySearch(
                arr,
                middleRightIndex + 1,
                endIndex,
                val);
        }
        // 迭代三分中的第二个区间 arr[middleLeftIndex + 1 ... middleRightIndex - 1]
        else
        {
            return TernarySearch(
                arr,
                middleLeftIndex + 1,
                middleRightIndex - 1,
                val);
        }
    }
    // 没找到-1
    return -1;
}

int main()
{
    cout << "Ternary Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Ternary Search
    int i = TernarySearch(arr, 0, arrSize - 1, searchedValue);

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
