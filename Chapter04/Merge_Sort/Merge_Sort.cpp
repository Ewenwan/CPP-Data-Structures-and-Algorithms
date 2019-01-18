// Project: Merge_Sort.cbp
// File   : Merge_Sort.cpp 先将序列依次二分，构建左右两个有序序列，最后合并在一起

#include <iostream>

using namespace std;

void Merge(
    int arr[],
    int startIndex,
    int middleIndex,
    int endIndex)
{
    // 需要排序的元素 数量
    int totalElements = endIndex - startIndex + 1;

    // 临时数据 存储 归并后的数组
    int * tempArray = new int[totalElements];

    // 左子数组 arr[startIndex ... middleIndex]
    int leftIndex = startIndex;

    // 右值数组 arr[middleIndex + 1 ... endIndex]
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    // Merge the two subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if(arr[leftIndex] <= arr[rightIndex])
        {
            // Store the left subarray's element
            // if it's lower than the right one
            tempArray[mergedIndex] = arr[leftIndex];

            // Go to next left subarray index
            ++leftIndex;
        }
        else
        {
            // Store the right subarray's element
            // if it's lower than the left one
            tempArray[mergedIndex] = arr[rightIndex];

            // Go to next right subarray index
            ++rightIndex;
        }

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in left subarray
    // that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray[mergedIndex] = arr[leftIndex];

        // Go to next left subarray index
        ++leftIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in right subarray
    // that is not stored to merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray[mergedIndex] = arr[rightIndex];

        // Go to next right subarray index
        ++rightIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // Now, the merged array has been sorted
    // Copy the elements to the original array
    for (int i = 0; i < totalElements; ++i)
    {
        arr[startIndex + i] = tempArray[i];
    }

    // Remove the temporary array tempArray
    delete[] tempArray;

    return;
}

void MergeSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // 分
    if(startIndex < endIndex)
    {
        // 中间 索引
        int middleIndex = (startIndex + endIndex) / 2;

        // 排序左边  arr[startIndex ... middleIndex]
        MergeSort(arr, startIndex, middleIndex);

        // 排序右边 arr[middleIndex + 1 ... endIndex]
        MergeSort(arr, middleIndex + 1, endIndex);

        // 合
        Merge(arr, startIndex, middleIndex, endIndex);
    }

    return;
}

int main()
{
    cout << "Merge Sort" << endl;

    // Initialize a new array
    int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with MergeSort algorithm
    MergeSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
