// Project: Linear_Search.cbp
// File   : Linear_Search.cpp  线性搜索
#include <iostream>

using namespace std;

int LinearSearch(
    int arr[],
    int startIndex,
    int endIndex,
    int val)
{
    // 按索引一次对比
    for(int i = startIndex; i < endIndex; ++i)
    {
        if(arr[i] == val) // 找到
        {
            return i;// 返回对应的 位置索引
        }
    }
    return -1; // 未找到 返回-1
}

int main()
{
    cout << "Linear Search" << endl;

    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30, 25, 18};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Define value to be searched
    int searchedValue = 30;

    // Find the searched value using Linear Search
    int i = LinearSearch(arr, 0, arrSize - 1, searchedValue);

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
