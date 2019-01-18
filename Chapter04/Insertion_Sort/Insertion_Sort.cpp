// Project: Insertion_Sort.cbp
// File   : Insertion_Sort.cpp 插入排序，类似打牌时，对拿到的牌一次插入到有序序列中的合适位置

#include <iostream>

using namespace std;

void InsertionSort(int arr[], int arrSize)
{
    // 依次拿出后面无序序列中的元素，插入前面有序序列中的合适位置
    for(int i = 1; i < arrSize; ++i)
    {
        // 当前 需要插入的元素
        int refValue = arr[i];

        int j;
        // 0,...,i-1是已经拿到的牌，已经有序的序列
        for(j = i - 1; j >= 0; --j)
        {
            // 将当前元素 refValue 插入到 前面有序的序列中
            if(arr[j] > refValue)
                arr[j+1] = arr[j]; // 序列中大于带插入元素则依次后移 
            else
                break; // 找到 待插入元素 的 合适位置了
        }

        // 将 待插入元素插入合适位置
        // arr[j] 小于 refValue,则其应该插入 j + 1 位置
        arr[j + 1] = refValue;
    }
}

int main()
{
    cout << "Insertion Sort" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Sort the array with InsertionSort algorithm
    InsertionSort(arr, arrSize);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
