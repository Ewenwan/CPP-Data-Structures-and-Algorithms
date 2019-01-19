// Project: Palindrome.cbp
// File   : Palindrome.cpp 回文 palindrome 顺读和倒读都一样的词语

#include <iostream>
#include <algorithm>

using namespace std;

bool IsPalindrome(
    string str)
{
    // 变大写
    transform(
        str.begin(),
        str.end(),
        str.begin(),
        ::toupper);

    // 去除空格
    str.erase(
        remove(
            str.begin(),
            str.end(),
            ' '),
            str.end());

    // 首尾指针
    int left = 0;
    int right = str.length() - 1;

    // 首尾指针 向中间遍历 依次比较 对应位置 的 字符 
    while(right > left)
    {
        if(str[left++] != str[right--])
        {
            return false;// 对应位置由不同的，则不是回文
        }
    }

    // 对应位置 字符全部相同，则为回文
    return true;
}

int main()
{
    cout << "Palindrome" << endl;

    // Input string
    string str;
    cout << "Input string -> ";
    getline(cin, str);

    // Check if it is palindrome
    cout << "'" << str << "' is ";
    if(IsPalindrome(str))
    {
        cout << "a palindrome";
    }
    else
    {
        cout << "NOT a palindrome";
    }
    cout << endl;

    return 0;
}
