// Project: Interpolation_Search.cbp
// File   : Interpolation_Search.cpp 插补查找 有序序列的 加权取中点 二分查找

#include <iostream>

using namespace std;

int InterpolationSearch(
    int arr[],
    int lowIndex,
    int highIndex,
    int val)
{
    if(lowIndex <= highIndex)
    {
        // 加权取中点 例如 30个元素，最小值5，最大值100，需要查找40
        // 则按比例 40出现的位置为 (40-5)*30/(100-5)
        int middleIndex =
            lowIndex + (
                (val - arr[lowIndex]) * (highIndex - lowIndex) /
                (arr[highIndex] - arr[lowIndex]));

        // 比较是否为 寻找的元素
        if(arr[middleIndex] == val)
        {
            return middleIndex;
        }
        // 递归左边 arr[lowIndex ... middleIndex - 1]
        else if(arr[middleIndex] > val)
        {
            return InterpolationSearch(arr, lowIndex, middleIndex - 1, val);
        }
        // 递归右边 arr[middleIndex + 1 ... highIndex]
        else
        {
            return InterpolationSearch(arr, middleIndex + 1, highIndex, val);
        }
    }

    // 未找到 -1
    return -1;
}

int main()
{
    cout << "Interpolation Search" << endl;

    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 16;

    // Find the searched value using Interpolation Search
    int i = InterpolationSearch(arr, 0, arrSize - 1, searchedValue);

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
