// 8 do-while 循环==让计算机猜数字
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 产生随机数=====
int GenerateRandomNumber(int min, int max)
{
    // static used for efficiency,
    // so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    // evenly distribute the random number
    // across our range
    return min + static_cast<int>(
        (max - min + 1) * (rand() * fraction));
}

int main()
{
    // set initial seed value to system clock
    srand(static_cast<unsigned int>(time(0)));

    char userChar;

    int iMin = 1;
    int iMax = 100;
    int iGuess;

    // Menu display
    cout << "Choose a number between 1 to 100, ";
    cout << "and I'll guess your number." << endl;
    cout << "Press L and ENTER if my guessed number is lower than yours";
    cout << endl;
    cout << "Press G and ENTER if my guessed number is greater than yours";
    cout << endl;
    cout << "Press Y and ENTER if I've successfully guessed your number!";
    cout << endl << endl;

    // Run the DO-WHILE loop
    do
    {
        iGuess = GenerateRandomNumber(iMin, iMax);// 根据不断缩小的范围，产生随机数
        cout << "I guess your number is " << iGuess << endl;
        cout << "What do you think? ";
        cin >> userChar; // l/L代表计算机产生的数小了
        if(userChar == 'L' || userChar == 'l')
            iMin = iGuess + 1;// 更新 搜索下限为上次猜的数+1
        else if(userChar == 'G' || userChar == 'g')// g/G代表计算机猜的数大了
            iMax = iGuess - 1;// 更新搜索上限

    }
    while(userChar != 'Y' && userChar != 'y'); // 计算机没猜对，会一直猜

    cout << "Yeeaayy.. I've got your number." << endl;
    return 0;
}
