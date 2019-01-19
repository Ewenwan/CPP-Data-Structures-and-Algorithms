// Project: Decimal_To_BinaryString.cbp
// File   : Decimal_To_BinaryString.cpp  十进制数 转 二进制字符串

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string DecimalToBinaryString(
    int decimalNumber)
{
    // 初始化二进制字符串结果
    string binaryString = "0";

    // 
    if(decimalNumber > 0)
    {
        // Reset result
        binaryString = "";

        // Declare a variable for division process
        div_t dv{};

        // Initialize the division quot
        dv.quot = decimalNumber;

        // 初二取余
        do
        {
            dv = div(dv.quot, 2);
            binaryString = to_string(dv.rem) + binaryString;
        }
        while(dv.quot);
    }

    // return the binary string
    return binaryString;
}

int main()
{
    cout << "Decimal To Binary String" << endl;

    // Input a decimal number
    int decNum;
    cout << "Input a decimal number -> ";
    cin >> decNum;

    // Convert to binary string
    string binaryString = DecimalToBinaryString(decNum);

    // Show the result to user
    cout << "Binary string of " << decNum;
    cout << " is '" << binaryString;
    cout << "'" << endl;

    return 0;
}
