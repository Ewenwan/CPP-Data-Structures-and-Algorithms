// Project: Jump_Search.cbp
// File   : Jump_Search.cpp  先按间隔点找到目标值出现的子序列，在确定的子序列中线性查找

#include <iostream>
#include <cmath>

using namespace std;

int LinearSearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // Iterate through the start index
    // to the end index and
    // return the searched value's index
    for(int i = startIndex; i < endIndex; ++i)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }

    // return -1 if no val is found
    return -1;
}

int JumpSearch(
    int arr[],
    int arrSize,
    int val)
{
    // It's impossible to search value
    // in array contains zero or less element
    if (arrSize <= 0)
    {
        return -1;
    }

    // 二分跳跃步骤数量
    int step = sqrt(arrSize);

    // Start comparing from index 0
    int blockIndex = 0;

    // 也是有序序列 ， 先按间隔点找到目标值出现的子序列
    while (blockIndex < arrSize && arr[blockIndex] < val)
    {
        blockIndex += step;
    }

    //  在确定的子序列中线性查找 arr[blockIndex - step .... blockIndex or arrSize]
    return LinearSearch(
        arr,
        blockIndex - step,
        min(blockIndex, arrSize),
        val);
}

int main()
{
    cout << "Jump Search" << endl;

    // Initialize a new array
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 39;

    // Find the searched value using Jump Search
    int i = JumpSearch(arr, arrSize, searchedValue);

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
