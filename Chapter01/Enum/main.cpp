// 9 enum枚举变量 牌花色面值 使用整数索引获取值 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// 牌的花色
// 黑桃（Spades)、红桃（Hearts)、草花（Clubs）、方块（Diamonds） 牌面（face）
enum CardSuits
{
    Club,
    Diamond,
    Heart,
    Spade
};
// 牌的大小
enum CardElements
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

// 根据枚举变量值，获取牌花色字符串========
string GetSuitString(CardSuits suit)
{
    string s;

    switch(suit)
    {
        case Club:
            s = "Club";
            break;
        case Diamond:
            s = "Diamond";
            break;
        case Heart:
            s = "Heart";
            break;
        case Spade:
            s = "Spade";
            break;
    }

    return s;
}

// 根据枚举变量值，获取牌面值字符串========
string GetElementString(CardElements element)
{
    string e;

    switch(element)
    {
        case Ace:
            e = "Ace";
            break;
        case Two:
            e = "Two";
            break;
        case Three:
            e = "Three";
            break;
        case Four:
            e = "Four";
            break;
        case Five:
            e = "Five";
            break;
        case Six:
            e = "Six";
            break;
        case Seven:
            e = "Seven";
            break;
        case Eight:
            e = "Eight";
            break;
        case Nine:
            e = "Nine";
            break;
        case Ten:
            e = "Ten";
            break;
        case Jack:
            e = "Jack";
            break;
        case Queen:
            e = "Queen";
            break;
        case King:
            e = "King";
            break;
    }

    return e;
}

// 产生指定范围内的随机数
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

    // generate random suit and element card
    int iSuit = GenerateRandomNumber(0, 3);    // 四种花色中的一种，下标
    int iElement = GenerateRandomNumber(0, 12);// 13种面值大小中的一种，下标
    
    // 根据下标索引创建 枚举变量=========================
// https://www.cnblogs.com/chio/archive/2007/07/18/822389.html
    // static_cast < type-id > ( expression )
    // 把expression转换为type-id类型，但没有运行时类型检查来保证转换的安全性。
// 来源：为什么需要static_cast强制转换？
// 情况1：void指针 -> 其他类型指针,把void指针转换成目标类型的指针(不安全!!)
// 情况2：改变通常的标准转换,用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。
// 情况3：避免出现可能多种转换的歧义
    CardSuits suit = static_cast<CardSuits>(
        iSuit);
    CardElements element = static_cast<CardElements>(
        iElement);

 // 打印牌 的字符串信息===============
    cout << "Your card is ";
    cout << GetElementString(element);
    cout << " of " << GetSuitString(suit) << endl;

    return 0;
}
