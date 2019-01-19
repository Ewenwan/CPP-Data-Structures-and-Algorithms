// Project: Anagram.cbp
// File   : Anagram.cpp
// 变位词 anagram  重构词
// triangle（三角形）就有integral（构成整体所必要的）这个变位词
// Silent（不要吵）和Listen（听我说）也是
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsAnagram(
    string str1,
    string str2)
{
    // 转变成 大写
    transform(
        str1.begin(),
        str1.end(),
        str1.begin(),
        ::toupper);
    transform(
        str2.begin(),
        str2.end(),
        str2.begin(),
        ::toupper);

    // 删除 空格
    str1.erase(
        remove(
            str1.begin(),
            str1.end(),
            ' '),
            str1.end());
    str2.erase(
        remove(
            str2.begin(),
            str2.end(),
            ' '),
            str2.end());

    // A-Z 排序
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // 排序后如果相同，则为 变位词
    return str1 == str2;
}

int main()
{
    cout << "Anagram" << endl;

    // Input string1
    string string1;
    cout << "Input string 1 -> ";
    getline(cin, string1);

    // Input string2
    string string2;
    cout << "Input string 2 -> ";
    getline(cin, string2);

    // Check if they are anagram
    cout << "'" << string1 << "' and '";
    cout << string2 << "' are ";
    if(IsAnagram(string1, string2))
    {
        cout << "anagram";
    }
    else
    {
        cout << "NOT anagram";
    }
    cout << endl;

    return 0;
}
